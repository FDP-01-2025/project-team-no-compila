#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

string file = "part1.txt";

enum objects {
    key, dagger, medallion, lantern, spell, map, parchment, blessedBottle, enchantment,
    creatureName
};

struct gameData {
    string player1;
    string player2;
    string name;
    string nameGame;
    int phase;
    int event;
    int pass;
    int inventory[12] = {0};
};

void progress(gameData player);
gameData loadProgress();
void showObjects(gameData player);
gameData menu();
void phase1(gameData &player);
void phase2(gameData &player);
void phase3(gameData &player);
void phase4(gameData &player);
void phase5(gameData &player);
void finals(gameData &player);