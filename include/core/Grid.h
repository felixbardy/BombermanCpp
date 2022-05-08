#pragma once

#include "core/Tile.h"

namespace BombermanCore {
    /**
     * @brief Stores the grid and provides an interface to access and modify it
     * 
     */
    class Grid
    {
    private:
        Tile* m_grid; //!< the grid itself
        int w,h;      //!< width and height
        
    public:
        Grid(int width, int height);
        ~Grid();
    };
}