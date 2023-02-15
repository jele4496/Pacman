#include "Player.h"

Player::Player(const std::string name, const bool is_human)
    : name_{name}, is_human_{is_human}, points_{0}, has_Treasure_{false}, isDead_{false}, lives_{3}, moves_{0} {}

std::string Player::get_name() const { return name_; }
int Player::get_points() const { return points_; }
Position Player::get_position() const { return pos_; }
bool Player::is_human() const { return is_human_; }
bool Player::hasTreasure() const { return has_Treasure_; }
bool Player::isDead() const { return isDead_; }
int Player::getLives() const { return lives_; }

void Player::ChangePoints(const int x) { points_ += x; }
void Player::SetPosition(Position pos) { pos_ = pos; }
void Player::setHasTreasure() { has_Treasure_ = true; }

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