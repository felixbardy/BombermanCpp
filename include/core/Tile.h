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

        tile_mask getType() const;
        tile_mask getContent() const;
        tile_mask getMask() const;
        void setType(tile_mask type);
        void setContent(tile_mask content);
        void setMask(tile_mask mask);
    };
    
}