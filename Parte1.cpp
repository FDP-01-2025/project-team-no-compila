#include <iostream>
using namespace std;




int main(){
    //Variable declaration
    int option;
    char a,b,c;
    string name, nameGame, saveGame;
    

    //Menu control
    cout << "-----Menu-----" << endl;
    cout << "1. Profile" << endl;
    cout << "2. New game" << endl;
    cout << "3. Saved game" << endl;
    cout << "4. Exit" << endl;
    cout << "5. Credits" << endl;
    cin >> option;

     // swithc startup
    switch (option)
    {
    case 1:
        cout << "Enter your name: " << endl;
        cin >> name;
        break;

    case 2:
        cout << "Enter a name for the game: " << endl;
        cin >> nameGame;
        break;

    case 3:
        cout << "Select saved game: " << endl;
        cin >> saveGame;
        break;

    case 4:
        cout << "Thanks for playing othe game " << endl;
        break;

    case 5:
        cout << "credits..." << endl;
        break;

    default:
        cout << "Invalid opction. Selecta a valid option (1-5) " << endl;
        break;
    }
    cout << "Event 1" << endl;
    cout << "The storm strikes the rusty gate, which opens with a blood-curdling screech. The";
    cout << "thunder illuminates the imposing Blackthorn Manor for seconds. On the damp ground, an old";
    cout << "metal box rests in front of a dusty portrait whose face seems to follow their movements.";
    
do{
    cout << "PLAYER 1:" << endl;
    cout << "Choose an option: " << endl;
    cout << "1) Force open the metal box" << endl;
    cout << "2) Inspect the portrait for clues" << endl;
    cout << "3) Close your eyes and listen to the whispers" << endl;
    cin >> option;
    
    switch (option)
{
case 1:
    cout << " You find an old iron key (useful later)." << endl;
    break;
case 2:
    cout << " You discover a partial map of the mansion behind the painting." << endl;
    break;
case 3:
    cout << " The whispers give you a warning about “the cursed basement door.”" << endl;
    break;
} 
    
}while (option > 3 || option < 1);

    do{ 
    cout << "PLAYER 2:" << endl;
    cout << "Choose an option: " << endl;
    cout << "1) Follow the footprints that disappear into the darkness" << endl;
    cout << "2) Explore a piece of furniture with strange grooves" << endl;
    cout << "3) Observe the shadows that seem to move." << endl;
    cin >> option;

    switch (option)
{
case 1:
    cout << "You discover a trapdoor hidden under the rug." << endl;
    break;
case 2:
    cout << "You find a strange medallion (spiritual protection)." << endl;
    break;
case 3:
    cout << "You perceive a ghostly figure pointing north ." << endl;
    break;
} 
}while (option > 3 || option < 1);



    return 0;
}
