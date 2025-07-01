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
