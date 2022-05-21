#include "sdl/SdlApp.h"

void SdlApp::fullInit()
{
    this->window = SDL_CreateWindow(
        name.c_str(),
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height,
        0
    );

    this->renderer = SDL_CreateRenderer(
        window,
        -1,
        0
    );

    Init();
    first_tick = SDL_GetTicks();
    previous_frame = -tick_interval;
    
}

void SdlApp::fullUpdate()
{
    SDL_PumpEvents();

    SDL_Event e;

    if (SDL_PeepEvents(&e,1,SDL_PEEKEVENT,SDL_QUIT, SDL_QUIT) > 0) {
        this->exit_app();
        return;
    }

    const Uint8* keypressed = SDL_GetKeyboardState(NULL);

    for( auto const& [scancode, callback] : callbacks )
    {
        if (keypressed[scancode])
            callback(scancode, this);
    }

    Update();
    /* do stuff */
}

void SdlApp::fullRender()
{
    Render();
    frameCount++;
    /* render additional info above the rest */
}

SdlApp::SdlApp(int width, int height, std::string name, int framerate) :
quit(false), target_framerate(framerate),
ticks(0), frameCount(0), previous_frame(0),
droppedFrames(0), first_tick(0),
width(width), height(height),
name(name)
{
  tick_interval = (1.0f / (float) framerate) * 1000;
}


SdlApp::~SdlApp()
{
    //Détruire le renderer
    SDL_DestroyRenderer(renderer);

    //Détruire la fenêtre
    SDL_DestroyWindow(window);
}

Uint32 SdlApp::getFramecount() const {return frameCount;}

int SdlApp::getWidth() const {return width;}

int SdlApp::getHeight() const {return height;}

int SdlApp::getFramerate() const {return target_framerate;}

void SdlApp::loop()
{
    fullInit();
    while ( !quit )
    {
        ticks = SDL_GetTicks();
        if (ticks > previous_frame + tick_interval)
        {
            droppedFrames += (ticks - previous_frame) / tick_interval - 1;
            previous_frame = ticks;
            fullUpdate();
            fullRender();
        }
        else
        {
            SDL_Delay(tick_interval - (ticks - previous_frame));
        }
    }

    Quit();
}

void SdlApp::exit_app()
{
    this->quit = true;
}