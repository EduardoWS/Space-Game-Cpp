#g++ main.cpp Game.cpp $(pkg-config --cflags --libs sdl2) -o main

CC = g++
CFLAGS = $(shell pkg-config --cflags --libs sdl2) -lSDL2_image	#-Wall -O2
programa = main

main: ./src/main.cpp ./src/Game.cpp ./src/TextureManager.cpp
	$(CC) $(CFLAGS) -o $(programa) ./src/main.cpp ./src/Game.cpp ./src/TextureManager.cpp

clean:
	rm -f $(programa)

exec:
	$(CC) $(CFLAGS) -o $(programa) ./src/main.cpp ./src/Game.cpp ./src/TextureManager.cpp
	./$(programa)