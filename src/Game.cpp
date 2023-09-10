#include "Game.hpp"
#include "TextureManager.hpp"

SDL_Texture *spaceshipTex, *tiroTex;
SDL_Rect destRect, destRect_tiro;
int flags;
float ship_scale = 2;
float tiro_scale = 1;
float rotationAngle = 0.0;

int imgWidth, imgHeight;
int tiro_Width, tiro_Height;

int centerX, centerY;


Game::Game(){
    tiro_flag = false;
}

Game::~Game(){

}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen){

    flags = 0;
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

        //spaceshipTex = IMG_LoadTexture(renderer, "assets/images/spaceships/spaceship1-2.png");
        //tiroTex = IMG_LoadTexture(renderer, "assets/images/guns/tiro1.png");

        spaceshipTex = TextureManager::LoadTexture("assets/images/spaceships/spaceship1-2.png", renderer);
        tiroTex = TextureManager::LoadTexture("assets/images/guns/tiro1.png", renderer);

        SDL_QueryTexture(spaceshipTex, NULL, NULL, &imgWidth, &imgHeight);
        SDL_QueryTexture(tiroTex, NULL, NULL, &tiro_Width, &tiro_Height);

        centerX = (1280 - static_cast<int>(imgWidth * ship_scale)) / 2;
        centerY = (720 - static_cast<int>(imgHeight * ship_scale)) / 2;
        destRect = { centerX, centerY, static_cast<int>(imgWidth * ship_scale), static_cast<int>(imgHeight * ship_scale) };
        destRect_tiro = { centerX+22, centerY-10, static_cast<int>(tiro_Width * tiro_scale), static_cast<int>(tiro_Height * tiro_scale) };

        
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
                rotationAngle = 0.0; // Nave apontando para cima
                destRect.y -= 10;
                break;
            case SDLK_s:
                rotationAngle = 180.0; // Nave apontando para baixo
                destRect.y += 10;
                break;
            case SDLK_d:
                rotationAngle = 90.0; // Nave apontando para a direita
                destRect.x += 10;
                break;
            case SDLK_a:
                rotationAngle = 270.0; // Nave apontando para a esquerda
                destRect.x -= 10;
                break;
            case SDLK_e:
                rotationAngle = 45.0; 
                destRect.x += 8;
                destRect.y -= 6;
                break;
            case SDLK_q:
                rotationAngle = 315.0; 
                destRect.x -= 8;
                destRect.y -= 6;
                break;
            case SDLK_SPACE:
                if (!tiro_flag) { // Verifique se já não está atirando
                    tiro_flag = true;
                    destRect_tiro.y = centerY - 10; // Redefina a posição inicial do tiro
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
    destRect.h = 64;
    destRect.w = 64;

    destRect_tiro.h = 16;
    destRect_tiro.w = 16;

    if(tiro_flag){
        destRect_tiro.y -= 20;
    }
    if(destRect_tiro.y <= 0){
        tiro_flag = false;
    }
    
}

void Game::render(){

    SDL_RenderClear(renderer);      // FIRST

    //É aqui que ficará as coisas para renderizar

    //SDL_RenderCopy(renderer, spaceshipTex, NULL, NULL);
    /* centerX = (1280 - static_cast<int>(imgWidth * ship_scale)) / 2;
    centerY = (720 - static_cast<int>(imgHeight * ship_scale)) / 2;
    destRect = { centerX, centerY, static_cast<int>(imgWidth * ship_scale), static_cast<int>(imgHeight * ship_scale) }; */

    // Defina o ponto de rotação no centro da nave
    SDL_Point pivot = { static_cast<int>(imgWidth * ship_scale) / 2, static_cast<int>(imgHeight * ship_scale) / 2 };
    
    if(tiro_flag){
        SDL_RenderCopyEx(renderer, tiroTex, NULL, &destRect_tiro, rotationAngle, &pivot, SDL_FLIP_NONE);
    }

    // Renderize a textura na tela com o ângulo de rotação
    SDL_RenderCopyEx(renderer, spaceshipTex, NULL, &destRect, rotationAngle, &pivot, SDL_FLIP_NONE);

    



    SDL_RenderPresent(renderer);    // LAST
    
}

void Game::clean(){

    SDL_DestroyTexture(spaceshipTex);
    SDL_DestroyTexture(tiroTex);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    std::cout << "\n\nGame Cleaned!\n\n==================\n\n";

}