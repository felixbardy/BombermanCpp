#include "../../include/core/Player.h"

namespace BombermanCore {

    Player::Player(float x, float y)
    : m_x(x), m_y(y), m_dir(DOWN),
      m_action(ActionMasks::CLEAR),
      m_max_bombs(1),
      m_power(1),
      m_bonuses(0)
    {}

    Player::~Player()
    {}

    void Player::getPos(float *x, float *y) const {
        *x = m_x;
        *y = m_y;
    }

    void Player::setPos(float x, float y) {
        m_x = x;
        m_y = y;
    }

    void Player::move(Direction dir) {
        if (dir == UP) m_y -= PLAYER_MOVE_SPEED;
        if (dir == DOWN) m_y += PLAYER_MOVE_SPEED;
        if (dir == RIGHT)  m_x += PLAYER_MOVE_SPEED;
        if (dir == LEFT)  m_x -= PLAYER_MOVE_SPEED;

        m_dir = dir;
    }

    Direction Player::getDir() const {
        return m_dir;
    }

    void Player::setDir(Direction dir) {
        m_dir = dir;
    }

    void Player::kill() {
        m_is_dead = true;
    }

    bool Player::isDead() const {
        return m_is_dead;
    }

    ActionMask Player::getActions() const {
        return m_action;
    }

    void Player::setAction(ActionMask action) {
        m_action = action;
    }

    void Player::addAction(ActionMask action) {
        m_action |= action;
    }

    void Player::simplifyActions() {
        using namespace ActionMasks;
        if (m_action & GO_LEFT && m_action & GO_RIGHT)
            clearAction(GO_LEFT | GO_RIGHT);
        if (m_action & GO_UP   && m_action & GO_DOWN )
            clearAction(GO_UP | GO_DOWN);
    }

    void Player::clearAction(ActionMask action) {
        m_action &= ~action;
    }

    void Player::clearActions() {
        m_action = 0;
    }

    int Player::getMaxBombs() const {
        return m_max_bombs;
    }

    void Player::addMaxBombs(int mod) {
        m_max_bombs += mod;
    }


    int Player::getPower() const {
        return m_power;
    }

    void Player::addPower(int mod) {
        m_power += mod;
    }

    BonusMask Player::getBonuses() const {
        return m_bonuses;
    }

    void Player::setBonuses(BonusMask bonus) {
        m_bonuses = bonus;
    }

    void Player::addBonus(BonusMask bonus) {
        m_bonuses |= bonus;
    }

}