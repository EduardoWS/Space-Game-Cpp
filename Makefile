#g++ main.cpp Game.cpp $(pkg-config --cflags --libs sdl2) -o main

CC = g++
CFLAGS = $(shell pkg-config --cflags --libs sdl2)	#-Wall -O2
programa = main

main: main.cpp Game.cpp
	$(CC) $(CFLAGS) -o $(programa) main.cpp Game.cpp

clean:
	rm -f $(programa)

exec:
	$(CC) $(CFLAGS) -o $(programa) main.cpp Game.cpp
	./$(programa)