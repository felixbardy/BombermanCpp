#include "core/Tile.h"

namespace BombermanCore
{
    Tile::Tile()
    {
        this->m_mask = TileType::EMPTY | TileContent::NOTHING;
    }

    Tile::Tile(tile_mask mask)
    {
    }

    Tile::~Tile()
    {
    }

} // namespace BombermanCore