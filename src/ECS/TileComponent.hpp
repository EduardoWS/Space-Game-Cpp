#ifndef TILECOMPONENT_HPP
#define TILECOMPONENT_HPP

#include "ECS.hpp"
#include "TransformComponent.hpp"
#include "SpriteComponent.hpp"
#include <SDL2/SDL.h>


class TileComponent : public Component
{
public:
    TransformComponent *transform;
    SpriteComponent *sprite;

    SDL_Rect tileRect;
    int tileID;
    char* path;

    TileComponent() = default;

    TileComponent(int x, int y, int w, int h, int id)
    {
        tileRect.x = x;
        tileRect.y = y;
        tileRect.w = w;
        tileRect.h = h;
        tileID = id;

        switch (tileID)
        {
        case 0:
            path = "assets/images/aliens/alien1.png";
            break;
        case 1:
            path = "assets/tiles/dirt.png";
            break;
        case 2:
            path = "assets/tiles/water.png";
            break;
        
        default:
            break;
        }
    }

    void init() override
    {
        entity->addComponent<TransformComponent>(tileRect.x, tileRect.y, tileRect.w, tileRect.h, 1);
        transform = &entity->getComponent<TransformComponent>();

        entity->addComponent<SpriteComponent>(path);
        sprite = &entity->getComponent<SpriteComponent>();
    }





};





#endif