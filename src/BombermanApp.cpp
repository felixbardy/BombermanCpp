#include "BombermanApp.h"

#include <iostream>

using namespace BombermanCore;
namespace BG = BombermanGraphics;

namespace BombermanGraphics
{

  std::initializer_list<
      std::pair<const TextureID, SDL_Rect>>
      TEXTURE_ASSOCIATIONS = {
     //    NAME                  x    y    w   h
     //   |____|                 |    |    |   |
          {EMPTY,               {32,  328, 12, 12}},
          {BLOCK,               {80,  328, 12, 12}},
          {WALL,                {8,   328, 12, 12}},

          {BOMB_1,              {58,  276, 12, 12}},
          {BOMB_2,              {35,  276, 12, 12}},
          {BOMB_3,              {11,  276, 12, 12}},

          {EXP_CENTER_1,        {200, 352, 12, 12}},
          {EXP_CENTER_2,        {176, 352, 12, 12}},
          {EXP_CENTER_3,        {152, 352, 12, 12}},
          {EXP_CENTER_4,        {128, 352, 12, 12}},
          {EXP_HORIZONTAL_1,    {368, 376, 12, 12}},
          {EXP_HORIZONTAL_2,    {344, 376, 12, 12}},
          {EXP_HORIZONTAL_3,    {320, 376, 12, 12}},
          {EXP_HORIZONTAL_4,    {296, 376, 12, 12}},
          {EXP_VERTICAL_1,      {272, 376, 12, 12}},
          {EXP_VERTICAL_2,      {248, 376, 12, 12}},
          {EXP_VERTICAL_3,      {224, 376, 12, 12}},
          {EXP_VERTICAL_4,      {200, 376, 12, 12}},
          {EXP_LEFT_1,          {176, 376, 12, 12}},
          {EXP_LEFT_2,          {152, 376, 12, 12}},
          {EXP_LEFT_3,          {128, 376, 12, 12}},
          {EXP_LEFT_4,          {104, 376, 12, 12}},
          {EXP_DOWN_1,          {80 , 376, 12, 12}},
          {EXP_DOWN_2,          {56 , 376, 12, 12}},
          {EXP_DOWN_3,          {32 , 376, 12, 12}},
          {EXP_DOWN_4,          {8  , 376, 12, 12}},
          {EXP_UP_1,            {296, 352, 12, 12}},
          {EXP_UP_2,            {272, 352, 12, 12}},
          {EXP_UP_3,            {248, 352, 12, 12}},
          {EXP_UP_4,            {224, 352, 12, 12}},
          {EXP_RIGHT_1,         {392, 352, 12, 12}},
          {EXP_RIGHT_2,         {368, 352, 12, 12}},
          {EXP_RIGHT_3,         {344, 352, 12, 12}},
          {EXP_RIGHT_4,         {320, 352, 12, 12}},

          {CRUMBLING_BLOCK_1,   {368, 328, 12, 12}},
          {CRUMBLING_BLOCK_2,   {392, 328, 12, 12}},
          {CRUMBLING_BLOCK_3,   {8,   352, 12, 12}},
          {CRUMBLING_BLOCK_4,   {32,  352, 12, 12}},
          {CRUMBLING_BLOCK_5,   {56,  352, 12, 12}},
          {CRUMBLING_BLOCK_6,   {80,  352, 12, 12}},
          {CRUMBLING_BLOCK_7,   {104, 352, 12, 12}},

          {PLAYER1_DOWN,        {8,   13,  16, 19}},         
          {PLAYER1_WALK_DOWN_1, {32,  13,  16, 19}},          
          {PLAYER1_WALK_DOWN_2, {56,  13,  14, 19}},        
          {PLAYER1_UP,          {80,  13,  16, 19}},      
          {PLAYER1_WALK_UP_1,   {104, 13,  16, 19}},          
          {PLAYER1_WALK_UP_2,   {128, 13,  14, 19}},
          {PLAYER1_SIDE,        {152, 13,  16, 19}},
          {PLAYER1_WALK_SIDE_1, {176, 13,  16, 19}},          
          {PLAYER1_WALK_SIDE_2, {200, 13,  14, 19}},

          {PLAYER2_DOWN,        {8,   88,  16, 19}},         
          {PLAYER2_WALK_DOWN_1, {32,  88,  16, 19}},          
          {PLAYER2_WALK_DOWN_2, {56,  88,  14, 19}},        
          {PLAYER2_UP,          {80,  88,  16, 19}},      
          {PLAYER2_WALK_UP_1,   {104, 88,  16, 19}},          
          {PLAYER2_WALK_UP_2,   {128, 88,  14, 19}},
          {PLAYER2_SIDE,        {152, 88,  16, 19}},
          {PLAYER2_WALK_SIDE_1, {176, 88,  16, 19}},          
          {PLAYER2_WALK_SIDE_2, {200, 88,  14, 19}},

          {PLAYER3_DOWN,        {8,   173,  16, 19}},         
          {PLAYER3_WALK_DOWN_1, {32,  173,  16, 19}},          
          {PLAYER3_WALK_DOWN_2, {56,  173,  14, 19}},        
          {PLAYER3_UP,          {80,  173,  16, 19}},      
          {PLAYER3_WALK_UP_1,   {104, 173,  16, 19}},          
          {PLAYER3_WALK_UP_2,   {128, 173,  14, 19}},
          {PLAYER3_SIDE,        {152, 173,  16, 19}},
          {PLAYER3_WALK_SIDE_1, {176, 173,  16, 19}},          
          {PLAYER3_WALK_SIDE_2, {200, 173,  14, 19}},

          {PLAYER4_DOWN,        {8,   237,  16, 19}},         
          {PLAYER4_WALK_DOWN_1, {32,  237,  16, 19}},          
          {PLAYER4_WALK_DOWN_2, {56,  237,  14, 19}},        
          {PLAYER4_UP,          {80,  237,  16, 19}},      
          {PLAYER4_WALK_UP_1,   {104, 237,  16, 19}},          
          {PLAYER4_WALK_UP_2,   {128, 237,  14, 19}},
          {PLAYER4_SIDE,        {152, 237,  16, 19}},
          {PLAYER4_WALK_SIDE_1, {176, 237,  16, 19}},          
          {PLAYER4_WALK_SIDE_2, {200, 237,  14, 19}},

      };
}

