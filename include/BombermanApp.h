#ifndef BombermanApp_H
#define BombermanApp_H

#include <map>
#include "extern/tinyxml2.h"

#include "sdl/SdlApp.h"
#include "core/Grid.h"

typedef std::map<BombermanCore::tile_mask,SDL_Rect> TextureMap;

class BombermanApp : public SdlApp
{
private:
    BombermanCore::Grid m_grid;
    TextureMap m_texture_map;
    SDL_Texture* m_tilemap;

    void loadTilemap();
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