#include "def.cpp"

int main()
{
    srand(time(0));
    gameData player = menu();
    showObjects(player);
    int &phase = player.phase;

    while (phase == 1) phase1(player);
    while (phase == 2) phase2(player);
    while (phase == 3) phase3(player);
    while (phase == 4) phase4(player);
    while (phase == 5) phase5(player);
    finals(player);
    progress(player);
    

    cout << "Game completed." << endl;

    return 0;
}
