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

        do
        {
            cout << endl;
            cout << "Inventory: " << endl;
            showObjects(player);
            cout << endl;
            cout << "PLAYER 2: " << player.player2 << endl;
            cout << "Choose an option: " << endl;
            cout << "1) Help your partner fight" << endl;
            cout << "2) Cast a spell learned previously" << endl;
            cout << "3) Jump the crack to advance alone" << endl;
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
                cout << "- They strengthen their confidence." << endl;
                cout << endl;
                break;
            case 2:
                cout << "- If you have obtained the item." << endl;
                if (player.inventory[enchantment] == 1)
                {
                    cout << "- Temporarily paralyzes the creature." << endl;
                    player.inventory[enchantment] = 0; // Once used, it is removed from inventory
                    cout << endl;
                }
                else
                {
                    cout << "- You have not learned any enchantment. You cannot help your partner." << endl;
                }
                break;
            case 3:
                cout << "- You find a shortcut, but you will be alone." << endl;
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

    case 3:
    {
        // Event 3
        cout << endl;
        cout << "-----PHASE 2: Cursed Library-----" << endl;
        cout << "A gramophone emits distorted voices. The books begin to levitate and spin in circles. ";
        cout << "The dust forms figures that imitate their movements." << endl;
        do
        {
            cout << endl;
            cout << "Inventory: " << endl;
            showObjects(player);
            cout << endl;
            cout << "PLAYER 1: " << player.player1 << endl;
            cout << "Choose an option: " << endl;
            cout << "1) Destroy the gramophone" << endl;
            cout << "2) Recite a purification spell" << endl;
            cout << "3) Leave without looking back" << endl;
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
                cout << "- You find a strange medallion." << endl;
                player.inventory[medallion] = 1; // Save obtained item
                cout << endl;
                break;
            case 2:
                cout << "- Temporarily calms the energies." << endl;
                cout << endl;
                break;
            case 3:
                cout << "- Avoids direct confrontation." << endl;
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
            cout << "1) Clap imitating the movements" << endl;
            cout << "2) Read a floating book in flight" << endl;
            cout << "3) Search for the roots of the phenomenon in the ceiling" << endl;
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
                cout << "- Gains the sympathy of a spirit that offers guidance." << endl;
                cout << endl;
                break;
            case 2:
                cout << "- Learns the true name of the central creature." << endl;
                player.inventory[creatureName] = 1; // Save obtained item
                cout << endl;
                break;
            case 3:
                cout << "- A secret compartment opens revealing a ceremonial dagger (useful in future confrontations)." << endl;
                player.inventory[dagger] = 1; // Save obtained item
                cout << endl;
                break;
            } // Ends the switch for case 3, player 2
            cout << "-------End of Phase 2-------" << endl;
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
    phase = 3;
    event = 0;
    progress(player);
    return;
}

// Phase 3
void phase3(gameData &player)
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
        cout << "----START OF PHASE 3: The Hall of Portraits----" << endl;
        cout << "They cross a long hallway where dozens of old portraits hang on the walls. ";
        cout << "Their eyes seem to follow every step. Some paintings are torn, others bleed slowly from the corners. ";
        cout << "The air becomes cold." << endl;
        do
        {
            cout << endl;
            cout << "Inventory: " << endl;
            showObjects(player);
            cout << endl;
            cout << "PLAYER 1: " << player.player1 << endl;
            cout << "Choose an option: " << endl;
            cout << "1) Examine a torn portrait and the blood" << endl;
            cout << "2) Touch an intact portrait" << endl;
            cout << "3) Avoid any contact with the paintings" << endl;
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
                cout << "- You discover a familiar face: the previous explorer who disappeared years ago. ";
                cout << "You find his diary with warnings about the 'Primordial Shadow'." << endl;
                cout << ".........If the shadow is released.....the world will be condemned......" << endl;
                cout << endl;
                break;
            case 2:
                cout << "- You find an ancient parchment with instructions to neutralize lesser entities." << endl;
                player.inventory[parchment] = 1; // Save obtained item
                cout << endl;
                break;
            case 3:
                cout << "- You advance without activating the mystical traps in the room." << endl;
                cout << endl;
                break;
            } // Ends the switch for case 1, player 1
            pass = 1;
            progress(player); // Save progress
        } while (option < 1 || option > 3); // Repeat until an option is chosen

        do
        {
            cout << endl;
            cout << "Inventory: " << endl;
            showObjects(player);
            cout << endl;
            cout << "PLAYER 2: " << player.player2 << endl;
            cout << "Choose an option: " << endl;
            cout << "1) Light incense to calm the environment" << endl;
            cout << "2) Recite the true name learned before" << endl;
            cout << "3) Draw protective symbols on the ground" << endl;
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
                cout << "- The atmosphere softens and reduces spiritual aggression for a few minutes." << endl;
                cout << endl;
                break;
            case 2:
                // Condition only if the item has been obtained
                if (player.inventory[creatureName] == 1)
                {
                    cout << "- The paintings whisper secrets of the final ritual." << endl;
                    player.inventory[creatureName] = 0; // Once used, it is removed from inventory
                    cout << endl;
                }
                else
                {
                    cout << "- You do not know the true name of the creature, and the ritual fails." << endl;
                }
                break;
            case 3:
                cout << "- Forms a safe circle to rest momentarily." << endl;
                cout << endl;
                break;
            } // Ends the switch for case 2, player 2
        } while (option < 1 || option > 3); // Repeat until an option is chosen
        cout << "Auto-saving game " << endl;
        cout << endl;
        // Auto-save after each event
        pass = 2;
        phase = 4;
        event = 0;
        progress(player);
        break;
    }

    case 2:
    {
        // Event 2
        cout << endl;
        cout << "-----PHASE 3: The Hall of Portraits-----" << endl;
        cout << "The walls begin to crack, the portraits tremble, and from one of them emerges a trapped spirit ";
        cout << "floating slowly towards them with outstretched hands." << endl;
        do
        {
            cout << endl;
            cout << "Inventory: " << endl;
            showObjects(player);
            cout << endl;
            cout << "PLAYER 1: " << player.player1 << endl;
            cout << "Choose an option: " << endl;
            cout << "1) Speak to him compassionately" << endl;
            cout << "2) Attack with the ceremonial dagger" << endl;
            cout << "3) Return to the library" << endl;
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
                cout << "- The spirit reveals information about a hidden exit, but warns of a guardian ahead." << endl;
                cout << endl;
                break;
            case 2:
                // Condition only if the item has been obtained
                if (player.inventory[dagger] == 1)
                {
                    cout << "- The spirit disappears, but warning signs remain." << endl;
                    cout << endl;
                }
                else
                {
                    cout << "- You do not have the dagger to use. You do no damage but it disappears." << endl;
                }
                break;
            case 3:
                cout << "- You find an ancient parchment with instructions to neutralize lesser entities." << endl;
                player.inventory[parchment] = 1; // Save obtained item
                cout << endl;
                break;
            } // Ends the switch for case 2, player 1
            pass = 1;
            progress(player); // Save progress
        } while (option < 1 || option > 3); // Repeat until an option is chosen
        do
        {
            cout << endl;
            cout << "Inventory: " << endl;
            showObjects(player);
            cout << endl;
            cout << "PLAYER 2: " << player.player2 << endl;
            cout << "Choose an option: " << endl;
            cout << "1) Offer the protective medallion" << endl;
            cout << "2) Sing the learned song" << endl;
            cout << "3) Try to distract it" << endl;
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
                // Condition only if the item has been obtained
                if (player.inventory[medallion] == 1)
                {
                    cout << "- The spirit absorbs the energy, weakening." << endl;
                    player.inventory[medallion] = 0; // Once used, it is removed from inventory
                    cout << endl;
                }
                else
                {
                    cout << "- You do not have any medallion. You cannot do anything." << endl;
                }
                break;
            case 2:
                // Condition only if the item has been obtained
                if (player.inventory[spell] == 1)
                {
                    cout << "- The spirit cries and thanks you before fading away." << endl;
                    player.inventory[spell] = 0; // Once used, it is removed from inventory
                    cout << endl;
                }
                else
                {
                    cout << "- You have not learned any spell. You cannot do anything." << endl;
                }
                break;
            case 3:
                cout << "- They buy time for both to escape to the next room." << endl;
                cout << endl;
                break;
            } // Ends the switch for case 2, player 2
        } while (option < 1 || option > 3); // Repeat until an option is chosen
        cout << "Auto-saving game " << endl;
        cout << endl;
        // Auto-save after each event
        pass = 2;
        phase = 4;
        event = 0;
        progress(player);
        break;
    }

    case 3:
    {
        // Event 3
        cout << endl;
        cout << "----START OF PHASE 3: The Hall of Portraits----" << endl;
        cout << "At the end of the room, a double door slowly opens by itself. Inside, an old-fashioned dining room. ";
        cout << "The plates are set, but the food is rotten. The lamps flicker erratically." << endl;
        do
        {
            cout << endl;
            cout << "Inventory: " << endl;
            showObjects(player);
            cout << endl;
            cout << "PLAYER 1: " << player.player1 << endl;
            cout << "Choose an option: " << endl;
            cout << "1) Check the lamps" << endl;
            cout << "2) Carefully examine the plates" << endl;
            cout << "3) Hit the large central table" << endl;
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
                cout << "- You find an ancient parchment with instructions to neutralize lesser entities." << endl;
                player.inventory[parchment] = 1; // Save obtained item
                cout << endl;
                break;
            case 2:
                cout << "- You discover the symbols engraved on the plates that are part of the exorcism ritual." << endl;
                cout << endl;
                break;
            case 3:
                cout << "- A piercing scream comes from beneath the wood." << endl;
                cout << endl;
                break;
            } // Ends the switch for case 3, player 1
            pass = 1;
            progress(player); // Save progress
        } while (option < 1 || option > 3); // Repeat until an option is chosen

        do
        {
            cout << endl;
            cout << "Inventory: " << endl;
            showObjects(player);
            cout << endl;
            cout << "PLAYER 2: " << player.player2 << endl;
            cout << "Choose an option: " << endl;
            cout << "1) Read old menus" << endl;
            cout << "2) Look under the table" << endl;
            cout << "3) Throw holy water (if you obtained it before)" << endl;
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
                cout << "- The names of the guests reveal: ancient cultists of the mansion." << endl;
                cout << endl;
                break;
            case 2:
                cout << "- You find a strange creature chained that whispers clues about the basement." << endl;
                cout << endl;
                break;
            case 3:
                // Condition only if the item has been obtained
                if (player.inventory[blessedBottle] == 1)
                {
                    cout << "- Completely neutralizes any hidden entity in the room." << endl;
                    player.inventory[blessedBottle] = 0; // Once used, it is removed from inventory
                    cout << endl;
                }
                else
                {
                    cout << "- You do not have any bottle with holy water. You cannot do anything." << endl;
                }
                break;
            } // Ends the switch for case 3, player 2
        } while (option < 1 || option > 3); // Repeat until an option is chosen
    } // Ends switch
    }
    cout << "-------End of Phase 3-------" << endl;
    cout << endl;
    cout << "Auto-saving game " << endl;
    cout << endl;
    // Auto-save after each event
    pass = 2;
    phase = 4;
    event = 0;
    progress(player);
    return;
}

