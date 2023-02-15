#include "Game.h"
#include "Player.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

// Implementation of Board class
Board::Board()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr_[i][j] = SquareType::Empty;
        }
    }
    rows_ = 10;
    cols_ = 10;
}

SquareType Board::get_square_value(Position pos) const
{
    return arr_[pos.row][pos.col];
}

void Board::SetSquareValue(Position pos, SquareType value)
{
    arr_[pos.row][pos.col] = value;
}

std::vector<Position> Board::GetMoves(Player *p)
{
    std::vector<Position> possible_moves;
    int row = p->get_position().row;
    int col = p->get_position().col;
    if (row - 1 >= 0 && arr_[row - 1][col] != SquareType::Wall)
    {
        possible_moves.push_back({row - 1, col});
    }
    if (row + 1 < 10 && arr_[row + 1][col] != SquareType::Wall)
    {
        possible_moves.push_back({row + 1, col});
    }
    if (col - 1 >= 0 && arr_[row][col - 1] != SquareType::Wall)
    {
        possible_moves.push_back({row, col - 1});
    }
    if (col + 1 < 10 && arr_[row][col + 1] != SquareType::Wall)
    {
        possible_moves.push_back({row, col + 1});
    }

    return possible_moves;
}

bool Board::MovePlayer(Player *p, Position pos, std::vector<Player *> enemylist)
{
     if (pos.row < 0 || pos.row >= board_.rows() || pos.col < 0 || pos.col >= board_.cols() || board_.get_square_value(pos) == SquareType::Wall)
    {
        return false;
    }

    // Check if the new position is occupied by another player or an enemy
    for (auto player : players_)
    {
        if (player != p && player->get_position() == pos)
        {
            return false;
        }
    }
    for (auto enemy : enemies_)
    {
        if (enemy->get_position() == pos)
        {
            return false;
        }
    }

    // Update the player's position and the board
    board_.MovePlayer(p, pos, enemies_);
    return true;
}
}

bool Board::MoveEnemy(Player *p, Position pos)
{
    // Check if the new position is within the bounds of the board and not a wall
    if (pos.row < 0 || pos.row >= rows_ || pos.col < 0 || pos.col >= cols_ || arr_[pos.row][pos.col] == SquareType::Wall)
    {
        return false;
    }

    // Update the enemy's position and the board
    arr_[p->get_position().row][p->get_position().col] = SquareType::Empty;
    arr_[pos.row][pos.col] = SquareType::Enemies;
    p->set_previous_position(p->get_position());
    p->set_position(pos);

    return true;
}