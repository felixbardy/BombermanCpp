#ifndef BombermanApp_H
#define BombermanApp_H

#include "sdl/SdlApp.h"

class BombermanApp : public SdlApp
{
private:
    /* data */
public:
    BombermanApp(int width, int height, std::string name, int framerate);
    ~BombermanApp();

    void Init();
    void Update();
    void Render();
    void Quit();
};


#endif //BombermanApp_H