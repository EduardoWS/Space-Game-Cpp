#include "GameObject.hpp"
#include "TextureManager.hpp"



GameObject::GameObject(const char *texturesheet, float scale){

    
    objTexture = TextureManager::LoadTexture(texturesheet);

    shot_speed = 10;
    shot_flag = false;

    rotationAngle = 0.0;

    SDL_QueryTexture(objTexture, NULL, NULL, &imgWidth, &imgHeight);
    imgWidth = imgWidth * scale;
    imgHeight = imgHeight * scale;
    centerX = (1280 - static_cast<int>(imgWidth)) / 2;
    centerY = (720 - static_cast<int>(imgHeight)) / 2;
    destRect = { centerX, centerY, static_cast<int>(imgWidth), static_cast<int>(imgHeight) };

    

}

void GameObject::Update(){

    //destRect.h = scale;
    //destRect.w = scale;

    

    switch (shot_flag)
    {
    case 0:
        destRect.y -= shot_speed;
        if(destRect.y < -64){
            shot_flag = -1;
        }
        break;

    case 1:
        destRect.x += shot_speed;
        if(destRect.x > 1344){
            shot_flag = -1;
        }
        break;

    case 2:
        destRect.y += shot_speed;
        if(destRect.y > 784){
            shot_flag = -1;
        }
        break;

    case 3:
        destRect.x -= shot_speed;
        if(destRect.x < -64){
            shot_flag = -1;
        }
        break;
    
    default:
        break;
    }
    

}

void GameObject::Render(){

    // Defina o ponto de rotação no centro da nave
    SDL_Point pivot = { static_cast<int>(imgWidth) / 2, static_cast<int>(imgHeight) / 2 };
    
    // Renderize a textura na tela com o ângulo de rotação
    SDL_RenderCopyEx(Game::renderer, objTexture, NULL, &destRect, rotationAngle, &pivot, SDL_FLIP_NONE);

}