// Phase 4
void phase4(gameData &player)
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
        cout << "----START OF PHASE 4: The Whispering Hall----" << endl;
        cout << "The hallway is narrow and dark. Faceless voices whisper your worst fears. ";
        cout << "The walls seem to move, the clocks at the ends spin forward and backward." << endl;
        do
        {
            cout << endl;
            cout << "Inventory: " << endl;
            showObjects(player);
            cout << endl;
            cout << "PLAYER 1: " << player.player1 << endl;
            cout << "Choose an option: " << endl;
            cout << "1) Sing loudly to block the whispers" << endl;
            cout << "2) Hit the walls" << endl;
            cout << "3) Cover your ears and move quickly" << endl;
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
                cout << "- The voices fade temporarily." << endl;
                cout << endl;
                break;
            case 2:
                cout << "- A secret door opens revealing a direct shortcut." << endl;
                cout << endl;
                break;
            case 3:
                cout << "- You do not discover any additional secrets." << endl;
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
            cout << "1) Respond to the whispers" << endl;
            cout << "2) Touch the clocks" << endl;
            cout << "3) Illuminate the dark corners with the lantern" << endl;
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
            // Start of switch for case 1, player 2
            switch (option)
            {
            case 1:
                cout << "- The voices offer forbidden knowledge about the central creature." << endl;
                cout << endl;
                break;
            case 2:
                cout << "- Adjusts the time of the hallway and slows the distortion." << endl;
                cout << endl;
                break;
            case 3:
                // Condition only if the item has been obtained
                if (player.inventory[lantern] == 1)
                {
                    cout << "- Temporarily banishes lesser entities." << endl;
                    player.inventory[lantern] = 0; // Once used, it is removed from inventory
                    cout << endl;
                    break;
                }
                else
                {
                    cout << "- You do not have any lantern. You walk in total darkness." << endl;
                }
            } // Ends the switch for case 1, player 2
            pass = 2;
            phase = 5;
            event = 0;
            progress(player); // Save progress
        } while (option < 1 || option > 3); // Repeat until an option is chosen
        break;
    }

    case 2:
    {
        // Event 2
        cout << endl;
        cout << "----START OF PHASE 4: The Whispering Hall----" << endl;
        cout << "A dense, giant shadow descends from the ceiling. It is the Primordial Shadow, manifestation of ancient rites." << endl;
        do
        {
            cout << "Inventory: " << endl;
            showObjects(player);
            cout << endl;
            cout << "PLAYER 1: " << player.player1 << endl;
            cout << "Choose an option: " << endl;
            cout << "1) Use the ceremonial dagger against the shadow" << endl;
            cout << "2) Recite the symbols from the plaque" << endl;
            cout << "3) Run to the next room" << endl;
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
                // Condition only if the item has been obtained
                if (player.inventory[dagger] == 1)
                {
                    cout << "- Inflicts spiritual damage, weakening it." << endl;
                    cout << endl;
                }
                else
                {
                    cout << "- You do not have any ceremonial dagger. You cannot do any damage." << endl;
                }
                break;
            case 2:
                cout << "- Stuns the creature for several seconds." << endl;
                cout << endl;
                break;
            case 3:
                cout << "- Manages to advance, but the creature remains free." << endl;
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
            cout << "1) Offer the ancient parchment" << endl;
            cout << "2) Read the diary of the lost explorer" << endl;
            cout << "3) Make loud noises to distract it" << endl;
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
                // Condition only if the item has been obtained
                if (player.inventory[parchment] == 1)
                {
                    cout << "- Partially traps the entity." << endl;
                    player.inventory[parchment] = 0; // Once used, it is removed from inventory
                    cout << endl;
                }
                else
                {
                    cout << "- You do not have any parchment. You cannot do anything." << endl;
                }
                break;
            case 2:
                cout << "- Discovers the final weak point of the creature." << endl;
                cout << endl;
                break;
            case 3:
                cout << "- The Shadow changes targets, allowing them to reunite." << endl;
                cout << endl;
                break;
            } // Ends the switch for case 2, player 2
            pass = 2;
            phase = 5;
            event = 0;
            progress(player); // Save progress
        } while (option < 1 || option > 3); // Repeat until an option is chosen
        break;
    }

    case 3:
    {
        // Event 3
        cout << endl;
        cout << "----START OF PHASE 4: The Whispering Hall----" << endl;
        cout << "While fleeing, they enter a circular room where multiple doors appear, ";
        cout << "all slowly turning as if the space itself were folding." << endl;
        do
        {
            cout << endl;
            cout << "Inventory: " << endl;
            showObjects(player);
            cout << endl;
            cout << "PLAYER 1: " << player.player1 << endl;
            cout << "Choose an option: " << endl;
            cout << "1) Choose the illuminated door" << endl;
            cout << "2) Choose the black door" << endl;
            cout << "3) Let your partner decide" << endl;
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
                cout << "- You move towards the core of the mansion." << endl;
                cout << endl;
                break;
            case 2:
                cout << "- You enter a hallway full of bloody paintings." << endl;
                cout << endl;
                break;
            case 3:
                cout << "- You synchronize your fate, increasing the joint spiritual strength." << endl;
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
            cout << "1) Follow the sound of water" << endl;
            cout << "2) Use the partial map found at the beginning" << endl;
            cout << "3) Leave it to chance (wander and point)" << endl;
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
                cout << "- You find access to the final ritual." << endl;
                cout << endl;
                break;
            case 2:
                // Condition only if the item has been obtained
                if (player.inventory[map] == 1)
                {
                    cout << "- You find a secondary secret door." << endl;
                    player.inventory[map] = 0; // Once used, it is removed from inventory
                    cout << endl;
                }
                else
                {
                    cout << "- You do not have any map. You cannot do anything." << endl;
                }
                break;
            case 3:
                cout << "- Completely random outcome." << endl;
                cout << endl;
                break;
            } // Ends the switch for case 3, player 2
        } while (option < 1 || option > 3); // Repeat until an option is chosen
        break;
    }
        // Ends switch
    }
    cout << "-------End of Phase 4-------" << endl;
    cout << endl;
    cout << "Auto-saving game " << endl;
    cout << endl;
    // Auto-save after each event
    pass = 2;
    phase = 5;
    event = 0;
    progress(player);
    return;
}

