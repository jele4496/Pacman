#include "Game.h"
#include <iostream>

int main()
{
    Player *human = new Player("Player1", true);
    std::vector<Player *> enemylist;
    for (int i = 0; i < 3; i++)
    {
        enemylist.push_back(new Player("Enemy" + std::to_string(i + 1), false));
    }
    Game game;
    game.NewGame(human, enemylist, 3);
    while (!game.IsGameOver(human))
    {
        game.TakeTurn(human, enemylist);
        for (int i = 0; i < enemylist.size(); i++)
        {
            if (!enemylist[i]->isDead())
            {
                game.TakeTurnEnemy(enemylist[i]);
            }
        }
    }
    std::cout << game.GenerateReport(human) << std::endl;
    return 0;
}