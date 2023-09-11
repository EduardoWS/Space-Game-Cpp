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

    Nebulosa neb;

    std::vector <Star> stars;

    void UpdateStars();

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

    int map[20][25];

};





#endif