#include "TextureManager.hpp"


SDL_Texture *TextureManager::LoadTexture(const char *filename, SDL_Renderer *ren){

    SDL_Texture *texture = IMG_LoadTexture(ren, filename);

    return texture;
}