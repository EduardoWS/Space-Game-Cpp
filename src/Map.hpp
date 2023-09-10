#ifndef MAP_HPP
#define MAP_HPP

#include "Game.hpp"
#include <vector>


class Map{

public:

    Map();
    ~Map();

    //std::vector <Star> stars;

    struct Star{
        int x;
        int y;
        int size;
        int brightness;
        int duration;
    };

    std::vector <Star> stars;

    void UpdateStars();

    void LoadMap();
    void DrawMap();

private:

    SDL_Rect src, dest;

    SDL_Texture* backgroundTex;
    SDL_Texture* planetsTex;
    SDL_Texture* starsTex;
    SDL_Texture* galaxyTex;

    int map[20][25];

};





#endif