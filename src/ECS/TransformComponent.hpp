#ifndef TRANSFORMCOMPONENTS_HPP
#define TRANSFORMCOMPONENTS_HPP

#include "Configs.hpp"
#include "Components.hpp"
#include "../Vector2D.hpp"

class TransformComponent : public Component
{
public:

    Vector2D position;
    Vector2D velocity;

    int height = 64;
    int width = 64;
    float scale = 1.0;

    int speed = 5; // 3



    TransformComponent(){
        //xpos = WINDOW_WIDTH/2 - 64;
        //ypos = WINDOW_HEIGHT/2 - 64;
        position.x = WINDOW_WIDTH/2.0f - 64.0f;
        position.y = WINDOW_HEIGHT/2.0f - 64.0f;
    }

    TransformComponent(float sc)
    {
        position.x = 0.0f;
        position.y = 0.0f;
        scale = sc;
    }
        
    

    TransformComponent(float x, float y){
        position.x = x;
        position.y = y;
    }

    TransformComponent(float x, float y, int w, int h, int sc){
        position.x = x;
        position.y = y;
        width = w;
        height = h;
        scale = sc;
    }

    void init() override
    {
        velocity.x = 0;
        velocity.y = 0;
    }

    void update() override
    {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }

};





#endif