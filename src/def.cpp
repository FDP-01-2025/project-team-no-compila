#include "header.h"

// Stores the progress of the game
void progress(gameData player)
{
    ofstream fileReading(file);
    if (fileReading.is_open())
    {
        string line;
        fileReading << player.phase << "\n"
                    << player.event << "\n"
                    << player.pass << "\n";
        for (int i = 0; i < 12; i++)
        {
            fileReading << player.inventory[i] << " ";
        }
        fileReading << "\n";
        fileReading << player.nameGame << "\n";
        fileReading << player.player1 << "\n";
        fileReading << player.player2 << "\n";
        fileReading.close();
    }
    else
    {
        cout << "The file could not be opened for reading." << endl;
    }
}

// Loads the previously saved game progress
gameData loadProgress()
{
    gameData player;
    ifstream read(file);
    if (read.is_open())

    {
        read >> player.phase >> player.event >> player.pass;
        for (int i = 0; i < 12; i++)
        {
            read >> player.inventory[i];
        }

        read.ignore();

        getline(read, player.nameGame);
        getline(read, player.player1);
        getline(read, player.player2);
        read.close();

        cout << "\nProgress loaded: Phase " << player.phase << "\n\n";
    }

    else

    {
        cout << "Could not load the game." << endl;

        player.phase = 1;
    }
    return player;
}

