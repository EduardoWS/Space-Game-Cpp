#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "Game.hpp"

class TextureManager{

public:
    static SDL_Texture *LoadTexture(const char *filename);

    static void Draw(SDL_Texture *texture, int x, int y, int width, int height);
};




#endif