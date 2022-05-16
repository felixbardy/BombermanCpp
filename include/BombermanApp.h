#ifndef BombermanApp_H
#define BombermanApp_H

#include <map>
#include "extern/tinyxml2.h"

#include "sdl/SdlApp.h"
#include "core/Grid.h"
#include "BombermanGraphics.h"

class BombermanApp : public SdlApp
{
private:
    BombermanCore::Grid m_grid;
    BombermanGraphics::TextureMap m_texture_map;
    SDL_Texture* m_tilemap;

    void loadTilemap();
    SDL_Rect getCurrentTexture(int x, int y);
    void xmlLoadStaticTexture(tinyxml2::XMLNode* texture_info);

public:
    BombermanApp(int width, int height, std::string name, int framerate);
    ~BombermanApp();

    void Init() override;
    void Update() override;
    void Render() override;
    void Quit() override;

};


#endif //BombermanApp_H