// Phase 5
void phase5(gameData &player)
{
    int option;
    int &phase = player.phase;
    int &event = player.event;
    int &pass = player.pass;
    // Phase 5
    cout << endl;
    cout << "----START OF PHASE 5: The Final Ritual----" << endl;
    cout << "Here the story approaches possible endings based on previous decisions. But first: " << endl;
    cout << "They arrive at an underground sanctuary. Three pedestals await specific offerings: " << endl;
    cout << "The iron key." << endl;
    cout << "The medallion." << endl;
    cout << "The parchment." << endl;
    cout << "If these objects were obtained during previous phases:" << endl;
    cout << "The ritual can be completed correctly (approaching a good ending)." << endl;
    cout << "If objects are missing, the ritual will be unstable." << endl;
    cout << "Both players must decide:" << endl;
    do
    {
        cout << endl;
        cout << "Inventory: " << endl;
        showObjects(player);
        cout << endl;
        cout << "PLAYER 1: " << player.player1 << " PLAYER 2: " << player.player2 << endl;
        cout << "Choose an option: " << endl;
        cout << "1) Place all found objects." << endl;
        cout << "2) Place only what you have." << endl;
        cout << "3) Reject the ritual and flee." << endl;
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
        // Start of switch
        switch (option)
        {
        case 1:
            // Condition only if all objects have been obtained
            if (player.inventory[key] == 1 && player.inventory[medallion] == 1 && player.inventory[parchment] == 1)
            {
                cout << "- The complete expulsion seal is activated." << endl;
                cout << "Consequence: The mansion trembles, the dark energy is absorbed." << endl;
                cout << "The voices of ancient condemned spirits thank the players." << endl;
                cout << endl;
            }
            // Condition only if at least one object has been obtained
            else if (player.inventory[key] == 1 || player.inventory[medallion] == 1 || player.inventory[parchment] == 1)
            {
                cout << "- Partial ritual; traces of entities remain in the place." << endl;
                cout << "Consequence: Some entities are released and escape into the outside world. ";
                cout << "The mansion remains abandoned, but dangerous." << endl;
                cout << endl;
            }
            // Condition if no object has been obtained
            else
            {
                cout << "- They unleash the complete wrath of the mansion while fleeing." << endl;
                cout << "Consequence: The entire structure collapses ";
                cout << "as the players flee through narrow passages." << endl;
                cout << endl;
            }
            break;

        case 2:
            // Condition only if at least one object has been obtained
            if (player.inventory[key] == 1 || player.inventory[medallion] == 1 || player.inventory[parchment] == 1)
            {
                cout << "- Partial ritual; traces of entities remain in the place." << endl;
                cout << "Consequence: Some entities are released and escape into the outside world. ";
                cout << "The mansion remains abandoned, but dangerous." << endl;
                cout << endl;
            }
            // Condition only if all objects have been obtained
            else if (player.inventory[key] == 1 && player.inventory[medallion] == 1 && player.inventory[parchment] == 1)
            {
                cout << "- The complete expulsion seal is activated." << endl;
                cout << "Consequence: The mansion trembles, the dark energy is absorbed." << endl;
                cout << "The voices of ancient condemned spirits thank the players." << endl;
                cout << endl;
            }
            // Condition if no object has been obtained
            else
            {
                cout << "- They unleash the complete wrath of the mansion while fleeing." << endl;
                cout << "Consequence: The entire structure collapses ";
                cout << "as the players flee through narrow passages." << endl;
                cout << endl;
            }
            break;
        case 3:
            // Condition if no object has been obtained
            cout << "- They unleash the complete wrath of the mansion while fleeing." << endl;
            cout << "Consequence: The entire structure collapses ";
            cout << "as the players flee through narrow passages." << endl;
            cout << endl;
            // Condition only if all objects have been obtained
            if (player.inventory[key] == 1 && player.inventory[medallion] == 1 && player.inventory[parchment] == 1)
            {
                cout << "- The complete expulsion seal is activated." << endl;
                cout << "Consequence: The mansion trembles, the dark energy is absorbed." << endl;
                cout << "The voices of ancient condemned spirits thank the players." << endl;
                cout << endl;
            }
            // Condition only if at least one object has been obtained
            else if (player.inventory[key] == 1 || player.inventory[medallion] == 1 || player.inventory[parchment] == 1)
            {
                cout << "- Partial ritual; traces of entities remain in the place." << endl;
                cout << "Consequence: Some entities are released and escape into the outside world. ";
                cout << "The mansion remains abandoned, but dangerous." << endl;
                cout << endl;
            }
            break;
        } // Ends the switch
    } while (option < 1 || option > 3); // Repeat until an option is chosen
    cout << "-------End of Phase 5-------" << endl;
    cout << "Auto-saving game " << endl;
    // Auto-save after each event
    pass = 1;
    phase = 6;
    event = 0;
    progress(player); // Save progress
}

