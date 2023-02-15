CXX = g++
CXXFLAGS = -std=c++17 -Wall
CXXGDB = -ggdb

all: main

clean:
	rm main Player.o Board.o Game.o

main: Player.o Board.o Game.o main.cpp
	$(CXX) $(CXXFLAGS) main.cpp Player.o Board.o Game.o -o main

Player.o: Player.cpp
	$(CXX) $(CXXFLAGS) -c Player.cpp

Board.o: Board.cpp
	$(CXX) $(CXXFLAGS) -c Board.cpp

Game.o: Game.cpp
	$(CXX) $(CXXFLAGS) -c Game.cpp