BombermanApp::BombermanApp(int width, int height, std::string name, int framerate)
    : SdlApp(width, height, name, framerate),
      m_grid(17, 17)
{
}

BombermanApp::~BombermanApp()
{
}

void BombermanApp::Init()
{
  //* Code d'initialisation de l'application
  loadTilemap();

  // DEBUG
  // FIXME Remove test lines when not needed
}

void BombermanApp::Update()
{
  //* Code de mise à jour de l'application

  // 1• Mise à jour du terrain (bombes / explosions)
  updateTerrain();

  // 2• Gestion de l'input / actions / réactions
  handleInput();
}

void BombermanApp::Render()
{
  //* Code d'affichage de l'application
  SDL_RenderClear(renderer);

  int unit_size = std::min(
      this->getWidth() / m_grid.getWidth(),
      this->getHeight() / m_grid.getHeight());

  for (int y = 0; y < m_grid.getHeight(); y++)
    for (int x = 0; x < m_grid.getWidth(); x++)
    {
      SDL_Rect dst_rect;
      SDL_Rect src_rect = getCurrentTexture(x, y);
      dst_rect.x = x * unit_size;
      dst_rect.y = y * unit_size;
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

void BombermanApp::Quit()
{
  //* Code à exécuter en sortie de l'application
}

void BombermanApp::loadTilemap()
{
  SDL_Surface *surface = IMG_Load("assets/sprites/tilemap.png");
  m_tilemap = SDL_CreateTextureFromSurface(renderer, surface);

  m_texture_map.insert(BG::TEXTURE_ASSOCIATIONS);
}

void BombermanApp::updateTerrain()
{
  for (int y = 0; y < m_grid.getHeight(); y++)
    for (int x = 0; x < m_grid.getWidth(); x++)
    {
      Tile *tile = m_grid.getTile(x, y);

      // Traitement des explosions en cours
      if (tile->getMask() & TileContent::EXPLOSION)
      {
        // Accéder à l'explosion
        explosion_data *exp = tile->getExplosion();
        // Décrémenter son compteur
        exp->step--;
        // Si le compteur est épuisé, retirer l'explosion
        if (exp->step == 0)
          tile->setContent(TileContent::NOTHING);
      }

      // Traitement des bombes
      if (tile->getMask() & TileContent::BOMB)
      {
        // Accéder à la bombe
        bomb_data *bomb = tile->getBomb();
        // Décrémenter le timer
        bomb->timer--;
        // Si le timer est à bout, détoner la bombe
        if (bomb->timer == 0)
          detonateBomb(x, y, bomb);
      }

      // Traitement des murs qui s'écroulent
      if (tile->getMask() & TileType::CRUMBLING_WALL) {
        int timer = tile->getCrumblingTimer();
        tile->setCrumblingTimer(--timer);
        if (timer == 0) tile->setType(TileType::EMPTY);
      }
    }
}

void BombermanApp::handleInput()
{
  int unit_size = getWidth() / m_grid.getWidth();
  int mx,my,tx,ty;
  SDL_GetMouseState(&mx,&my);

  SDL_Event e;
  while(SDL_PollEvent(&e)) {
    if (e.type == SDL_MOUSEBUTTONDOWN) {
      Uint8 pressed = e.button.button;
      if (pressed == SDL_BUTTON_LEFT) {
        tx = mx / unit_size;
        ty = my / unit_size;
        m_grid.getTile(tx,ty)->addBomb({false,BOMB_DEFAUT_TIMER,2});
      }
    }
  }
}

void BombermanApp::detonateBomb(int x, int y, bomb_data *bomb)
{
  Tile *origin = m_grid.getTile(x, y);
  origin->setContent(TileContent::EXPLOSION);
  origin->addExplosion(
      {
          Direction::NONE,          // Centre de l'explosion
          6*EXPLOSION_STEP_DURATION // Timer de 7 étapes
      }
  );
  propagateExplosion(x,y,Direction::EAST, bomb->power);
  propagateExplosion(x,y,Direction::WEST, bomb->power);
  propagateExplosion(x,y,Direction::SOUTH, bomb->power);
  propagateExplosion(x,y,Direction::NORTH, bomb->power);
}

void BombermanApp::propagateExplosion(int x, int y, Direction dir, int power) {
  //TODO Implement this function
  //FIXME Penser à une implémentation non-récursive
  
  if (power == 0) return;

  Tile* tile = nullptr;

  while(power > 0) {
    switch(dir) {
      case NORTH:
        tile = m_grid.getTile(x,--y);
        break;
      case SOUTH:
        tile = m_grid.getTile(x,++y);
        break;
      case WEST:
        tile = m_grid.getTile(--x,y);
        break;
      case EAST:
        tile = m_grid.getTile(++x,y);
        break;
      default:
        return;
    }

    // Si la case est vide
    if (tile->getMask() & TileType::EMPTY) {
      // Si il y a une bombe
      if (tile->getMask() & (TileContent::BOMB | TileContent::REMOTE)) {
        // Récupérer les connées de la bombe
        bomb_data* bomb = tile->getBomb();

        // Placer l'explosion sur la case
        tile->setContent(TileContent::EXPLOSION);
        tile->addExplosion(
          {
            Direction::NONE,
            6 * EXPLOSION_STEP_DURATION
          }
        );
        
        // Faire exploser la bombe dans les 3 autres directions
        if (dir != NORTH) propagateExplosion(x,y,SOUTH,bomb->power);
        if (dir != SOUTH) propagateExplosion(x,y,NORTH,bomb->power);
        if (dir != EAST)  propagateExplosion(x,y,WEST, bomb->power);
        if (dir != WEST)  propagateExplosion(x,y,EAST, bomb->power);

        // Arrêter la propagation
        return;
      }
      // Sinon, si la case contient une explosion
      else if (tile->getMask() & TileContent::EXPLOSION) {
        //TODO Joindre les explosions correctement
      }
      // Sinon, si un bonus est présent
      else if (
        tile->getMask() 
        & 
        (TileContent::BONUS_BOMB | TileContent::BONUS_FIRE | TileContent::BONUS_FOOTBOMB | TileContent::BONUS_REMOTE)
        ) {
        //TODO Brûler le bonus
        // Arrêter la propagation
        return;
      }
      
      // Une fois les conditions passée, sachant la case vide,
      // on peut propager l'explosion dans cette direction
      Direction exp_dir;
      if (power == 1) exp_dir = dir;
      else if (dir == NONE) exp_dir = NONE;
      else {
        if (dir == NORTH || dir == SOUTH) exp_dir = VERTICAL;
        else  exp_dir = HORIZONTAL;
      }
      

      tile->setContent(TileContent::EXPLOSION);
      tile->addExplosion(
        {
          exp_dir,
          6 * EXPLOSION_STEP_DURATION
        }
      );
      // Et on décrémente la puissance
      power--;


    } // FIN SI (la case est vide)

    // Si la case n'est pas vide:
    else if (tile->getMask() & TileType::BLOCK) {
        // Lancer la destruction du bloc
        tile->setType(TileType::CRUMBLING_WALL);
        tile->setCrumblingTimer(7 * CRUMBLING_STEP_DURATION);
        // Une fois la destruction lancée, arrêter l'explosion
        return;
    }
    else {
      // Si aucune des conditions n'est remplie, on s'arrête
      return;
    }
  }

}

SDL_Rect BombermanApp::getCurrentTexture(int x, int y)
{
  const Tile *tile = m_grid.getTile(x, y);

  if (tile->getMask() & TileContent::BOMB)
  {
    switch ((BG::BOMB_LOOP_SPEED * getFramecount() / getFramerate()) % 4)
    {
    case 0:
      return m_texture_map[BG::BOMB_1];
    case 1:
      return m_texture_map[BG::BOMB_2];
    case 2:
      return m_texture_map[BG::BOMB_3];
    case 3:
      return m_texture_map[BG::BOMB_2];
    default:
      return m_texture_map[BG::MISSING_TEXTURE];
    }
  }

  if (tile->getMask() & TileContent::EXPLOSION)
  {
    switch (std::abs(tile->getExplosion()->step/EXPLOSION_STEP_DURATION - 3))
    {
    case 0:
      switch (tile->getExplosion()->dir)
      {
      case NONE:
        return m_texture_map[BG::EXP_CENTER_4];
      case HORIZONTAL:
        return m_texture_map[BG::EXP_HORIZONTAL_4];
      case VERTICAL:
        return m_texture_map[BG::EXP_VERTICAL_4];
      case SOUTH:
        return m_texture_map[BG::EXP_DOWN_4];
      case NORTH:
        return m_texture_map[BG::EXP_UP_4];
      case EAST:
        return m_texture_map[BG::EXP_RIGHT_4];
      case WEST:
        return m_texture_map[BG::EXP_LEFT_4];
      }
    case 1:
      switch (tile->getExplosion()->dir)
      {
      case NONE:
        return m_texture_map[BG::EXP_CENTER_3];
      case HORIZONTAL:
        return m_texture_map[BG::EXP_HORIZONTAL_3];
      case VERTICAL:
        return m_texture_map[BG::EXP_VERTICAL_3];
      case SOUTH:
        return m_texture_map[BG::EXP_DOWN_3];
      case NORTH:
        return m_texture_map[BG::EXP_UP_3];
      case EAST:
        return m_texture_map[BG::EXP_RIGHT_3];
      case WEST:
        return m_texture_map[BG::EXP_LEFT_3];
      }
    case 2:
      switch (tile->getExplosion()->dir)
      {
      case NONE:
        return m_texture_map[BG::EXP_CENTER_2];
      case HORIZONTAL:
        return m_texture_map[BG::EXP_HORIZONTAL_2];
      case VERTICAL:
        return m_texture_map[BG::EXP_VERTICAL_2];
      case SOUTH:
        return m_texture_map[BG::EXP_DOWN_2];
      case NORTH:
        return m_texture_map[BG::EXP_UP_2];
      case EAST:
        return m_texture_map[BG::EXP_RIGHT_2];
      case WEST:
        return m_texture_map[BG::EXP_LEFT_2];
      }
    case 3:
      switch (tile->getExplosion()->dir)
      {
      case NONE:
        return m_texture_map[BG::EXP_CENTER_1];
      case HORIZONTAL:
        return m_texture_map[BG::EXP_HORIZONTAL_1];
      case VERTICAL:
        return m_texture_map[BG::EXP_VERTICAL_1];
      case SOUTH:
        return m_texture_map[BG::EXP_DOWN_1];
      case NORTH:
        return m_texture_map[BG::EXP_UP_1];
      case EAST:
        return m_texture_map[BG::EXP_RIGHT_1];
      case WEST:
        return m_texture_map[BG::EXP_LEFT_1];
      }
    default:
      std::cerr << "Something seems off with explosion at " << x << "," << y << std::endl;
    }
  }

  if (tile->getMask() & TileType::BLOCK)
    return m_texture_map[BG::BLOCK];
  if (tile->getMask() & TileType::UNBREAKABLE)
    return m_texture_map[BG::WALL];
  if (tile->getMask() & TileType::EMPTY)
    return m_texture_map[BG::EMPTY];
  if (tile->getMask() & TileType::CRUMBLING_WALL) {
    switch(tile->getCrumblingTimer()/CRUMBLING_STEP_DURATION) {
      case 6:
        return m_texture_map[BG::CRUMBLING_BLOCK_1];
      case 5:
        return m_texture_map[BG::CRUMBLING_BLOCK_2];
      case 4:
        return m_texture_map[BG::CRUMBLING_BLOCK_3];
      case 3:
        return m_texture_map[BG::CRUMBLING_BLOCK_4];
      case 2:
        return m_texture_map[BG::CRUMBLING_BLOCK_5];
      case 1:
        return m_texture_map[BG::CRUMBLING_BLOCK_6];
      case 0:
        return m_texture_map[BG::CRUMBLING_BLOCK_7];
      default:
        return m_texture_map[BG::MISSING_TEXTURE];
    }
  }
    

  return m_texture_map[BG::MISSING_TEXTURE];
}