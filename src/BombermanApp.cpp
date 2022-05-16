#include "BombermanApp.h"

#include <iostream>

using namespace BombermanCore;

namespace BombermanGraphics {

    std::initializer_list<
            std::pair<const TextureID,SDL_Rect>
            > TEXTURE_ASSOCIATIONS = {
        //    NAME   x  y   w  h
        //   |____|  |  |   |  |
            {EMPTY, {32,328,12,12}},
            {BLOCK, {80,328,12,12}},
            {WALL,  {8,328,12,12}}
    };
}

BombermanApp::BombermanApp(int width, int height, std::string name, int framerate)
: SdlApp(width, height, name, framerate),
  m_grid(17,17)
{

}

BombermanApp::~BombermanApp()
{
}

void BombermanApp::Init() {
    //* Code d'initialisation de l'application
    loadTilemap();
}

void BombermanApp::Update() {
    //* Code de mise à jour de l'application
}

void BombermanApp::Render() {
    //* Code d'affichage de l'application
    SDL_RenderClear(renderer);

    int unit_size = std::min(
        this->getWidth() / m_grid.getWidth(),
        this->getHeight() / m_grid.getHeight()
    );

    for (int y = 0; y < m_grid.getHeight(); y++)
    for (int x = 0; x < m_grid.getWidth(); x++)
    {
        SDL_Rect dst_rect;
        SDL_Rect src_rect = getCurrentTexture(x,y);
        dst_rect.x = x*unit_size;
        dst_rect.y = y*unit_size;
        dst_rect.w = unit_size;
        dst_rect.h = unit_size;
        SDL_RenderCopy(
            renderer,
            m_tilemap,
            &src_rect,
            &dst_rect
        );
    }

    SDL_RenderPresent(renderer);
}

void BombermanApp::Quit() {
    //* Code à exécuter en sortie de l'application
}


void BombermanApp::loadTilemap() {
    SDL_Surface* surface = IMG_Load("assets/sprites/tilemap.png");
    m_tilemap = SDL_CreateTextureFromSurface(renderer,surface);

    m_texture_map.insert(
        BombermanGraphics::TEXTURE_ASSOCIATIONS
    );
}

SDL_Rect BombermanApp::getCurrentTexture(int x, int y) {
    const Tile* tile = m_grid.getTile(x,y);

    if (tile->getMask() & TileType::BLOCK)
        return m_texture_map[BombermanGraphics::BLOCK];
    if (tile->getMask() & TileType::UNBREAKABLE)
        return m_texture_map[BombermanGraphics::WALL];
    if (tile->getMask() & TileType::CLEAR)
        return m_texture_map[BombermanGraphics::EMPTY];

    return m_texture_map[BombermanGraphics::MISSING_TEXTURE];
}