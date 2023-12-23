all:
	g++ src/include/cpp/*.cpp -I src/include -L src/lib  -o main main.cpp  -lmingw32 -lSDL2main -lSDL2 -g

# *.cpp tells g++ to compile all the cpp files in that directory, -I tells g++ where to look for files that are #included in the cpp directory.