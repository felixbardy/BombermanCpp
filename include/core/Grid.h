#pragma once

#include "core/Tile.h"

namespace BombermanCore {
    /**
     * @brief Stores the grid and provides an interface to
     * generate, access and modify it
     * 
     */
    class Grid
    {
    private:
        Tile* m_grid; //!< the grid itself
        int w,h;      //!< width and height
        
    public:
        /**
         * @brief Construct a new Grid of given size
         * 
         * @param width width of the Grid
         * @param height height of the Grid
         */
        Grid(int width, int height);
        ~Grid();

        /**
         * @brief Get the width of the Grid
         * 
         * @return int
         */
        int getWidth() const;

        /**
         * @brief Get the height of the Grid
         * 
         * @return int 
         */
        int getHeight() const;

        /**
         * @brief Get the Tile at given index
         * 
         * @param index the index of the Tile
         * @return const Tile* a pointer to the Tile
         */
        Tile* getTile(int index);

        /**
         * @brief Get the Tile at given coordinates
         * 
         * @param x the horizontal coordinate
         * @param y the vertical coordinate
         * @return const Tile* a pointer to the Tile
         */
        Tile* getTile(int x, int y);
    };
}