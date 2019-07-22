LIBS= -lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS = -L/PRO2/SFML-2.5.1/lib
CPPFLAGS = -I/PRO2/SFML-2.5.1/include
CXXFLAGS = -Wall -std=c++11
LIBDIR = PRO2/SFML-2.5.1/lib
OBJS = main.o tileMap.o enemy.o entity.o menu.o tower.o healthbar.o player.o

CC = g++
	
main.o: main.cpp
	$(CC) -c main.cpp $(CPPFLAGS) -o main.o

player.o: player.cpp
	$(CC) -c player.cpp $(CPPFLAGS) -o player.o	

healthbar.o: healthbar.cpp
	$(CC) -c healthbar.cpp $(CPPFLAGS) -o healthbar.o

menu.o: menu.cpp
	$(CC) -c menu.cpp $(CPPFLAGS) -o menu.o	

tower.o: tower.cpp
	$(CC) -c tower.cpp $(CPPFLAGS) -o tower.o		

entity.o: entity.cpp
	$(CC) -c entity.cpp $(CPPFLAGS) -o entity.o	

tileMap.o: tileMap.cpp
	$(CC) -c tileMap.cpp $(CPPFLAGS) -o tileMap.o 	

enemy.o: enemy.cpp
	$(CC) -c enemy.cpp $(CPPFLAGS) -o enemy.o 

dll: $(OBJS)
	$(CC) -shared -o mydll.dll $(OBJS) $(LIBS) $(LDFLAGS)

game: main.o
	@echo "** Building the game"
	$(CC) -o game.exe main.o $(LIBS) -lmydll $(LDFLAGS) -L/PRO2/TowerDefense

project: dll game

dll: $(OBJ)
	$(CC) -shared -o mydll.dll $(OBJ) $(LDLIBS) $(SFML_LIBS)