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


    return 0;
}
