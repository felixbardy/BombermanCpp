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
          {PLAYER1_WALK_DOWN_2, {56,  13,  16, 19}},        
          {PLAYER1_UP,          {80,  13,  16, 19}},      
          {PLAYER1_WALK_UP_1,   {104, 13,  16, 19}},          
          {PLAYER1_WALK_UP_2,   {128, 13,  16, 19}},
          {PLAYER1_SIDE,        {152, 13,  16, 19}},
          {PLAYER1_WALK_SIDE_1, {176, 13,  16, 19}},          
          {PLAYER1_WALK_SIDE_2, {200, 13,  16, 19}},

          {PLAYER2_DOWN,        {8,   77,  16, 19}},         
          {PLAYER2_WALK_DOWN_1, {32,  77,  16, 19}},          
          {PLAYER2_WALK_DOWN_2, {56,  77,  16, 19}},        
          {PLAYER2_UP,          {80,  77,  16, 19}},      
          {PLAYER2_WALK_UP_1,   {104, 77,  16, 19}},          
          {PLAYER2_WALK_UP_2,   {128, 77,  16, 19}},
          {PLAYER2_SIDE,        {152, 77,  16, 19}},
          {PLAYER2_WALK_SIDE_1, {176, 77,  16, 19}},          
          {PLAYER2_WALK_SIDE_2, {200, 77,  16, 19}},

          {PLAYER3_DOWN,        {8,   173,  16, 19}},         
          {PLAYER3_WALK_DOWN_1, {32,  173,  16, 19}},          
          {PLAYER3_WALK_DOWN_2, {56,  173,  16, 19}},        
          {PLAYER3_UP,          {80,  173,  16, 19}},      
          {PLAYER3_WALK_UP_1,   {104, 173,  16, 19}},          
          {PLAYER3_WALK_UP_2,   {128, 173,  16, 19}},
          {PLAYER3_SIDE,        {152, 173,  16, 19}},
          {PLAYER3_WALK_SIDE_1, {176, 173,  16, 19}},          
          {PLAYER3_WALK_SIDE_2, {200, 173,  16, 19}},

          {PLAYER4_DOWN,        {8,   237,  16, 19}},         
          {PLAYER4_WALK_DOWN_1, {32,  237,  16, 19}},          
          {PLAYER4_WALK_DOWN_2, {56,  237,  16, 19}},        
          {PLAYER4_UP,          {80,  237,  16, 19}},      
          {PLAYER4_WALK_UP_1,   {104, 237,  16, 19}},          
          {PLAYER4_WALK_UP_2,   {128, 237,  16, 19}},
          {PLAYER4_SIDE,        {152, 237,  16, 19}},
          {PLAYER4_WALK_SIDE_1, {176, 237,  16, 19}},          
          {PLAYER4_WALK_SIDE_2, {200, 237,  16, 19}},

      };
}

BombermanApp::BombermanApp(int width, int height, std::string name, int framerate, int n_players, int grid_w, int grid_h)
    : SdlApp(width, height, name, framerate),
      m_grid(grid_w, grid_h),
      m_n_players(n_players)
{
  const int players_pos[] = {
    grid_w+1, // top left
    2*grid_w-2, // top right
    grid_h*grid_w - grid_w - 2, // bottom right
    grid_h*grid_w - 2*grid_w + 1 // bottom left
  };

  m_players = new BG::DrawablePlayer[n_players];

  for (int i = 0; i < n_players; i++) {
    m_players[i] = BG::DrawablePlayer(
      players_pos[i] % grid_w,
      players_pos[i] / grid_w
    );
    m_players[i].setKeyMap(BG::players_default_map[i]);
    m_players[i].setTextureMap(BG::players_texture_map[i]);
  }

}

