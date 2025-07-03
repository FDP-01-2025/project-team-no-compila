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
        // Start of switch
        switch (option)
        {
        // Create profile
        case 1:
            do
            {
                cout << "----Select an option----" << endl;
                cout << "1. Profile: " << endl;
                cout << "2. Enter your name: " << endl;
                cout << "3. Exit" << endl;
                cin >> option;
                // Check if the input was invalid (for example, if a letter was entered)
                if (cin.fail())
                {
                    cin.clear();            // Clear the error state
                    cin.ignore(1000, '\n'); // Discard the incorrect input
                    cout << "Invalid option. Enter a number between 1 and 3." << endl;
                    option = 0; // Set a value out of range to continue the loop
                    continue;
                }
                switch (option)
                {
                case 1:
                    // Show the saved profile name
                    {
                        string name;
                        ifstream file("profile.txt");
                        if (file.is_open())
                        {
                            getline(file, name);
                            file.close();
                            cout << "Profile name: " << name << endl;
                        }
                        else
                        {
                            cout << "No profile name saved yet." << endl;
                        }
                        break;
                    }

                    // Enter the profile name and save it
                    {
                        string name;
                        cout << "Enter your name: ";
                        cin >> name;
                        ofstream file("profile.txt");
                        if (file.is_open())
                        {
                            file << name << endl;
                            file.close();
                            cout << "Name saved successfully." << endl;
                        }
                        else
                        {
                            cout << "Error saving the name." << endl;
                        }
                        break;
                    }
                    break;
                case 3:
                    // Exit profile options
                    break;
                default:
                    cout << "Invalid option. Select a valid option (1-2)";
                    break;
                }
            } while (option != 3); // Repeat until one of the options is chosen
            break;

case 2:
            // Create a new game
            cout << "Enter a name for the game: " << endl;
            cin >> player.nameGame;
            cout << "Enter the name of player 1: " << endl;
            cin >> player.player1;
            cout << "Enter the name of player 2: " << endl;
            cin >> player.player2;
            cout << endl;
            player.phase = 1;
            progress(player); // Save progress
            return player;    // Enter the game phases
        case 3:
            // Load the progress of the previously played game
            player = loadProgress();
            cout << endl;
            return player; // Enter the saved game phase
        case 4:
            // Exit the game
            cout << "Thank you for playing." << endl;
            exit(0);
