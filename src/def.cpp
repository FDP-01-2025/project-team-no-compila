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

// Displays the objects obtained by the player during the game
void showObjects(gameData player)
{
    for (int i = 0; i < 12; i++)
    {
        if (player.inventory[i] == 1)
        {
            cout << endl;
            switch (i)
            {
            case key:
                cout << "- Key" << endl;
                break;
            case dagger:
                cout << "- Dagger" << endl;
                break;
            case medallion:
                cout << "- Medallion" << endl;
                break;
            case lantern:
                cout << "- Lantern" << endl;
                break;
            case spell:
                cout << "- Spell" << endl;
                break;
            case map:
                cout << "- Map" << endl;
                break;
            case parchment:
                cout << "- Parchment" << endl;
                break;
            case blessedBottle:
                cout << "- Blessed Bottle" << endl;
                break;
            case enchantment:
                cout << "- Enchantment" << endl;
                break;
            case creatureName:
                cout << "- Creature Name" << endl;
                break;
            }
        }
    }
}

// Main menu where all the main options are available
gameData menu()
{
    // Variable declaration
    int option;
    gameData player;
    // Menu control
    do
    {
        cout << "-----Menu-----" << endl;
        cout << "1. Profile" << endl;
        cout << "2. New game" << endl;
        cout << "3. Saved game" << endl;
        cout << "4. Exit" << endl;
        cout << "5. Credits" << endl;
        cin >> option;
        // Check if the input was invalid (for example, if a letter was entered)
        if (cin.fail())
        {
            // All this makes it so if a letter is entered, it tells them it's incorrect
            cin.clear();            // Clear the error state
            cin.ignore(1000, '\n'); // Discard the incorrect input
            cout << "Invalid option. Enter a number between 1 and 5." << endl;
            option = 0; // Set a value out of range to continue the loop
            continue;
        }

