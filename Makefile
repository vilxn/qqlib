rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

LIB = -lopengl32 -lglfw3 -lgdi32
INC = -I./include -L./libs
OUT = main.exe
SOURCE = main.cpp $(call rwildcard,./src/,*.cpp *.o)

all: main.exe

main.exe:
	g++ $(INC) $(SOURCE) $(LIB) -o $(OUT)

clear:
	rm $(OUT)