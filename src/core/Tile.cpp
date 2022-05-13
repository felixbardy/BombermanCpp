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

    tile_mask Tile::getMask() const {
        return m_mask;
    }

    tile_mask Tile::getType() const {
        return m_mask & TileContent::CLEAR;
    }

    tile_mask Tile::getContent() const {
        return m_mask & TileType::CLEAR;
    }

    void Tile::setType(tile_mask type) {
        m_mask &= TileType::CLEAR;
        m_mask |= type;
    }

    void Tile::setContent(tile_mask content) {
        m_mask &= TileContent::CLEAR;
        m_mask |= content;
    }

    void Tile::setMask(tile_mask mask) {
        m_mask = mask;
    }

} // namespace BombermanCore