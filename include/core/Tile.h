#pragma once

#include "BombermanCore.h"

namespace BombermanCore {
    class Tile
    {
    private:
        tile_mask m_mask;
        bomb_data m_bomb;
        explosion_data m_explosion;
        int m_crumbling_timer;
    public:
        Tile();
        Tile(tile_mask mask);
        ~Tile();

        bool addBomb(bomb_data bomb);
        bomb_data* getBomb();
        const bomb_data* getBomb() const;

        void addExplosion(explosion_data explosion);
        explosion_data* getExplosion();
        const explosion_data* getExplosion() const;

        tile_mask getType() const;
        tile_mask getContent() const;
        tile_mask getMask() const;
        void setType(tile_mask type);
        void setContent(tile_mask content);
        void setMask(tile_mask mask);

        void setCrumblingTimer(int timer);
        int  getCrumblingTimer() const;
    };
    
}