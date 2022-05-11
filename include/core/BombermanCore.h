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
        /// Clears type with a bitwise and
        const tile_mask CLEAR        = 0xfff0;
        /// Describes a navigable tile
        const tile_mask EMPTY        = 0x1;
        /// Describes a destructible block
        const tile_mask BLOCK        = 0x2;
        /// Describes an unbreakable wall
        const tile_mask UNBREAKABLE = 0x4;
        /// [DEV] Describes the slots still available
        const tile_mask UNUSED_TYPE  = 0x8;
    };

    /// Masks expressing the potential content of a Tile
    namespace TileContent {
        /// Clears content with a bitwise and
        const tile_mask CLEAR        = 0x000f;
        /// No content
        const tile_mask NOTHING      = 0x10;
        /// Added max bombs bonus
        const tile_mask BONUS_BOMB   = 0x20;
        /// Added firepower bonus
        const tile_mask BONUS_FIRE   = 0x40;
        /// The footbomb bonus
        const tile_mask FOOTBOMB     = 0x80;
        /// The remote bomb bonus
        const tile_mask REMOTE       = 0x100;
        /// [DEV] Describes the slots still available
        const tile_mask UNUSED_SLOTS = 0xfe00; // All last 7 bits
    }
} // namespace BombermanCore
