#include "Player.h"
#include <iostream>
#include <vector>
#include "Game.h"
#include <string>

Player::Player(const std::string name, const bool is_human)
{

    name_ = name;
    is_human_ = is_human;
    points_ = 0;
}

std::string Player::ToRelativePosition(Position other)
{

    Position current = pos_;
    if (current.row == other.row)
    {
        if (other.col == current.col + 1)
        {
            return "Right";
        }
        else
        {
            return "Left";
        }
    }
    else
    {
        if (other.row <= current.row)
        {
            return "Up";
        }
        else
        {
            return "Down";
        }
    }
    return "failed";
}

std::string Player::Stringify()
{
    return name_ + " has " + std::to_string(points_) + " points.";
}
