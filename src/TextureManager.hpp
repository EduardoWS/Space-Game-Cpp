#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "Game.hpp"

class TextureManager{

public:
    static SDL_Texture *LoadTexture(const char *filename, SDL_Renderer *ren);
};




#endif