#include "core/Grid.h"

namespace BombermanCore
{
    Grid::Grid(int width, int height)
    {
        this->w = width;
        this->h = height;
        this->m_grid = new Tile[h*w];
        for (int x = 0; x < width; x++) {
            m_grid[x].setType(TileType::UNBREAKABLE);
            m_grid[(height-1)*width+x].setType(TileType::UNBREAKABLE);
        }
        for (int y = 0; y < height; y++) {
            m_grid[y*width].setType(TileType::UNBREAKABLE);
            m_grid[y*width + (width-1)].setType(TileType::UNBREAKABLE);
        }
    }
    
    Grid::~Grid()
    {
    }

}