#pragma once

#include "stdint.h"

/**
 * @brief Contains the Bomberman game's core
 * 
 */
namespace BombermanCore
{
    
    typedef uint16_t tile_mask; //!< Expresses the type and content of a tile
    // Mask structure:
    //      unused | used | tile type
    //      vvvvvvv|vvvvv | vvvv
    // bits xxxxxxx|xxxxx | xxxx

    /// Masks expressing the type of a Tile
    namespace TileType {
        const tile_mask EMPTY        = 0x1;
        const tile_mask BLOCK        = 0x2;
        const tile_mask UNBREACKABLE = 0x4;
        const tile_mask UNUSED_TYPE  = 0x8;
    };

    /// Masks expressing the potential content of a Tile
    namespace TileContent {
        const tile_mask NOTHING      = 0x10;
        const tile_mask BONUS_BOMB   = 0x20;
        const tile_mask BONUS_FIRE   = 0x40;
        const tile_mask FOOTBOMB     = 0x80;
        const tile_mask REMOTE       = 0x100;
        const tile_mask UNUSED_SLOTS = 0xfe00; // All last 7 bits
    }
} // namespace BombermanCore
