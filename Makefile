all: main.o Player.o Board.o Game.o
g++ main.o Player.o Board.o Game.o -o main

main.o: main.cpp
g++ -c main.cpp

Player.o: Player.cpp
g++ -c Player.cpp

Board.o: Board.cpp
g++ -c Board.cpp

Game.o: Game.cpp
g++ -c Game.cpp

clean:
rm -f *.o main