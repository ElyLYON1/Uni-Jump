CC= g++
FLAGS = -g -Wall -c
INCLUDE_DIR_SDL = #-I/usr/include/SDL2
LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image
EXE = bin/affichagetxt 
CORPS= obj/Couleur.o obj/Dimension.o obj/Position.o obj/Personnage.o obj/Block.o obj/Carte.o obj/WinTxt.o obj/txtJeu.o obj/main.o

#a faire

all : $(EXE)

$(EXE) : $(CORPS)
	$(CC)$(INCLUDE_DIR_SDL) $(CORPS) -o $(EXE)


obj/Carte.o : src/Carte.h src/Carte.cpp
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) src/Carte.cpp -o obj/Carte.o $(LIBS_SDL)


obj/Couleur.o : src/Couleur.h src/Couleur.cpp
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) src/Couleur.cpp -o obj/Couleur.o $(LIBS_SDL)


obj/main.o : src/Block.h src/Carte.h src/Couleur.h src/Dimension.h src/Personnage.h src/Position.h src/main.cpp 
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) src/main.cpp -o obj/main.o $(LIBS_SDL)


obj/Block.o : src/Block.h src/Block.cpp
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) src/Block.cpp -o obj/Block.o $(LIBS_SDL)


obj/Dimension.o : src/Dimension.h src/Dimension.cpp
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) src/Dimension.cpp -o obj/Dimension.o $(LIBS_SDL)


obj/Personnage.o : src/Personnage.h src/Personnage.cpp
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) src/Personnage.cpp -o obj/Personnage.o $(LIBS_SDL)


obj/Position.o : src/Position.h src/Position.cpp
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) src/Position.cpp -o obj/Position.o $(LIBS_SDL)


obj/WinTxt.o : src/WinTxt.h src/WinTxt.cpp
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) src/WinTxt.cpp -o obj/WinTxt.o $(LIBS_SDL)
	

obj/txtJeu.o : src/txtJeu.h src/txtJeu.cpp
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) src/txtJeu.cpp -o obj/txtJeu.o $(LIBS_SDL)

val:
	valgrind -v --leak-check=full --show-reachable=yes ./bin/affichagetxt




clean:
	rm -f  ./obj/* ./bin/*
