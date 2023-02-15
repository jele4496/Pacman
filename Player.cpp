#include "Player.h"

Player::Player(const std::string name, const bool is_human)
    : name_{name}, is_human_{is_human}, points_{0}, has_Treasure_{false}, isDead_{false}, lives_{3}, moves_{0} {}

std::string Player::ToRelativePosition(Position other)
{
    if (other.row < pos_.row && other.col == pos_.col)
    {
        return "up";
    }
    else if (other.row > pos_.row && other.col == pos_.col)
    {
        return "down";
    }
    else if (other.row == pos_.row && other.col < pos_.col)
    {
        return "left";
    }
    else if (other.row == pos_.row && other.col > pos_.col)
    {
        return "right";
    }
    else if (other.row < pos_.row && other.col < pos_.col)
    {
        return "upleft";
    }
    else if (other.row < pos_.row && other.col > pos_.col)
    {
        return "upright";
    }
    else if (other.row > pos_.row && other.col < pos_.col)
    {
        return "downleft";
    }
    else if (other.row > pos_.row && other.col > pos_.col)
    {
        return "downright";
    }
    else
    {
        return "none";
    }
}

std::string Player::Stringify()
{
    return name_ + " has " + std::to_string(points_) + " points.";
}