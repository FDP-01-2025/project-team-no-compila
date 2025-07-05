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

        case 5:
            // Credits of the game's creators
            cout << "The Mansion of Blackthorn" << endl;
            cout << "A game created by brilliant minds in the shadows." << endl;
            cout << "Creators:" << endl;
            cout << "Jose Ariel Álvarez Morales 00034725" << endl;
            cout << "Diego Gabriel Bonilla Comandari 00147325" << endl;
            cout << "Erick Jose Claros Lopez 00071125" << endl;
            cout << "Angel Leonel Choto Garcia 00185725" << endl;
            cout << "Thank you for playing. But remember: In Blackthorn, the shadows are always watching." << endl;
            cout << endl;
            break;
        default:
            cout << "Invalid option. Select a valid option (1-5) " << endl;
            break;
        }
    } while (option != 4); // Repeat until one of the options is chosen
    return player;
}
// Phase 1
void phase1(gameData &player)
{
    int option;
    int &phase = player.phase;
    int &event = player.event;
    int &pass = player.pass;
    // Randomly choose events
    if (event < 1 || event > 3)
    {
        event = rand() % 3 + 1;
        progress(player);
    }
    // Start of switch
    switch (event)
    {
    case 1:
    {
        // Event 1
        cout << endl;
        cout << "Entering the Blackthorn Mansion" << endl;
        cout << "-----Phase 1-----" << endl;
        cout << "The storm hits the rusty door, which opens with a chilling creak. The ";
        cout << "storm illuminates the imposing Blackthorn Mansion for seconds. On the damp floor, an old ";
        cout << "metal box rests in front of a dusty portrait whose face seems to follow your movements." << endl;

do
        {
            cout << endl;
            cout << "Inventory: " << endl;
            showObjects(player);
            cout << endl;
            cout << "PLAYER 1: " << player.player1 << endl;
            cout << "Choose an option: " << endl;
            cout << "1) Force open the metal box" << endl;
            cout << "2) Inspect the portrait for clues" << endl;
            cout << "3) Close your eyes and listen to the whispers" << endl;
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
            // Start of switch for case 1, player 1
            switch (option)
            {
            case 1:
                cout << "- You find an old iron key (useful later)." << endl;
                player.inventory[key] = 1;
                cout << endl;
                break;
            case 2:
                cout << "- You discover a partial map of the mansion behind the painting." << endl;
                player.inventory[map] = 1;
                cout << endl;
                break;
            case 3:
                cout << "- The whispers warn you about 'the cursed basement door'." << endl;
                cout << endl;
                break;
            } // Ends the switch for case 1, player 1
        } while (option < 1 || option > 3); // Repeat until an option is chosen
        pass = 1;
        progress(player); // Save progress

        
do
        {
            cout << endl;
            cout << "Inventory: " << endl;
            showObjects(player);
            cout << endl;
            cout << "PLAYER 2: " << player.player2 << endl;
            cout << "Choose an option: " << endl;
            cout << "1) Follow the footprints that disappear into the darkness" << endl;
            cout << "2) Explore a piece of furniture with strange indentations" << endl;
            cout << "3) Observe the shadows that seem to move" << endl;
            cin >> option;
            // Start of switch for case 1, player 2
            switch (option)
            {
            case 1:
                cout << "- You discover a hidden trapdoor under the carpet." << endl;
                cout << endl;
                break;
            case 2:
                cout << "- You find a strange medallion." << endl;
                player.inventory[medallion] = 1;
                cout << endl;
                break;
            case 3:
                cout << "- You perceive a ghostly figure pointing north." << endl;
                cout << endl;
                break;
            } // Ends the switch for case 1, player 2
            pass = 2;
            phase = 2;
            event = 0;
            progress(player); // Save progress
        } while (option < 1 || option > 3); // Repeat until an option is chosen
        break;
    }

    case 2:
    {
        // Event 2
        cout << "Entering the Blackthorn Mansion" << endl;
        cout << "-----Phase 1-----" << endl;
        cout << "As you advance, the air becomes denser. The walls seem to pulse, as if the house were alive. ";
        cout << "A clock strikes midnight, but its hands turn backward. A dead crow hangs from the ceiling by a broken rope. ";
        cout << "A cracked mirror shows something that the eye cannot understand." << endl;
        do
        {
            cout << endl;
            cout << "Inventory: " << endl;
            showObjects(player);
            cout << endl;
            cout << "PLAYER 1: " << player.player1 << endl;
            cout << "Choose an option: " << endl;
            cout << "1) Try to light a lighter" << endl;
            cout << "2) Inspect the clock" << endl;
            cout << "3) Examine the broken mirror" << endl;
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
            // Start of switch for case 2, player 1
            switch (option)
            {
            case 1:
                cout << "- The light reveals arcane symbols drawn in blood." << endl;
                cout << endl;
                break;
            case 2:
                cout << "- Inside there is a secret compartment with a small bottle of protective essence." << endl;
                player.inventory[blessedBottle] = 1;
                cout << endl;
                break;
            case 3:
                cout << "- You find an old iron key (useful later)." << endl;
                player.inventory[key] = 1;
                cout << endl;
                break;
            } // Ends the switch for case 2, player 1
        } while (option < 1 || option > 3); // Repeat until an option is chosen
        pass = 1;
        progress(player); // Save progress
        do
        {
            cout << endl;
            cout << "Inventory: " << endl;
            showObjects(player);
            cout << endl;
            cout << "PLAYER 2: " << player.player2 << endl;
            cout << "Choose an option: " << endl;
            cout << "1) Find a lantern" << endl;
            cout << "2) Listen carefully to the laments" << endl;
            cout << "3) Investigate the dead crow" << endl;
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
            // Start of switch for case 2, player 2
            switch (option)
            {
            case 1:
                cout << "- You find an old lantern with enough charge for later." << endl;
                player.inventory[lantern] = 1;
                cout << endl;
                break;
            case 2:
                cout << "- The voices warn about 'the ritual of the three keys'." << endl;
                cout << ".........Key........Parchment..........medallion......." << endl;
                cout << endl;
                break;
            case 3:
                cout << "- You find an ancient parchment with instructions to neutralize lesser entities." << endl;
                player.inventory[parchment] = 1;
                cout << endl;
                break;
            } // Ends the switch for case 2, player 2
            pass = 2;
            phase = 2;
            event = 0;
            progress(player); // Save progress
        } while (option < 1 || option > 3); // Repeat until an option is chosen
        break;
    }

case 3:
    {
        // Event 3
        cout << "Entering the Blackthorn Mansion" << endl;
        cout << "-----Phase 1-----" << endl;
        cout << "The house creaks and groans. A gust of wind knocks a book open down the hallway. ";
        cout << "In the background, a door slams shut violently, as if pushed by invisible hands." << endl;
        do
        {
            cout << endl;
            cout << "Inventory: " << endl;
            showObjects(player);
            cout << endl;
            cout << "PLAYER 1: " << player.player1 << endl;
            cout << "Choose an option: " << endl;
            cout << "1) Chase the flying book" << endl;
            cout << "2) Try to force the closed door" << endl;
            cout << "3) Step back to find another safe route" << endl;
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
            // Start of switch for case 3, player 1
            switch (option)
            {
            case 1:
                cout << "- You find an old iron key (useful later)." << endl;
                player.inventory[key] = 1;
                cout << endl;
                break;
            case 2:
                cout << "- You find resistance, but manage to open a hidden passage." << endl;
                cout << endl;
                break;
            case 3:
                cout << "- You find a protective symbol on the ground that activates a seal." << endl;
                cout << endl;
                break;
            } // Ends the switch for case 3, player 1
        } while (option < 1 || option > 3); // Repeat until an option is chosen
        pass = 1;
        progress(player); // Save progress

do
        {
            cout << endl;
            cout << "Inventory: " << endl;
            showObjects(player);
            cout << endl;
            cout << "PLAYER 2: " << player.player2 << endl;
            cout << "Choose an option: " << endl;
            cout << "1) Run after your partner" << endl;
            cout << "2) Investigate the nearby collapsed room" << endl;
            cout << "3) Analyze the writings on the walls" << endl;
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
            // Start of switch for case 3, player 2
            switch (option)
            {
            case 1:
                cout << "- You become stronger as a team." << endl;
                cout << endl;
                break;
            case 2:
                cout << "- You discover the remains of ancient explorers (warning)." << endl;
                cout << endl;
                break;
            case 3:
                cout << "- You learn a spell to weaken entities." << endl;
                player.inventory[enchantment] = 1;
                cout << endl;
                break;
            } // Ends the switch for case 3, player 2
            cout << "-------End of Phase 1-------" << endl;
            cout << endl;
        } while (option < 1 || option > 3); // Repeat until an option is chosen
        break;
    }
        // Ends switch
    }
    cout << "Auto-saving game " << endl;
    cout << endl;
    // Auto-save after each event
    pass = 2;
    phase = 2;
    event = 0;
    progress(player);
    return;
}

