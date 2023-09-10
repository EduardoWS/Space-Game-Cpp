#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Game.hpp"

class GameObject{

public:
    GameObject(const char *texturesheet, float scale=1);
    ~GameObject();

    SDL_Texture *objTexture;
    bool shot_flag;
    float shot_speed;
    int centerX, centerY;

    float getRotationAngle() const {
        return rotationAngle;
    }
    void setRotationAngle(float angle) {
        rotationAngle = angle;
    }

    SDL_Rect &getDestRect(){
        return destRect;
    }
    void setDestRect(SDL_Rect rect) {
        destRect = rect;
    }

    void Update();
    void Render();

private:

    int xpos;
    int ypos;

    
    //SDL_Rect srcRect, destRect;

    // Variáveis relacionadas à nave e ao tiro
    SDL_Rect destRect;
    float rotationAngle;


    int imgWidth, imgHeight;
    

};




#endif