#g++ main.cpp $(pkg-config --cflags --libs sdl2) -lSDL2_image


# Nome do seu programa
PROG = main

# Compilador e opções de compilação
CXX = g++
CXXFLAGS = -std=c++11
LDLIBS = $(shell pkg-config --cflags --libs sdl2) -lSDL2_image

# Fontes e objetos
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(PROG) $(OBJS) $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(PROG) $(OBJS)
