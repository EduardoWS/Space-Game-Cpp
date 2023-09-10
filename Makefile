#g++ main.cpp Game.cpp $(pkg-config --cflags --libs sdl2) -o main

CC = g++
CFLAGS = $(shell pkg-config --cflags --libs sdl2) -lSDL2_image

SRC_DIR = ./src
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:.cpp=.o)
programa = main

main: $(OBJS)
	$(CC) $(CFLAGS) -o $(programa) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(programa)

exec: main
	./$(programa)