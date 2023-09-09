#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include <SDL2/SDL.h>

class Game{

public:
    Game();
    ~Game();

    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running(){ return isRunning; }

private:
    //int cont = 0;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;

};



#endif