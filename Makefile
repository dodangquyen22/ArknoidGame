all: compile link

compile:
      
	   g++ -c main.cpp game.cpp menu.cpp GameStateManager.cpp gameover.cpp -Isrc\include  

link:
	   g++ main.o game.o menu.o gameover.o GameStateManager.o -o sfml-app -Lsrc\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
	   
