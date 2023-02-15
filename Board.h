#ifndef BOARD_H
#define BOARD_H

#include "Player.h"
#include <vector>

// you may change this enum as you need
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

class Board
{
public:
    // TODO: implement
    Board();
    // already implemented in line
    int get_rows() const { return rows_; }
    int get_cols() const { return cols_; }

    // TODO: you MUST implement the following functions
    SquareType get_square_value(Position pos) const;
    void SetSquareValue(Position pos, SquareType value);
    std::vector<Position> GetMoves(Player *p);
    bool MovePlayer(Player *p, Position pos);

    // You probably want to implement this
    friend std::ostream &operator<<(std::ostream &os, const Board &b);

private:
    SquareType arr_[10][10];
    int rows_;
    int cols_;
    // you may add more fields, as needed
}; // class Board

#endif // BOARD_H