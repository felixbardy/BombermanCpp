#include "BombermanApp.h"

BombermanApp::BombermanApp(int width, int height, std::string name, int framerate)
: SdlApp(width, height, name, framerate),
  m_grid(20,20)
{

}

BombermanApp::~BombermanApp()
{
}

void BombermanApp::Init() {
    //* Code d'initialisation de l'application
}

void BombermanApp::Update() {
    //* Code de mise à jour de l'application
}

void BombermanApp::Render() {
    //* Code d'affichage de l'application
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}

void BombermanApp::Quit() {
    //* Code à exécuter en sortie de l'application
}