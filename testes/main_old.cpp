#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv){

    SDL_Init(SDL_INIT_EVERYTHING); // sempre bom ter em todo código
    IMG_Init(IMG_INIT_PNG); // Inicializa o SDL_image para trabalhar com PNG

    // Obtenha a resolução do monitor primário
    SDL_DisplayMode dm;
    SDL_GetDesktopDisplayMode(0, &dm);

    //definir proporção da tela:
    int largura_tela = 1280;
    int altura_tela = 720;

    SDL_Window *window = NULL;
    window = SDL_CreateWindow(
        "SPACE",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        largura_tela, altura_tela,
        SDL_WINDOW_SHOWN
        //dm.w, dm.h, // Use a resolução do monitor
        //SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN // Tela cheia
    );

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_Texture *texture = NULL;
    SDL_Surface *surface = IMG_Load("nave1.png"); 

    if (surface == NULL) {
        // Trate o erro de carregamento da imagem, se necessário
        std::cerr << "Erro ao carregar a imagem: " << IMG_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface); // Libere a superfície após criar a textura

    // Obtenha as dimensões da imagem
    int imgWidth, imgHeight;
    SDL_QueryTexture(texture, NULL, NULL, &imgWidth, &imgHeight);

    // Defina a escala desejada para a imagem
    float scale = 2; // Ajuste o valor conforme necessário para redimensionar a imagem

    // Coloque a janela em modo de tela inteira
    //SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

    // Ângulo de rotação inicial
    float rotationAngle = 0.0;

    while(true){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){ //clique no fechar janela
                //cout << "Teste\n";
                exit(0);
            }

            // Verifique as teclas pressionadas
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_w:
                        rotationAngle = 0.0; // Nave apontando para cima
                        break;
                    case SDLK_s:
                        rotationAngle = 180.0; // Nave apontando para baixo
                        break;
                    case SDLK_d:
                        rotationAngle = 90.0; // Nave apontando para a direita
                        break;
                    case SDLK_a:
                        rotationAngle = 270.0; // Nave apontando para a esquerda
                        break;
                    case SDLK_e:
                        rotationAngle = 45.0; 
                        break;
                    case SDLK_q:
                        rotationAngle = 315.0; 
                        break;
                    default:
                        break;
                }
            }
        }
        SDL_RenderClear(renderer);




        //int centerX = (dm.w - static_cast<int>(imgWidth * scale)) / 2;
        //int centerY = (dm.h - static_cast<int>(imgHeight * scale)) / 2;
        int centerX = (largura_tela - static_cast<int>(imgWidth * scale)) / 2;
        int centerY = (altura_tela - static_cast<int>(imgHeight * scale)) / 2;
        SDL_Rect destRect = { centerX, centerY, static_cast<int>(imgWidth * scale), static_cast<int>(imgHeight * scale) };
        //SDL_RenderCopyEx(renderer, texture, NULL, &destRect, 0, NULL, SDL_FLIP_NONE);

        // Defina o ponto de rotação no centro da nave
        SDL_Point pivot = { static_cast<int>(imgWidth * scale) / 2, static_cast<int>(imgHeight * scale) / 2 };
        // Renderize a textura na tela com o ângulo de rotação
        SDL_RenderCopyEx(renderer, texture, NULL, &destRect, rotationAngle, &pivot, SDL_FLIP_NONE);





        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit(); // Desliga o SDL_image

    SDL_Quit();



    return 0;
}