#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <iostream>
#include "Player.h"

enum class SquareType
{
    Wall,
    Dots,
    Pacman,
    Treasure,
    Enemies,
    Empty,
    PowerfulPacman,
    Trap,
    EnemySpecialTreasure
};

std::string SquareTypeStringify(SquareType sq);

class Board
{
public:
    Board(const int rows, const int cols);
    std::vector<Position> GetMoves(Player *p);
    bool MovePlayer(Player *p, Position pos, std::vector<Player *> enemylist);
    bool MoveEnemy(Player *p, Position pos);
    int get_dots_count() const { return dots_count_; }
    friend std::ostream &operator<<(std::ostream &os, const Board &b);
    SquareType arr_[100][100];

private:
    int rows_;
    int cols_;
    int dots_count_;
};

class Game
{
public:
    Game();
    void NewGame(Player human, std::vector<Player> enemylist, const int enemies);
    void TakeTurn(Player p, std::vector<Player> enemylist);
    void TakeTurnEnemy(Player &enemy);
    bool IsGameOver(Player *p);
    bool CheckifdotsOver();
    std::string GenerateReport(Player *human);
    friend std::ostream &operator<<(std::ostream &os, const Game &m);

private:
    Board *board_;
    std::vector<Player *> players_;
	std::vector<Player *> enemies_;
	int num_enemies_;
    void PrintBoard();
    int turn_count_;
    int dots_count_;
    bool GameOver;
};

#endif // GAME_H
