#include "Game.hpp"
#include "TextureManager.hpp"
#include "Map.hpp"
#include "ECS/Components.hpp"


Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& player(manager.addEntity());
auto& alien(manager.addEntity());


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

        player.addComponent<TransformComponent>();
        player.addComponent<SpriteComponent>("assets/images/spaceships/spaceship3.png");

        alien.addComponent<TransformComponent>(0,0);
        alien.addComponent<SpriteComponent>("assets/images/aliens/alien1.png");
        
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
                
                break;
            case SDLK_s:
                
                break;
            case SDLK_d:
                
                break;
            case SDLK_a:
                
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
                
             
            default:
                break;
        }
    
    default:
        break;
    }

}

void Game::update(){
    
    manager.refresh();
    manager.update();

    alien.getComponent<TransformComponent>().position.Add(Vector2D(1, 1));
    

     
}

void Game::render(){

    SDL_RenderClear(renderer);      // FIRST

    //É aqui que ficará as coisas para renderizar

    map->DrawMap();
    manager.draw();



    SDL_RenderPresent(renderer);    // LAST
    
}

void Game::clean(){

    //SDL_DestroyTexture(ship->objTexture);
    //SDL_DestroyTexture(shot->objTexture);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    std::cout << "\n\nGame Cleaned!\n\n==================\n\n";

}