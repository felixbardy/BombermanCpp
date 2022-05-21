#include <map>

#include <SDL.h>

#include "core/Player.h"
#include "BombermanGraphics.h"

namespace BombermanGraphics {

    const int DEATH_STEP_DURATION = 5;
    const int WALK_CYCLE_LENGTH = 13;

    enum PlayerTexture {
        DOWN,      
        WALK_DOWN_1,
        WALK_DOWN_2,
        UP,        
        WALK_UP_1, 
        WALK_UP_2, 
        SIDE,      
        WALK_SIDE_1,
        WALK_SIDE_2
    };

    typedef std::map<SDL_Scancode,BC::ActionMask> KeyMap;
    typedef std::map<PlayerTexture,TextureID> PlayerTextureMap;
    typedef std::initializer_list<std::pair<const SDL_Scancode,BC::ActionMask>> KeyMapInitList;
    typedef std::initializer_list<std::pair<const PlayerTexture,TextureID>> PlayerTextureMapInitList;

    const KeyMapInitList players_default_map[] = {
        { //PLAYER ONE
            {SDL_SCANCODE_W, BC::ActionMasks::GO_UP},
            {SDL_SCANCODE_A, BC::ActionMasks::GO_LEFT},
            {SDL_SCANCODE_S, BC::ActionMasks::GO_DOWN},
            {SDL_SCANCODE_D, BC::ActionMasks::GO_RIGHT},
            {SDL_SCANCODE_SPACE, BC::ActionMasks::ACTION},
            {SDL_SCANCODE_LSHIFT, BC::ActionMasks::PAUSE}
        },
        { //PLAYER TWO
            {SDL_SCANCODE_UP,       BC::ActionMasks::GO_UP},
            {SDL_SCANCODE_LEFT,     BC::ActionMasks::GO_LEFT},
            {SDL_SCANCODE_DOWN,     BC::ActionMasks::GO_DOWN},
            {SDL_SCANCODE_RIGHT,    BC::ActionMasks::GO_RIGHT},
            {SDL_SCANCODE_KP_0,     BC::ActionMasks::ACTION}
        }
        // TODO Players 3 and 4 keybindings
    };

    const PlayerTextureMapInitList players_texture_map[] = {
        {   // PLAYER ONE
            {DOWN,          PLAYER1_DOWN},
            {WALK_DOWN_1,   PLAYER1_WALK_DOWN_1},
            {WALK_DOWN_2,   PLAYER1_WALK_DOWN_2},
            {UP,            PLAYER1_UP},
            {WALK_UP_1,     PLAYER1_WALK_UP_1}, 
            {WALK_UP_2,     PLAYER1_WALK_UP_2}, 
            {SIDE,          PLAYER1_SIDE},      
            {WALK_SIDE_1,   PLAYER1_WALK_SIDE_1},
            {WALK_SIDE_2,   PLAYER1_WALK_SIDE_2}
        },
        {   // PLAYER TWO
            {DOWN,          PLAYER2_DOWN},
            {WALK_DOWN_1,   PLAYER2_WALK_DOWN_1},
            {WALK_DOWN_2,   PLAYER2_WALK_DOWN_2},
            {UP,            PLAYER2_UP},
            {WALK_UP_1,     PLAYER2_WALK_UP_1}, 
            {WALK_UP_2,     PLAYER2_WALK_UP_2}, 
            {SIDE,          PLAYER2_SIDE},      
            {WALK_SIDE_1,   PLAYER2_WALK_SIDE_1},
            {WALK_SIDE_2,   PLAYER2_WALK_SIDE_2}
        },
        {   // PLAYER THREE
            {DOWN,          PLAYER3_DOWN},
            {WALK_DOWN_1,   PLAYER3_WALK_DOWN_1},
            {WALK_DOWN_2,   PLAYER3_WALK_DOWN_2},
            {UP,            PLAYER3_UP},
            {WALK_UP_1,     PLAYER3_WALK_UP_1}, 
            {WALK_UP_2,     PLAYER3_WALK_UP_2}, 
            {SIDE,          PLAYER3_SIDE},      
            {WALK_SIDE_1,   PLAYER3_WALK_SIDE_1},
            {WALK_SIDE_2,   PLAYER3_WALK_SIDE_2}
        },
        {   // PLAYER FOUR
            {DOWN,          PLAYER4_DOWN},
            {WALK_DOWN_1,   PLAYER4_WALK_DOWN_1},
            {WALK_DOWN_2,   PLAYER4_WALK_DOWN_2},
            {UP,            PLAYER4_UP},
            {WALK_UP_1,     PLAYER4_WALK_UP_1}, 
            {WALK_UP_2,     PLAYER4_WALK_UP_2}, 
            {SIDE,          PLAYER4_SIDE},      
            {WALK_SIDE_1,   PLAYER4_WALK_SIDE_1},
            {WALK_SIDE_2,   PLAYER4_WALK_SIDE_2}
        },
    };

    /**
     * @brief A player with added functionality for rendering
     * 
     */
    class DrawablePlayer : public BC::Player
    {
    private:
        /// The keymapping for this player
        KeyMap m_keymap;
        /// A mapping to the correct TextureID s for the Player
        PlayerTextureMap m_texture_map;
        /// Keeps track of the death animation when necessary
        int m_death_timer;
    public:
        /**
         * @brief Constructs a new DrawablePlayer object at coordinates (x,y)
         * 
         * @param x x coordinate
         * @param y y coordinate
         */
        DrawablePlayer(int x, int y);

        DrawablePlayer();

        /**
         * @brief Destroys the Drawable Player object
         * 
         */
        ~DrawablePlayer();

        /**
         * @brief Returns the appropriate TextureID for rendering
         * 
         * @param framecount the current framecount
         * @return TextureID 
         */
        TextureID getTexture(int framecount);

        /**
         * @brief Sets the PlayerTextureMap
         * 
         * @param dict the correct associations
         */
        void setTextureMap(PlayerTextureMapInitList dict);
        /**
         * @brief Set the KeyMap for the Player's controls
         * 
         * @param map key-action associations
         */
        void setKeyMap(KeyMapInitList map);

        /**
         * @brief Handles the input of the given keycode
         * 
         * @param keycode the keycode to handle
         */
        void handleInput(const Uint8* kb_state);

    };

}