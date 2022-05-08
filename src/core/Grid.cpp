#include "core/Grid.h"

namespace BombermanCore
{
    Grid::Grid(int width, int height)
    {
        this->w = width;
        this->h = height;
        this->m_grid = new Tile[h*w];
    }
    
    Grid::~Grid()
    {
    }

}