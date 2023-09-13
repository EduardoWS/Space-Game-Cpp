#include "Game.hpp"
#include "TextureManager.hpp"
#include "Map.hpp"
#include "ECS/Components.hpp"
#include "Collision.hpp"


Map* map;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

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

        map = new Map();

        player.addComponent<TransformComponent>();
        player.addComponent<SpriteComponent>("assets/images/spaceships/spaceship3.png");
        player.addComponent<KeyboardController>();
        player.addComponent<ColliderComponent>("player");

        alien.addComponent<TransformComponent>(0, 360);
        alien.addComponent<SpriteComponent>("assets/images/aliens/alien1.png");
        alien.addComponent<ColliderComponent>("Alien");

        isRunning = true;

    }else{
        isRunning = false;
    }

}

void Game::handleEvents(){

    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    
    default:
        break;
    }

}

void Game::update(){
    
    map->UpdateStars();
    map->UpdateFallingStars();

    manager.refresh();
    manager.update();

    if(Collision::AABB(player.getComponent<ColliderComponent>().collider,
                        alien.getComponent<ColliderComponent>().collider))
    {
        player.getComponent<TransformComponent>().scale = 0.5;
        std::cout << "Alien hit!" << "\n";
    }

     
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