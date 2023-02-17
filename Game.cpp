#include "Game.h"
#include <iostream>
#include <vector>
#include "Player.h"

std::string SquareTypeStringify(SquareType sq){
  if(sq==SquareType::Wall){

    return "❎";

  }
  else if(sq==SquareType::Pacman){

    return "😄";
  }
  else if(sq==SquareType::Enemies){

    return "👻";

  }
  else if(sq==SquareType::Treasure){

    return "🎁";

  }
  else if(sq==SquareType::Empty){

    return "🟨";

  }
  return "Didn't work";
}

Board::Board(const int rows, const int cols) : rows_{rows}, cols_{cols}, dots_count_{0}
{
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
        {
            arr_[row][col] = SquareType::Empty;
        }
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

bool Board::MovePlayer(Player *p, Position pos, std::vector<Player *> enemylist)
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
        for (int t = 0; t < enemylist.size(); t++)
        {
            if (enemylist[t]->get_position().row == pos.row && enemylist[t]->get_position().col == pos.col)
            {
                p->ChangePoints(5);
                enemylist[t]->setIsDead(true);
                enemylist[t]->setLives();
            }
        }
    }
    return true;
}

bool Board::MoveEnemy(Player *p, Position pos)
{
    if (arr_[pos.row][pos.col] == SquareType::Wall)
    {
        return false;
    }
    p->SetPosition(pos);
    SquareType value = arr_[pos.row][pos.col];
    if (value == SquareType::Pacman)
    {
        p->ChangePoints(5);
    }
    return true;
}

Game::Game() : board_{nullptr}, GameOver{false} {}

// Check if the game is over. Returns true if the game is over, false otherwise.
bool Game::IsGameOver(Player *p)
{
    if (p->getLives() <= 0)
    {
        GameOver = true;
    }
    else if (dots_count_ == 0)
    {
        GameOver = true;
    }
    return GameOver;
}

// This function simulates a turn taken by an enemy. It randomly selects a move from
// all possible moves, and if it reaches the player, then it reduces player's points
// and lives, and sets the has_Treasure_ flag to false if the player was carrying the treasure.
void Game::TakeTurnEnemy(Player &enemy)
{
    std::vector<Position> moves = board_->GetMoves(&enemy);
    int random_move = rand() % moves.size();
    Position new_pos = moves[random_move];
    board_->MoveEnemy(&enemy, new_pos);
    SquareType value = board_->arr_[new_pos.row][new_pos.col];
    if (value == SquareType::Pacman)
    {
        enemy.ChangePoints(-5);
        players_[0]->ChangePoints(-5);
        players_[0]->setLives();
        if (players_[0]->hasTreasure())
        {
            players_[0]->has_Treasure_ = false;
        }
    }
}

// This function generates a game report for the human player, including the number
// of points they got, and the number of dots remaining on the board.
std::string Game::GenerateReport(Player *human)
{
    std::string result = "Game over! " + human->Stringify() + " Dots remaining: " + std::to_string(dots_count_);
    return result;
}

// This function starts a new game, with the specified human player and enemy list. It
// creates a new board, initializes the players and the enemies, and sets the turn count
// to zero.
void Game::NewGame(Player human, std::vector<Player> enemylist, const int enemies)
{
    board_ = new Board(10, 10);
    players_.push_back(&human);
    for (int i = 0; i < enemies; i++)
    {
        Player *ptr = &enemylist[i];
        players_.push_back(ptr);
        enemies_.push_back(ptr);
    }
    dots_count_ = board_->get_dots_count();
    turn_count_ = 0;
}

// This function simulates a turn taken by a player. It prints the board, asks for a move,
// and updates the player's position based on the move. If the player steps on a dot, then
// their points are updated. If they step on an enemy, then the enemy's lives are reduced.
// If the player steps on a treasure, then they get 10 points and the has_Treasure_ flag is set.
void Game::TakeTurn(Player p, std::vector<Player> enemylist)
{
    std::cout << *board_ << std::endl;
    std::vector<Position> moves = board_->GetMoves(&p);
    std::cout << p.Stringify() << std::endl;
    std::cout << "Possible moves:";
    for (auto m : moves)
    {
        std::cout << " (" << m.row << "," << m.col << ")";
    }
    std::cout << std::endl;
    std::cout << "Enter a move (row col):";
    int row, col;
    std::cin >> row >> col;
}

std::ostream &operator<<(std::ostream &os, const Board &b)
{
    for (int row = 0; row < b.rows_; ++row)
    {
        for (int col = 0; col < b.cols_; ++col)
        {
            os << SquareTypeStringify(b.arr_[row][col]) << " ";
        }
        os << std::endl;
    }
    return os;
}

