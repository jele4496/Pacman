#pragma once

#include <iostream>
#include <vector>
#include "Game.h"

class Board
{
  public:
    Board(const int rows, const int cols);
    std::vector<Position> GetMoves(Player *p);
    bool MovePlayer(Player *p, Position pos, std::vector<Player *> enemylist);
    bool MoveEnemy(Player *p, Position pos);
    int get_dots_count() const { return dots_count_; }
    friend std::ostream &operator<<(std::ostream &os, const Board &b);

  private:
    int rows_;
    int cols_;
    SquareType arr_[100][100];
    int dots_count_;
};
