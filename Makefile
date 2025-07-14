LIB = -lopengl32 -lglfw3 -lgdi32
INC = -I./include -L./libs
OUT = main.exe
SOURCE = glad.o main.cpp $(wildcard src/*.cpp) $(wildcard src/render/*.cpp) $(wildcard src/math/*.cpp)

all: main.exe

main.exe:
	g++ $(INC) $(SOURCE) $(LIB) -o $(OUT)

clear:
	rm $(OUT)