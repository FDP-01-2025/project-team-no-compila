#include <iostream>
using namespace std;




int main(){
    //Variable declaration
    int option;
    char a,b,c;



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
    cin >> opc;
    
    switch (opc)
{
case 1:
    cout << "→ You find an old iron key (useful later)." << endl;
    break;
case 2:
    cout << "→ You discover a partial map of the mansion behind the painting." << endl;
    break;
case 3:
    cout << "→ The whispers give you a warning about “the cursed basement door.”" << endl;
    break;
} 
    
}while (opc > 3 || opc < 1);


    return 0;
}
