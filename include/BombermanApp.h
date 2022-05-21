#ifndef BombermanApp_H
#define BombermanApp_H

#include <map>
#include "extern/tinyxml2.h"

#include "sdl/SdlApp.h"
#include "core/Grid.h"

#include "BombermanGraphics.h"
#include "DrawablePlayer.h"

class BombermanApp : public SdlApp
{
private:
  BC::Grid m_grid;
  BG::TextureMap m_texture_map;
  SDL_Texture *m_tilemap;
  BG::DrawablePlayer *m_players;
  int m_n_players;

  void loadTilemap();
  void updateTerrain();
  void handleInput();
  void detonateBomb(int x, int y, BC::bomb_data *bomb);
  void propagateExplosion(int x, int y, BC::Direction dir, int power);
  SDL_Rect getCurrentTexture(int x, int y);
  void xmlLoadStaticTexture(tinyxml2::XMLNode *texture_info);

public:
  BombermanApp(int width, int height, std::string name, int framerate, int n_players, int grid_w, int grid_h);
  ~BombermanApp();

  void Init() override;
  void Update() override;
  void Render() override;
  void Quit() override;
};

#endif // BombermanApp_H