// Phase 2
void phase2(gameData &player)
{
    int option;
    int &phase = player.phase;
    int &event = player.event;
    int &pass = player.pass;
    // Randomly choose the event
    if (event < 1 || event > 3)
    {
        event = rand() % 3 + 1;
        progress(player); // Save progress
    }
    // Start of switch
    switch (event)
    {
    case 1:
    {
        // Event 1
        cout << endl;
        cout << "-----PHASE 2: Cursed Library-----" << endl;
        cout << "A giant library stretches before you. The books whisper. ";
        cout << "Some open by themselves, revealing illegible text. A staircase creaks, ";
        cout << "as if someone invisible is climbing. In the center, an open book. ";
        cout << "on a pedestal radiates energy." << endl;
        do
        {
            cout << endl;
            cout << "Inventory: " << endl;
            showObjects(player);
            cout << endl;
            cout << "PLAYER 1: " << player.player1 << endl;
            cout << "Choose an option: " << endl;
            cout << "1) Examine the book on the pedestal" << endl;
            cout << "2) Go up the stairs" << endl;
            cout << "3) Keep your distance as a precaution" << endl;
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
            // Start of switch for case 1, player 1
            switch (option)
            {
            case 1:
                cout << "- You obtain a key spell for the future." << endl;
                player.inventory[spell] = 1; // Save obtained item
                cout << endl;
                break;
            case 2:
                cout << "- You find a strange medallion." << endl;
                player.inventory[medallion] = 1; // Save obtained item
                cout << endl;
                break;
            case 3:
                cout << "- You avoid the automatic curse of the pedestal." << endl;
                cout << endl;
                break;
            } // Ends the switch for case 1, player 1
        } while (option < 1 || option > 3); // Repeat until an option is chosen
        pass = 1;
        progress(player); // Save progress

do
        {
            cout << endl;
            cout << "Inventory: " << endl;
            showObjects(player);
            cout << endl;
            cout << "PLAYER 2: " << player.player2 << endl;
            cout << "Choose an option: " << endl;
            cout << "1) Examine the floating books" << endl;
            cout << "2) Try to turn off the floating lights" << endl;
            cout << "3) Find hidden symbols in the structure" << endl;
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
            // Start of switch for case 2, player 2
            switch (option)
            {
            case 1:
                cout << "- I discover notes from the ancient owners." << endl;
                cout << endl;
                break;
            case 2:
                cout << "- I get a break from the negative energies." << endl;
                cout << endl;
                break;
            case 3:
                cout << "- I find ancient symbols that help open closed doors." << endl;
                cout << endl;
                break;
            } // Ends the switch for case 2, player 2
            pass = 2;
            phase = 3;
            event = 0;
            progress(player); // Save progress
        } while (option < 1 || option > 3); // Repeat until an option is chosen
        break;
    }
case 2:
    {
        // Event 2
        cout << endl;
        cout << "-----PHASE 2: Cursed Library-----" << endl;
        cout << "A deep crack opens in the floor. A dark tentacle emerges, ";
        cout << "trying to drag everything it finds. The organ music begins to play from above." << endl;
        do
        {
            cout << endl;
            cout << "Inventory: " << endl;
            showObjects(player);
            cout << endl;
            cout << "PLAYER 1: " << player.player1 << endl;
            cout << "Choose an option: " << endl;
            cout << "1) Fight the tentacle" << endl;
            cout << "2) Find the source of the music" << endl;
            cout << "3) Run between the shelves" << endl;
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
            // Start of switch for case 2, player 1
            switch (option)
            {
            case 1:
                cout << "- You manage to injure it and buy time." << endl;
                cout << endl;
                break;
            case 2:
                cout << "- You find a strange medallion." << endl;
                player.inventory[medallion] = 1; // Save obtained item
                cout << endl;
                break;
            case 3:
                cout << "- You find an alternative corridor." << endl;
                cout << endl;
                break;
            } // Ends the switch for case 2, player 1
        } while (option < 1 || option > 3); // Repeat until an option is chosen
        pass = 1;
        progress(player); // Save progress


