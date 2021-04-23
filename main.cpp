#include <iostream>
#include <algorithm>
#include "lands.h"
#include "player.h"
#include "player.cpp"
#include "lands.cpp"
using namespace std;

enum PlayerChoice { NORTH, SOUTH, EAST, WEST };

void clearTerminal() 
{
    for (int i = 0; i < 100; i++)
    {
        cout << endl;
    }
}

bool getPlayerInput(PlayerChoice& playerChoice) 
{
   
    string input;
    cout << "Which direction will you go?" << endl;
    cout << "Enter N, S, E, or W" << endl;
    cin >> input;

    transform(input.begin(), input.end(), input.begin(), ::tolower);

    if (input == "n" || input == "N") 
    {
        playerChoice = NORTH;
    }
    else if (input == "s" || input == "S") 
    {
        playerChoice = SOUTH;
    }
    else if (input == "e" || input == "E") 
    {
        playerChoice = EAST;
    }
    else if (input == "w" || input == "W") 
    {
        playerChoice = WEST;
    }
    else 
    {
        cout << "Invalid input." << endl;
        return false;
    }

    return true;
}

int main()
{
    const unsigned int MAP_SIZE = 20;
    Player player(Player::DEFAULT_HEALTH,
        Player::DEFAULT_HUNGER,
        Player::DEFAULT_THIRST,
        MAP_SIZE / 2, MAP_SIZE / 2);

    //Build Map
    Land* map[MAP_SIZE][MAP_SIZE];
    for (int i = 0; i < MAP_SIZE; i++) 
    {
        for (int j = 0; j < MAP_SIZE; j++) 
        {
            map[i][j] = getRandomLand();
        }
    }

    cout << "You wake up in a " <<
        map[player.getX()][player.getY()]->getShortDescription() <<
        " biome with no memory of how you got there." << endl;

    while (player.isAlive()) 
    {
        clearTerminal();
        player.newTurn();

        // Give description of surroundings
        unsigned int x = player.getX();
        unsigned int y = player.getY();

        cout << map[x][y]->getLongDescription() << endl << endl;
        cout << map[x][y]->visit(player) << endl << endl;

        cout << player.printStats() << endl << endl;

        // TODO: Handle boundry conditions
        cout << "To the north you see a " << map[x][y + 1]->getShortDescription() << endl;
        cout << "To the south you see a " << map[x][y - 1]->getShortDescription() << endl;
        cout << "To the east you see a " << map[x + 1][y]->getShortDescription() << endl;
        cout << "To the west you see a " << map[x - 1][y]->getShortDescription() << endl;

        PlayerChoice playerChoice;
        while (!getPlayerInput(playerChoice));

        switch (playerChoice) {
        case NORTH:
           
            player.setY(player.getY() + 1);
            break;
        case SOUTH:
            player.setY(player.getY() - 1);
            break;
        case EAST:
            player.setX(player.getX() + 1);
            break;
        case WEST:
            player.setX(player.getX() - 1);
            break;
        default:
            cout << "Invalid input found: " << playerChoice << endl;
            break;
        }

    }
    


    return 0;
}