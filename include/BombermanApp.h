#ifndef BombermanApp_H
#define BombermanApp_H

#include "sdl/SdlApp.h"
#include "core/Grid.h"

class BombermanApp : public SdlApp
{
private:
    BombermanCore::Grid m_grid;
public:
    BombermanApp(int width, int height, std::string name, int framerate);
    ~BombermanApp();

    void Init();
    void Update();
    void Render();
    void Quit();
};


#endif //BombermanApp_H