#include "core/Tile.h"

namespace BombermanCore
{
    Tile::Tile()
    {
        this->m_mask = TileType::EMPTY | TileContent::NOTHING;
    }

    Tile::Tile(tile_mask mask)
    {
    }

    Tile::~Tile()
    {
    }


    bool Tile::addBomb(bomb_data bomb) {
        if (m_mask & TileContent::BOMB) return false;

        m_mask &= TileContent::CLEAR;
        m_mask |= TileContent::BOMB;
        m_bomb = bomb;
        return true;
    }

    bomb_data* Tile::getBomb() {
        return &m_bomb;
    }

    const bomb_data* Tile::getBomb() const {
        return getBomb();
    }

    void Tile::addExplosion(explosion_data explosion) {
        m_mask &= TileContent::CLEAR;
        m_mask |= TileContent::EXPLOSION;
        m_explosion = explosion;
    }

    explosion_data* Tile::getExplosion() {
        return &m_explosion;
    }

    const explosion_data* Tile::getExplosion() const {
        return &m_explosion;
    }

    tile_mask Tile::getMask() const {
        return m_mask;
    }

    tile_mask Tile::getType() const {
        return m_mask & TileContent::CLEAR;
    }

    tile_mask Tile::getContent() const {
        return m_mask & TileType::CLEAR;
    }

    void Tile::setType(tile_mask type) {
        m_mask &= TileType::CLEAR;
        m_mask |= type;
    }

    void Tile::setContent(tile_mask content) {
        m_mask &= TileContent::CLEAR;
        m_mask |= content;
    }

    void Tile::setMask(tile_mask mask) {
        m_mask = mask;
    }

} // namespace BombermanCore