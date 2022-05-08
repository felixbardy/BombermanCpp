#pragma once

#include "BombermanCore.h"

namespace BombermanCore {
    class Tile
    {
    private:
        tile_mask m_mask;
    public:
        Tile();
        Tile(tile_mask mask);
        ~Tile();
    };
    
}