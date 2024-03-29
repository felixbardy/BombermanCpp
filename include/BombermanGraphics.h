#pragma once

#include <map>
#include <list>

#include <SDL2/SDL.h>
namespace BombermanGraphics {

    const int BOMB_LOOP_SPEED = 8;

    enum TextureID {
        // Missing texture
        MISSING_TEXTURE,

        // Tiles
        EMPTY,
        BLOCK,
        WALL,

        // Animated
        BOMB_1,
        BOMB_2,
        BOMB_3,
        CRUMBLING_BLOCK_1,
        CRUMBLING_BLOCK_2,
        CRUMBLING_BLOCK_3,
        CRUMBLING_BLOCK_4,
        CRUMBLING_BLOCK_5,
        CRUMBLING_BLOCK_6,
        CRUMBLING_BLOCK_7,

        // Explosions
        EXP_CENTER_1,
        EXP_CENTER_2,
        EXP_CENTER_3,
        EXP_CENTER_4,
        EXP_HORIZONTAL_1,
        EXP_HORIZONTAL_2,
        EXP_HORIZONTAL_3,
        EXP_HORIZONTAL_4,
        EXP_VERTICAL_1,
        EXP_VERTICAL_2,
        EXP_VERTICAL_3,
        EXP_VERTICAL_4,
        EXP_UP_1,
        EXP_UP_2,
        EXP_UP_3,
        EXP_UP_4,
        EXP_DOWN_1,
        EXP_DOWN_2,
        EXP_DOWN_3,
        EXP_DOWN_4,
        EXP_LEFT_1,
        EXP_LEFT_2,
        EXP_LEFT_3,
        EXP_LEFT_4,
        EXP_RIGHT_1,
        EXP_RIGHT_2,
        EXP_RIGHT_3,
        EXP_RIGHT_4,

        // Player1
        PLAYER1_DOWN,
        PLAYER1_SIDE,
        PLAYER1_UP,
        PLAYER1_WALK_UP_1,
        PLAYER1_WALK_UP_2,
        PLAYER1_WALK_SIDE_1,
        PLAYER1_WALK_SIDE_2,
        PLAYER1_WALK_DOWN_1,
        PLAYER1_WALK_DOWN_2,
        PLAYER1_DEATH_1,
        PLAYER1_DEATH_2,
        PLAYER1_DEATH_3,
        PLAYER1_DEATH_4,
        PLAYER1_DEATH_5,
        PLAYER1_DEATH_6,
        PLAYER1_DEATH_7,
        PLAYER1_DEATH_8,

        // Player2
        PLAYER2_DOWN,
        PLAYER2_SIDE,
        PLAYER2_UP,
        PLAYER2_WALK_UP_1,
        PLAYER2_WALK_UP_2,
        PLAYER2_WALK_SIDE_1,
        PLAYER2_WALK_SIDE_2,
        PLAYER2_WALK_DOWN_1,
        PLAYER2_WALK_DOWN_2,
        PLAYER2_DEATH_1,
        PLAYER2_DEATH_2,
        PLAYER2_DEATH_3,
        PLAYER2_DEATH_4,
        PLAYER2_DEATH_5,
        PLAYER2_DEATH_6,
        PLAYER2_DEATH_7,
        PLAYER2_DEATH_8,

        // Player3
        PLAYER3_DOWN,
        PLAYER3_SIDE,
        PLAYER3_UP,
        PLAYER3_WALK_UP_1,
        PLAYER3_WALK_UP_2,
        PLAYER3_WALK_SIDE_1,
        PLAYER3_WALK_SIDE_2,
        PLAYER3_WALK_DOWN_1,
        PLAYER3_WALK_DOWN_2,
        PLAYER3_DEATH_1,
        PLAYER3_DEATH_2,
        PLAYER3_DEATH_3,
        PLAYER3_DEATH_4,
        PLAYER3_DEATH_5,
        PLAYER3_DEATH_6,
        PLAYER3_DEATH_7,
        PLAYER3_DEATH_8,

        // Player4
        PLAYER4_DOWN,
        PLAYER4_SIDE,
        PLAYER4_UP,
        PLAYER4_WALK_UP_1,
        PLAYER4_WALK_UP_2,
        PLAYER4_WALK_SIDE_1,
        PLAYER4_WALK_SIDE_2,
        PLAYER4_WALK_DOWN_1,
        PLAYER4_WALK_DOWN_2,
        PLAYER4_DEATH_1,
        PLAYER4_DEATH_2,
        PLAYER4_DEATH_3,
        PLAYER4_DEATH_4,
        PLAYER4_DEATH_5,
        PLAYER4_DEATH_6,
        PLAYER4_DEATH_7,
        PLAYER4_DEATH_8
    };

    typedef std::map<TextureID,SDL_Rect> TextureMap;

    extern std::initializer_list<
        std::pair<const TextureID,SDL_Rect>
        > TEXTURE_ASSOCIATIONS;

}
