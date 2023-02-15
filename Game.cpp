#include "Game.h"
#include <iostream>
std::string SquareTypeStringify(SquareType sq)
{
    switch (sq)
    {
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
}

std::vector<Position> Board::GetMoves(Player *p)
{
    std::vector<Position> moves;
    int row = p->get_position().row;
    int col = p->get_position().col;
    if (arr_[row - 1][col] != SquareType::Wall)
    {
        moves.push_back({row - 1, col});
    }
    if (arr_[row + 1][col] != SquareType::Wall)
    {
        moves.push_back({row + 1, col});
    }
    if (arr_[row][col - 1] != SquareType::Wall)
    {
        moves.push_back({row, col - 1});
    }
    if (arr_[row][col + 1] != SquareType::Wall)
    {
        moves.push_back({row, col + 1});
    }
    return moves;
}

bool Board::MovePlayer(Player p, Position pos, std::vector<Player> enemylist)
{
    if (arr_[pos.row][pos.col] == SquareType::Wall)
    {
        return false;
    }
    p->SetPosition(pos);
    SquareType value = arr_[pos.row][pos.col];
    if (value == SquareType::Dots)
    {
        p->ChangePoints(1);
        arr_[pos.row][pos.col] = SquareType::Empty;
        dots_count_--;
    }
    else if (value == SquareType::Treasure)
    {
        p->ChangePoints(10);
        p->setHasTreasure();
        arr_[pos.row][pos.col] = SquareType::Empty;
    }
    else if (value == SquareType::Enemies)
    {
        for (int i = 0; i < enemylist.size(); i++)
        {
            if (enemylist[i]->get_position().row == pos.row && enemylist[i]->get_position().col == pos.col)
            {
                p->ChangePoints(5);
                enemylist[i]->setIsDead(true);
                enemylist[i]->setLives();
            }
        }
    }