BombermanApp::~BombermanApp()
{
  SDL_DestroyTexture(m_tilemap);
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

  // Affichage du terrain
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

  //*******************/
  //* Drawing players */
  //*******************/
  
  // Horizontal texture offset due to player oversizing
  int player_hor_offset = unit_size * (BG::PLAYER_OVERSIZE / 2.0);
  // Width of the rendered player
  int player_width  = unit_size * (1.0 + BG::PLAYER_OVERSIZE);
  // Height of the rendered player
  int player_height = 19.0 * ((float)player_width / 16.0);

  // Draw each player
  for (int i = 0; i < m_n_players; i++) {
    // Get a pointer to the player
    BG::DrawablePlayer* player = &m_players[i];
    // Get the player's position
    float x,y;
    player->getPos(&x, &y);
    // Generate the destination rectangle
    SDL_Rect dst_rect = {
      // x minus the horizontal offset
      x * unit_size - player_hor_offset,
      // y shifted so that the base of the player
      // is at the corresponding coordinates
      y * unit_size - (player_height - (unit_size / 1.5)),
      player_width, // width
      player_height // height
    };
    // Getting the source rectangle from the texture map
    SDL_Rect src_rect = m_texture_map[player->getTexture(getFramecount())];

    // Flip the texture if player is headed to the left
    SDL_RendererFlip flip = 
      (player->getDir() == Direction::LEFT) 
      ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;

    // Render the player
    SDL_RenderCopyEx(
      this->renderer,
      m_tilemap,
      &src_rect, &dst_rect,
      0, NULL,
      flip
    );
    
    player->clearActions();
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
  const Uint8* kb_state = SDL_GetKeyboardState(NULL);

  // Gestion de l'input des joueurs
  for (int i = 0; i < m_n_players; i++) {
    m_players[i].handleInput(kb_state);
    m_players[i].simplifyActions();
  }

  // Action des joueurs
  for (int i = 0; i < m_n_players; i++) {
    // Get the player
    BG::DrawablePlayer *player = &m_players[i];
    if (!player->isDead()) {
      // Get the player's actions
      BC::ActionMask actions = player->getActions();
      // Get the player's position
      float player_x,player_y;
      int tile_x, tile_y;
      player->getPos(&player_x, &player_y);
      tile_x = (int)(player_x + 0.5);
      tile_y = (int)(player_y + 0.5);
      // If the player is acting, put a bomb on the current tile
      if (actions & ActionMasks::ACTION) {
        // If there is not already a bomb there
        if (!(m_grid.getTile(tile_x, tile_y)->getContent() & TileContent::BOMB))
          // Add a bomb following the player's stats
          // TODO Account for the remote bonus
          m_grid.getTile(tile_x,tile_y)->addBomb(
            {false,BOMB_DEFAUT_TIMER,player->getPower()}
          );
      }
      if (actions & ActionMasks::GO_DOWN) {
        //TODO Check if possible
        player->move(DOWN);
      }
      if (actions & ActionMasks::GO_UP) {
        //TODO Check if possible
        player->move(UP);
      }
      if (actions & ActionMasks::GO_LEFT) {
        //TODO Check if possible
        player->move(LEFT);
      }
      if (actions & ActionMasks::GO_RIGHT) {
        //TODO Check if possible
        player->move(RIGHT);
      }
      if (actions & ActionMasks::PAUSE) {
        //TODO Pause
      }
    } // END IF isDead()
  }

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
  propagateExplosion(x,y,Direction::RIGHT, bomb->power);
  propagateExplosion(x,y,Direction::LEFT, bomb->power);
  propagateExplosion(x,y,Direction::DOWN, bomb->power);
  propagateExplosion(x,y,Direction::UP, bomb->power);
}

void BombermanApp::propagateExplosion(int x, int y, Direction dir, int power) {
  if (power == 0) return;

  Tile* tile = nullptr;

  while(power > 0) {
    switch(dir) {
      case UP:
        tile = m_grid.getTile(x,--y);
        break;
      case DOWN:
        tile = m_grid.getTile(x,++y);
        break;
      case LEFT:
        tile = m_grid.getTile(--x,y);
        break;
      case RIGHT:
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
        if (dir != UP) propagateExplosion(x,y,DOWN,bomb->power);
        if (dir != DOWN) propagateExplosion(x,y,UP,bomb->power);
        if (dir != RIGHT)  propagateExplosion(x,y,LEFT, bomb->power);
        if (dir != LEFT)  propagateExplosion(x,y,RIGHT, bomb->power);

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
        if (dir == UP || dir == DOWN) exp_dir = VERTICAL;
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
      case DOWN:
        return m_texture_map[BG::EXP_DOWN_4];
      case UP:
        return m_texture_map[BG::EXP_UP_4];
      case RIGHT:
        return m_texture_map[BG::EXP_RIGHT_4];
      case LEFT:
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
      case DOWN:
        return m_texture_map[BG::EXP_DOWN_3];
      case UP:
        return m_texture_map[BG::EXP_UP_3];
      case RIGHT:
        return m_texture_map[BG::EXP_RIGHT_3];
      case LEFT:
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
      case DOWN:
        return m_texture_map[BG::EXP_DOWN_2];
      case UP:
        return m_texture_map[BG::EXP_UP_2];
      case RIGHT:
        return m_texture_map[BG::EXP_RIGHT_2];
      case LEFT:
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
      case DOWN:
        return m_texture_map[BG::EXP_DOWN_1];
      case UP:
        return m_texture_map[BG::EXP_UP_1];
      case RIGHT:
        return m_texture_map[BG::EXP_RIGHT_1];
      case LEFT:
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