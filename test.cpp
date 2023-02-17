#include <iostream>
#include <vector>
#include "Game.h"
#include "Player.h"

int main()
{
    // Create a human player and an enemy list
    Player human("Player1", true);
    std::vector<Player> enemylist;
    for (int i = 0; i < 3; i++)
    {
        enemylist.push_back(Player("Enemy" + std::to_string(i + 1), false));
    }

    // Create a new game and start playing
    Game game;
    game.NewGame(human, enemylist, 3);
    while (!game.IsGameOver(&human))
    {
        game.TakeTurn(human, enemylist);
        for (int i = 0; i < enemylist.size(); i++)
        {
            if (!enemylist[i].isDead())
            {
                game.TakeTurnEnemy(enemylist[i]);
            }
        }
    }

    // Print the final report
    std::cout << game.GenerateReport(&human) << std::endl;

    return 0;
}
