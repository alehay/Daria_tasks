.PHONY all clean

all: chapter

clean:
	rm -rf hello *.o


g++ -std=c++17 -I/usr/include/SFML -L/usr/local/lib main.cpp game.cpp database.cpp window.cpp settings.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system -lX11 -lXrandr -lXcursor

	