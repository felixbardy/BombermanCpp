#include "DrawablePlayer.h"

namespace BC = BombermanCore;

namespace BombermanGraphics {
    DrawablePlayer::DrawablePlayer(int x, int y)
    : Player(x,y),
      m_keymap(), m_texture_map(),
      m_death_timer(-1)
    {}

    DrawablePlayer::DrawablePlayer()
    : Player(0,0)
    {}

    DrawablePlayer::~DrawablePlayer()
    {}

    TextureID DrawablePlayer::getTexture(int framecount) {
        using namespace BC::ActionMasks;
        if ( getActions() & GO_UP ) {
            switch ((framecount/WALK_CYCLE_LENGTH)%4) {
                case 0:
                    return m_texture_map[PlayerTexture::WALK_UP_1];
                case 1:
                case 3:
                    return m_texture_map[PlayerTexture::UP];
                case 2:
                    return m_texture_map[PlayerTexture::WALK_UP_2];
            }
        }
        else if ( getActions() & GO_DOWN ) {
            switch ((framecount/WALK_CYCLE_LENGTH)%4) {
                case 0:
                    return m_texture_map[PlayerTexture::WALK_DOWN_1];
                case 1:
                case 3:
                    return m_texture_map[PlayerTexture::DOWN];
                case 2:
                    return m_texture_map[PlayerTexture::WALK_DOWN_2];
            }
        }
        else if ( getActions() & (GO_LEFT | GO_RIGHT)) {
            switch ((framecount/WALK_CYCLE_LENGTH)%4) {
                case 0:
                    return m_texture_map[PlayerTexture::WALK_SIDE_1];
                case 1:
                case 3:
                    return m_texture_map[PlayerTexture::SIDE];
                case 2:
                    return m_texture_map[PlayerTexture::WALK_SIDE_2];
            }
        }
        else {
            if (getDir() == BC::UP) return m_texture_map[PlayerTexture::UP];
            if (getDir() == BC::DOWN) return m_texture_map[PlayerTexture::DOWN];
            return m_texture_map[PlayerTexture::SIDE];
        }
    }

    void DrawablePlayer::setTextureMap(PlayerTextureMapInitList dict) {
        m_texture_map.clear();
        m_texture_map.insert(dict);
    }

    void DrawablePlayer::setKeyMap(KeyMapInitList map) {
        m_keymap.clear();
        m_keymap.insert(map);
    }

    void DrawablePlayer::handleInput(const Uint8* kb_state) {
        for (const auto& [keycode, action] : m_keymap) {
            if (kb_state[keycode]) {
                addAction(action);
            }
        }
    }
}