#ifndef COLLISION_HPP
#define COLLISION_HPP

#include <SDL2/SDL.h>

class Collision
{
public:
    static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
};


#endif