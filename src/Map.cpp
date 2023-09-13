#include "Map.hpp"
#include "TextureManager.hpp"



Map::Map(){

    //backgroundTex = TextureManager::LoadTexture("");
    //planetsTex = TextureManager::LoadTexture("");
    starsTex = TextureManager::LoadTexture("assets/images/scenario/star3.png");
    nebulosaTex = TextureManager::LoadTexture("assets/images/scenario/nebulosa1.png");
    planet1Tex = TextureManager::LoadTexture("assets/images/scenario/Planeta1.png");
    planet2Tex = TextureManager::LoadTexture("assets/images/scenario/Planeta2.png");
    planet3Tex = TextureManager::LoadTexture("assets/images/scenario/Planeta3.png");
    galaxiaTex = TextureManager::LoadTexture("assets/images/scenario/galaxia.png");
    galaxia2Tex = TextureManager::LoadTexture("assets/images/scenario/galaxia2.png");
    backgroundTex = TextureManager::LoadTexture("assets/images/scenario/background.png");
    ECadenteTex = TextureManager::LoadTexture("assets/images/scenario/ECadente1.png");

    //ECadente
    // gerar cadentes aleatoriamente e adicioná-las ao vetor de cadentes.
    cadente.y = rand() % 720; // Posição X aleatória na largura da tela
    cadente.x = rand() % 1200 + 700; // Posição Y acima da tela
    cadente.velocity = 50; // Velocidade aleatória
    cadente.flag = true;
    cadente.cont = 0;


    //nebulosa
    neb.duration = rand() % 100 + 50;
    neb.brightness = 50;
    neb.soma = false;

    // gerar estrelas aleatoriamente e adicioná-las ao vetor de estrelas.
    const int numStars = 500;
    
    for (int i = 0; i < numStars; i++) {
        // Gere posições x e y aleatórias para as estrelas.
        int x = rand() % 1280;
        int y = rand() % 720;
        // Defina um tamanho e brilho aleatórios para a estrela.
        int allowedNumbers[] = {1, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 8, 8, 8, 8};
        int index = std::rand() % 15; // 4 porque há 4 números na lista
        int size = allowedNumbers[index];
        //int size = rand() % 10 + 1; // Tamanhos de 1 a 16
        int brightness = rand() % 256; // Brilho de 0 a 255 // padrao -> 256

        // Armazene os valores em uma estrutura temporária e adicione-a ao vetor.
        Star star = { x, y, size, brightness, rand() % 100 + 50 }; // Duração aleatória entre 50 e 149 // padrao -> 100 / 50
        stars.push_back(star);

    }


}

Map::~Map()
{
    SDL_DestroyTexture(starsTex);
    SDL_DestroyTexture(backgroundTex);
    SDL_DestroyTexture(ECadenteTex);
}


void Map::LoadMap(){

}

void Map::DrawMap(){

    
   
    SDL_SetTextureAlphaMod(backgroundTex, neb.brightness);
    TextureManager::Draw(backgroundTex, 0, -50, 1300, 1024);

    SDL_SetTextureAlphaMod(ECadenteTex, 100);
    TextureManager::Draw(ECadenteTex, cadente.x, cadente.y, 256, 30); 

    // gerar nebulosa
    //SDL_SetTextureAlphaMod(nebulosaTex, neb.brightness);
    //TextureManager::Draw(nebulosaTex, 1280/2 - 400, 720/2 - 300, 256, 170);

    //SDL_SetTextureAlphaMod(galaxiaTex, 220);
    //TextureManager::Draw(galaxiaTex, 380, 330, 430, 200);

    //SDL_SetTextureAlphaMod(galaxia2Tex, 150);
    //TextureManager::Draw(galaxia2Tex, 0, 520, 350, 256);

    // gerar planetas
    /* SDL_SetTextureAlphaMod(planet1Tex, 200);
    TextureManager::Draw(planet1Tex, 800, 30, 32, 32);

    SDL_SetTextureAlphaMod(planet2Tex, 200);
    TextureManager::Draw(planet2Tex, 1280/2 + 500, -10, 128, 128);

    SDL_SetTextureAlphaMod(planet3Tex, 200);
    TextureManager::Draw(planet3Tex, 30, 10, 64, 64); */


    // Desenhar as estrelas na tela.
    for (const Star& star : stars) {
        // Use o brilho para simular o efeito de piscar.
        SDL_SetTextureAlphaMod(starsTex, star.brightness);
        // Desenhe a estrela na posição (x, y).
        TextureManager::Draw(starsTex, star.x, star.y, star.size, star.size);
    }

    

}



void Map::UpdateStars() {
    // Atualizar o estado das estrelas, como a duração da piscada e a intensidade do brilho.
    for (Star& star : stars) {
        // Reduzir a duração da piscada.
        star.duration -= 1;
        if(star.brightness > 0)
            star.brightness -= 1;

        // Se a duração for menor ou igual a zero, reinicie a piscada.
        if (star.duration <= 0) {
            //int x = rand() % 1280;
            //int y = rand() % 720;
            //star.x = x;
            //star.y = y;
            star.duration = rand() % 100 + 50; // Duração aleatória entre 50 e 149
            star.brightness = rand() % 256; // Brilho aleatório de 0 a 255
        }
    }

    // nebulosa
    neb.duration -= 1;
    
    if(neb.duration <= 0){
        neb.duration = rand() % 100 + 20;
        if(!neb.soma) neb.brightness -= 1;
        else neb.brightness += 1;
        
        if(neb.brightness == 40){  // menor numero
            neb.soma = true;
        }
        if(neb.brightness == 60){  // maior numero
            neb.soma = false;
        }
        
    }
    
}


void Map::UpdateFallingStars() {
    
    if(cadente.cont >= 250){
        cadente.flag = true;
        cadente.cont = 0;
    }

    if(cadente.flag){
        // Atualize a posição da estrela cadente
        cadente.x -= cadente.velocity;
        

        // Verifique se a cadente cadente saiu da tela na parte inferior
        if (cadente.x < -200) {
            // Recoloque a cadente cadente aleatoriamente na parte superior
            cadente.y = rand() % 715 + 3; 
            cadente.x = rand() % 300 + 1280; 
            cadente.velocity = rand() % 50 + 15; // Velocidade aleatória
            cadente.flag = false;
        }

    }else cadente.cont += 1;
}
