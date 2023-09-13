#include "TextureManager.hpp"


SDL_Texture *TextureManager::LoadTexture(const char *filename){

    SDL_Texture *texture = IMG_LoadTexture(Game::renderer, filename);

    return texture;
}

void TextureManager::Draw(SDL_Texture *texture, int x, int y, int width, int height) {
    SDL_Rect srcRect; // Define a região da textura a ser desenhada.
    SDL_Rect destRect; // Define a região na tela onde a textura será desenhada.

    srcRect.x = 0; // Posição X na textura (começando do canto superior esquerdo).
    srcRect.y = 0; // Posição Y na textura (começando do canto superior esquerdo).
    srcRect.w = width; // Largura da região a ser desenhada na textura.
    srcRect.h = height; // Altura da região a ser desenhada na textura.

    destRect.x = x; // Posição X na tela onde a textura será desenhada.
    destRect.y = y; // Posição Y na tela onde a textura será desenhada.
    destRect.w = width; // Largura da região a ser desenhada na tela.
    destRect.h = height; // Altura da região a ser desenhada na tela.

    SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect); // Renderiza a textura na tela.
} 

/* void TextureManager::Draw(SDL_Texture *texture, SDL_Rect srcRect, SDL_Rect destRect) {
    
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect); // Renderiza a textura na tela.
} */