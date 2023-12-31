#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"


GameObject* ship;
GameObject* shot;
GameObject* shot2;
GameObject* shot3;
Map* map;

SDL_Renderer* Game::renderer = nullptr;


Game::Game(){

}

Game::~Game(){

}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen){

    int flags = 0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "\n\nSubsystems Initialised!\n";
        
        //IMG_Init(IMG_INIT_PNG); // Inicializa o SDL_image para trabalhar com PNG

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window){
            std::cout << "\nWindow Created!\n";
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            std::cout << "\nRenderer Created!\n";
        }

        /* SDL_Surface *tmpSurface = IMG_Load("assets/images/spaceships/spaceship1-2.png");
        spaceshipTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
        SDL_FreeSurface(tmpSurface); */

        ship = new GameObject("assets/images/spaceships/spaceship3.png", 1);
        ship->dir_ship = 0;
        shot = new GameObject("assets/images/guns/tiro1.png", 2);
        shot2 = new GameObject("assets/images/guns/tiro1.png", 2);
        shot3 = new GameObject("assets/images/guns/tiro1.png", 2);
        shot->shot_flag = -1;
        shot2->shot_flag = -1;
        shot3->shot_flag = -1;
        map = new Map();
        
        isRunning = true;

    }else{
        isRunning = false;
    }

}

void Game::handleEvents(){

    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
            case SDLK_w:
                ship->setRotationAngle(0.0);
                ship->dir_ship = 0;
                //ship->getDestRect().y -= 10;
                //destRect.y -= 10;
                break;
            case SDLK_s:
                ship->setRotationAngle(180.0);
                ship->dir_ship = 2;
                //ship->getDestRect().y += 10;
                //destRect.y += 10;
                break;
            case SDLK_d:
                ship->setRotationAngle(90.0);
                ship->dir_ship = 1;
                //ship->getDestRect().x += 10;
                //destRect.x += 10;
                break;
            case SDLK_a:
                ship->setRotationAngle(270.0);
                ship->dir_ship = 3;
                //ship->getDestRect().x -= 10;
                //destRect.x -= 10;
                break;
            /* case SDLK_e:
                rotationAngle = 45.0; 
                destRect.x += 8;
                destRect.y -= 6;
                break;
            case SDLK_q:
                rotationAngle = 315.0; 
                destRect.x -= 8;
                destRect.y -= 6;
                break; */
            case SDLK_SPACE:
                if (shot->shot_flag == -1) { // Verifique se já não está atirando
                    shot->shot_flag = ship->dir_ship;
                    shot->setRotationAngle(ship->getRotationAngle());
                    // Redefina a posição inicial do tiro
                    shot->getDestRect().x = ship->getDestRect().x;
                    shot->getDestRect().y = ship->getDestRect().y;
                }else if (shot2->shot_flag == -1) { // Verifique se já não está atirando
                    shot2->shot_flag = ship->dir_ship;
                    shot2->setRotationAngle(ship->getRotationAngle());
                    // Redefina a posição inicial do tiro
                    shot2->getDestRect().x = ship->getDestRect().x;
                    shot2->getDestRect().y = ship->getDestRect().y;

                }else if (shot3->shot_flag == -1) { // Verifique se já não está atirando
                    shot3->shot_flag = ship->dir_ship;
                    shot3->setRotationAngle(ship->getRotationAngle());
                    // Redefina a posição inicial do tiro
                    shot3->getDestRect().x = ship->getDestRect().x;
                    shot3->getDestRect().y = ship->getDestRect().y;
                }
             
            default:
                break;
        }
    
    default:
        break;
    }

}

void Game::update(){
    //cont++;
    //std::cout << cont << "\n";

    //ship->Update();
    map->UpdateStars();
    map->UpdateFallingStars();

    if(shot->shot_flag>=0){
        shot->Update();
    }

    if(shot2->shot_flag>=0){
        shot2->Update();
    }

    if(shot3->shot_flag>=0){
        shot3->Update();
    }

     
}

void Game::render(){

    SDL_RenderClear(renderer);      // FIRST

    //É aqui que ficará as coisas para renderizar

    map->DrawMap();

    
    if(shot->shot_flag>=0){
        shot->Render();
    }
    if(shot2->shot_flag>=0){
        shot2->Render();
    }
    if(shot3->shot_flag>=0){
        shot3->Render();
    }

    ship->Render();


    SDL_RenderPresent(renderer);    // LAST
    
}

void Game::clean(){

    SDL_DestroyTexture(ship->objTexture);
    SDL_DestroyTexture(shot->objTexture);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    std::cout << "\n\nGame Cleaned!\n\n==================\n\n";

}