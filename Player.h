#ifndef _PLAYER_H_
#define _PLAYER_H_

struct Position
{
	int row;
	int col;

	// // already implemented for you!
	bool operator==(const Position &other)
	{
		return row == other.row && col == other.col;
	}
};

class Player
{
public:
	// TODO: implement
	Player(const std::string name, const bool is_human); // constructor
	name_{name}, is_human_{is_human}, points_{0}, has_Treasure_{false}, isDead_{false}, lives_{3}, moves_{0} {};
	// // These are already implemented for you
	std::string get_name() const { return name_; }	   // inline member function
	int get_points() const { return points_; }		   // inline member function
	Position get_position() const { return pos_; }	   // inline member function
	bool is_human() const { return is_human_; }		   // inline member function
	bool hasTreasure() const { return has_Treasure_; } // inline member function
	bool isDead() const { return isDead_; }			   // inline member function
	int getLives() const { return lives_; }

	// // TODO: implement the following functions
	// // You MUST implement the following functions
	void ChangePoints(const int x) { points_ += x; }

	// // set a new position for this player
	void SetPosition(Position pos) { pos_ = pos; }

	// // checks if the player owns a treasure
	void setHasTreasure() { has_Treasure_ = true; }

	// //checks if the enemy is dead
	void setIsDead(bool isdead) { isDead_ = isdead; }

	// //updates the lives for a player
	void setLives() { lives_--; }

	// // You may want to implement these functions as well
	// // ToRelativePosition is a function we used to translate positions
	// // into direction s relative to the player (up, down, etc)
	std::string ToRelativePosition(Position other);
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
	// // Convert this player to a string representation of their name and points
	std::string Stringify();

	// // this method should return the number of moves made by the player in this game
	int getMoves() { return moves_; }

	// // update the number of moves in each human player's turn
	void incrementMoves() { moves_++; }

	// You may add other functions as needed/wanted

private:
	std::string name_;
	int points_;
	Position pos_;
	bool is_human_;
	bool has_Treasure_;
	bool isDead_;
	int lives_ = 3;
	int moves_;

	// You may add other fields as needed

}; // class Player

#endif // _PLAYER_H_
