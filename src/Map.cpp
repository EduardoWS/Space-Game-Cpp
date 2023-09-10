#include "Map.hpp"
#include "TextureManager.hpp"



Map::Map(){

    //backgroundTex = TextureManager::LoadTexture("");
    //planetsTex = TextureManager::LoadTexture("");
    starsTex = TextureManager::LoadTexture("assets/images/scenario/star1.png");
    //galaxyTex = TextureManager::LoadTexture("");


    // Aqui você pode gerar estrelas aleatoriamente e adicioná-las ao vetor de estrelas.
    // Vou criar um exemplo simples com 100 estrelas para começar.
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

void Map::LoadMap(){

}

void Map::DrawMap(){

    // Desenhe as estrelas na tela.
    for (const Star& star : stars) {
        // Use o brilho para simular o efeito de piscar.
        SDL_SetTextureAlphaMod(starsTex, star.brightness);
        // Desenhe a estrela na posição (x, y).
        TextureManager::Draw(starsTex, star.x, star.y, star.size, star.size);
    }

}



void Map::UpdateStars() {
    // Atualize o estado das estrelas, como a duração da piscada e a intensidade do brilho.
    for (Star& star : stars) {
        // Reduza a duração da piscada.
        star.duration -= 1;
        if(star.brightness > 0)
            star.brightness -= 1;

        // Se a duração for menor ou igual a zero, reinicie a piscada.
        if (star.duration <= 0) {
            int x = rand() % 1280;
            int y = rand() % 720;
            star.x = x;
            star.y = y;
            star.duration = rand() % 100 + 50; // Duração aleatória entre 50 e 249
            star.brightness = rand() % 256; // Brilho aleatório de 0 a 255
        }
    }
}