CXX = g++
CXXFLAGS = -std=c++17 -Wall
CXXGDB = -ggdb

all: main test

clean:
	rm main test Player.o Game.o test.o

main: Player.o Game.o main.cpp
	$(CXX) $(CXXFLAGS) main.cpp Player.o Game.o -o main

test: Player.o Game.o test.o
	$(CXX) $(CXXFLAGS) test.o Player.o Game.o -o test

Player.o: Player.cpp
	$(CXX) $(CXXFLAGS) -c Player.cpp

Game.o: Game.cpp
	$(CXX) $(CXXFLAGS) -c Game.cpp

test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c test.cpp
