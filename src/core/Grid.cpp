#include "core/Grid.h"

#include <random>

namespace BombermanCore
{
    Grid::Grid(int width, int height)
    {
        this->w = width;
        this->h = height;
        this->m_grid = new Tile[h*w];

        /* Adding random blocks*/
        for (int i = 0; i < width*height; i++)
            if (rand() % 3) m_grid[i].setType(TileType::BLOCK);

        /* Clearing player zones */
        const int player_zones[12] = {
            //player 1
            width+1,
            width+2,
            2*width+1,

            //player 2
            2*width-3,
            2*width-2,
            3*width-2,

            //player 3
            w*h - 2*width + 1,
            w*h - 2*width + 2,
            w*h - 3*width + 1,

            //player 4
            w*h - width - 2,
            w*h - width - 3,
            w*h - 2*width - 2
        };
        for (int i = 0; i < 12; i++) {
            m_grid[player_zones[i]].setMask(
                TileType::EMPTY | TileContent::NOTHING
            );
        }

        /* Adding the pillars */
        for (int x = 2; x < width-1; x+=2)
        for (int y = 2; y < height-1; y+=2)
            m_grid[y*width+x].setType(TileType::UNBREAKABLE);

        /* Adding the boundaries */
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
        delete[] m_grid;
    }

    int Grid::getWidth() const {
        return w;
    }

    int Grid::getHeight() const {
        return h;
    }

    const Tile* Grid::getTile(int index) const {
        return &m_grid[index];
    }

    const Tile* Grid::getTile(int x, int y) const {
        return getTile(y*w+x);
    }

}