#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <map>
#include <string>

class SdlApp
{
protected:
    SDL_Window* window;
    SDL_Renderer* renderer;

private:
    int width, height;
    std::string name;   
    bool quit;
    int target_framerate;
    Uint32 first_tick, previous_frame, ticks, tick_interval;
    Uint32 frameCount, droppedFrames;
    std::map<SDL_Scancode, void (*)(SDL_Scancode, SdlApp*)> callbacks;

    void fullInit();
    void fullUpdate();
    void fullRender();
public:
    SdlApp(int width, int height, std::string name, int framerate = 60);
    ~SdlApp();

protected:
    Uint32 getFramecount();
    int getWidth();
    int getHeight();

    // Méthode à surcharger appelée lors de l'initialisation
    virtual void Init() = 0;
    // Méthode à surchager appelée à chaque frame
    virtual void Update() = 0;
    // Méthode d'affichage à surchager appelée à chaque frame
    virtual void Render() = 0;
    // Méthode à surchager appelée à l'arrêt de l'application
    virtual void Quit() = 0;

public:
    // Ajoute un callback à la pression d'une touche
    void addCallback(SDL_Scancode sc, void (*callback)(SDL_Scancode, SdlApp*));
    // Lance la boucle de l'application
    void loop();
    // Commande l'arrêt de la boucle
    void exit();
};

