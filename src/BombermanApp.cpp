#include "BombermanApp.h"

#include <iostream>

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
        SDL_Rect src_rect = m_texture_map[m_grid.getTile(x,y)->getType()];
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
    using namespace tinyxml2;
    using namespace BombermanCore;
    // Initialisation du document
    XMLDocument xml_doc;
    // Sert à récupérer les résultats des fonctions
    XMLError result;

    SDL_Surface* surface = IMG_Load("assets/sprites/tilemap.png");
    m_tilemap = SDL_CreateTextureFromSurface(renderer,surface);

    result = xml_doc.LoadFile("assets/sprites/map.xml");
    XMLCheckResult(result);

    XMLNode* root = xml_doc.FirstChild();
    if (root == nullptr) {
        std::cerr << "Texture map file seems empty!"
                     " (check assets/sprites/map.xml)\n";
        exit(XML_ERROR_FILE_READ_ERROR);
    }

    XMLElement* static_tex = root->FirstChildElement("Static");
    
    while (static_tex) {
        int mask;
        SDL_Rect rect;

        result = static_tex->QueryIntAttribute("x", &rect.x);
        XMLCheckResult(result);
        result = static_tex->QueryIntAttribute("y", &rect.y);
        XMLCheckResult(result);
        result = static_tex->QueryIntAttribute("w", &rect.w);
        XMLCheckResult(result);
        result = static_tex->QueryIntAttribute("h", &rect.h);
        XMLCheckResult(result);
        result = static_tex->QueryIntAttribute("mask", &mask);
        XMLCheckResult(result);
        
        std::pair<TextureMap::const_iterator,bool> emplace_result;

        emplace_result = m_texture_map.emplace(
            (tile_mask)mask,
            rect
        );

        if (!emplace_result.second)
            std::cerr << "Failed to load a texture! (id: " << mask <<")\n"; 

        static_tex = static_tex->NextSiblingElement("Static");
    }
}