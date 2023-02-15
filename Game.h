#ifndef _GAME_H_
#define _GAME_H_

#include <vector>
#include "Player.h"
#include <string>

// you may change this enum as you need
enum class SquareType { Wall, Dots, Pacman, Treasure, Enemies, Empty, PowerfulPacman, Trap, EnemySpecialTreasure };

// TODO: implement
std::string SquareTypeStringify(SquareType sq);
// Sample implementation:
switch (sq) {
case SquareType::Wall:
	return "Wall";
case SquareType::Dots:
	return "Dots";
case SquareType::Pacman:
	return "Pacman";
case SquareType::Treasure:
	return "Treasure";
case SquareType::Enemies:
	return "Enemies";
case SquareType::Empty:
	return "Empty";
case SquareType::PowerfulPacman:
	return "PowerfulPacman";
case SquareType::Trap:
	return "Trap";
case SquareType::EnemySpecialTreasure:
	return "EnemySpecialTreasure";
default:
	return "Unknown";
}

class Board {
public:
	// // TODO: implement
	Board() : rows_{ 10 }, cols_{ 10 } {
		for (int row = 0; row < rows_; ++row) {
for (int col = 0; col < cols_; ++col) {
if (row == 0 || col == 0 || row == rows_ - 1 || col == cols_ - 1) {
arr_[row][col] = SquareType::Wall;
}
else {
arr_[row][col] = SquareType::Empty;
}
}
}
}
	// // already implemented in line
	int get_rows() const { return rows_; }
int get_cols() const { return cols_; }

	// // TODO: you MUST implement the following functions
	SquareType get_square_value(Position pos) const { return arr_[pos.row][pos.col]; }

	// // set the value of a square to the given SquareType
	void SetSquareValue(Position pos, SquareType value) { arr_[pos.row][pos.col] = value; }

	// // get the possible Positions that a Player/Enemy could move to
	// // (not off the board or into a wall)
	std::vector<Position> GetMoves(Player* p);

	// // Move a player to a new position on the board. Return
	// // true if they moved successfully, false otherwise.
	bool MovePlayer(Player* p, Position pos, std::vector<Player*> enemylist);

    // // Move an enemy to a new position on the board. Return
	// // true if they moved successfully, false otherwise.
    bool MoveEnemy(Player *p, Position pos);

	// // You probably want to implement this
	friend std::ostream& operator<<(std::ostream& os, const Board &b);

private:
	SquareType arr_[10][10];
	int rows_; // might be convenient but not necessary
	int cols_;
	// you may add more fields, as needed
};  // class Board

class Game {
public:
	// TODO: implement these functions
	Game() : board_{ new Board() }, turn_count_{ 0 }, dots_count_{ 0 }, GameOver{ false }

	// // initialize a new game, given one human player and
	// // a number of enemies to generate
	void NewGame(Player *human,std::vector<Player*> enemylist, const int enemies);

	// // have the given Player take their turn
	void TakeTurn(Player *p,std::vector<Player*> enemylist);

	// //have the enemy take turn
	void TakeTurnEnemy(Player *p);

	bool IsGameOver(Player *p);

	// // return true if all pellets have been collected
	bool CheckifdotsOver();

	// // You probably want to implement these functions as well
	// // string info about the game's conditions after it is over
	std::string GenerateReport(Player *p);

	friend std::ostream& operator<<(std::ostream& os, const Game &m);

private:
	Board *board_;
	std::vector<Player *> players_;
	int turn_count_;
    int dots_count_;
    bool GameOver;

	// you may add more fields, as needed

};  // class Game

#endif  // _GAME_H_