// Game endings 
void finals(gameData &player) 
{ 
    int &phase = player.phase; 
    int &event = player.event; 

    int &pass = player.pass; 
    // Here we integrate the possible endings: 
    // Ending 1 
    // Condition only if all objects have been obtained 
    if (player.inventory[key] == 1 && player.inventory[medallion] == 1 && player.inventory[parchment] == 1) 

    { 
        cout << endl; 
        cout << "-----------ENDING------------" << endl; 
        cout << "The Complete Purification" << endl; 
        cout << "They managed to gather all the elements, follow the correct clues, "; 
        cout << "face the Primordial Shadow and seal the evil forever. "; 
        cout << "Both characters emerge at dawn as the mansion collapses. "; 
        cout << "The singing of the first birds can be heard. They are safe." << endl; 

    } 
    // Ending 2 
    // Condition only if at least one object has been obtained 
    else if (player.inventory[key] == 1 || player.inventory[medallion] == 1 || player.inventory[parchment] == 1) 

    { 
        cout << endl; 
        cout << "-----------ENDING------------" << endl; 
        cout << "The Dark Echo" << endl; 
        cout << "Some rituals or decisions failed. The mansion remains partially clean, "; 
        cout << "but some spirits manage to escape into the outside world. The air is heavier, "; 
        cout << "and they feel that they have not finished everything. At least they saved their lives." << endl; 

    } 
    // Ending 3 
    // Condition if no object has been obtained 
    else 

    { 
        cout << endl; 
        cout << "-----------ENDING------------" << endl; 
        cout << "The Sealed Fate" << endl; 
        cout << "They fled without performing the ritual or failed severely. The entities dominate "; 
        cout << "the mansion completely. A dark portal remains open permanently. "; 
        cout << "Years later, more reckless visitors disappear. "; 
        cout << "No one speaks of the Blackthorn Mansion again." << endl; 

    } 
    cout << "Auto-saving game " << endl; 
    cout << endl; 

    // Auto-save after each event 
    pass = 1; 
    phase = 7; 
    event = 0; 
    progress(player); 
    return; 

} 
