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
	Board();
	int get_rows() const { return 10; }
	int get_cols() const { return 10; }
	SquareType get_square_value(Position pos) const;
	void SetSquareValue(Position pos, SquareType value);
	std::vector<Position> GetMoves(Player *p);
	bool MovePlayer(Player p, Position pos, std::vector<Player> enemylist);
	bool MoveEnemy(Player *p, Position pos);
	friend std::ostream &operator<<(std::ostream &os, const Board &b);

private:
	SquareType arr_[10][10];
	int rows_;
	int cols_;
};

class Game
{
public:
	Game();
	void NewGame(Player human, std::vector<Player> enemylist, const int enemies);
	void TakeTurn(Player p, std::vector<Player> enemylist);
	void TakeTurnEnemy(Player *p);
	bool IsGameOver(Player *p);
	bool CheckifdotsOver();
	std::string GenerateReport(Player *p);
	friend std::ostream &operator<<(std::ostream &os, const Game &m);

private:
	Board *board_;
	std::vector<Player *> players_;
	int turn_count_;
	int dots_count_;
	bool GameOver;
};

#endif // GAME_H