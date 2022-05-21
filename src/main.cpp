#include <iostream>
#include <string>
#include <sstream>

#include "BombermanApp.h"

#include "CmakeConfig.h"

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    if ( TTF_Init() == -1)
    {
        std::cout << "Failed to initialize SDL_TTF!" << std::endl;
        IMG_Quit();
        SDL_Quit();
        exit(1);
    }

    std::stringstream title;
    title << "BombermanApp " 
          << BombermanApp_VERSION_MAJOR
          << "."
          << BombermanApp_VERSION_MINOR;

    BombermanApp app(600, 600, title.str(), 60, 2, 17, 17);
    app.loop();

    // À la sortie du programme:

    //Détruire les textures
    //? SDL_DestroyTexture( texture );

    //Détruire les surfaces
    //? SDL_FreeSurface( surface );

    //Fermer les polices
    //? TTF_CloseFont( font );

    

    //Fermer SDL, SDL_Image et SDL_ttf
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    return 0;
}