#ifndef MAP_HPP
#define MAP_HPP

#include "Game.hpp"
#include <vector>


class Map{

public:

    Map();
    ~Map();

    struct Star{
        int x;
        int y;
        int size;
        int brightness;
        int duration;
    };

    struct Nebulosa{
        bool soma; //somar ou subtrair?
        int brightness;
        int duration;
    };

    struct Cadente{
        bool flag;
        int x, y;
        int velocity;
        //int direcao;    // 0: subindo; 1: direita; 2: descendo; 3: esquerda;
        int cont;
    };

    Nebulosa neb;
    Cadente cadente;

    std::vector <Star> stars;
    //std::vector <Cadente> cadentes;

    void UpdateStars();
    void UpdateFallingStars();

    void LoadMap();
    void DrawMap();

private:

    SDL_Rect src, dest;

    SDL_Texture* backgroundTex;
    SDL_Texture* planet1Tex;
    SDL_Texture* planet2Tex;
    SDL_Texture* planet3Tex;
    SDL_Texture* starsTex;
    SDL_Texture* nebulosaTex;
    SDL_Texture* galaxiaTex;
    SDL_Texture* galaxia2Tex;
    SDL_Texture* ECadenteTex;

    int map[20][25];

};





#endif