#ifndef TRANSFORMCOMPONENTS_HPP
#define TRANSFORMCOMPONENTS_HPP

#include "Configs.hpp"
#include "Components.hpp"
#include "../Vector2D.hpp"

class TransformComponent : public Component
{
public:

    Vector2D position;

    TransformComponent(){
        //xpos = WINDOW_WIDTH/2 - 64;
        //ypos = WINDOW_HEIGHT/2 - 64;
        position.x = WINDOW_WIDTH/2 - 64;
        position.y = WINDOW_HEIGHT/2 - 64;
    }

    TransformComponent(float x, float y){
        position.x = x;
        position.y = y;
    }

    void update() override
    {
        
    }

};





#endif