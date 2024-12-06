#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <thread>
#include "Fighter.h"
using namespace std;

int const N_RECORDS = 50;
int const NUM_BATTLES = 100;
string const  classes[] = { "Warrior", "Mage", "Archer", "Assassin", "Paladin", "Berserker" };
int matrix[NUM_BATTLES][6] = { 0 };
string enemyClasses[N_RECORDS];
int enemyLevels[N_RECORDS];

void initialMessage();
void createCSV(const string& filename);

int main() {

    // Seed created with the current time, to change every execution
    srand(time(0));
    // Fixed seed, to NOT change every execution
    //srand(3559);

    initialMessage();

    for (int i = 0; i < N_RECORDS; ++i) {
        // Generate the enemy
        int randomLevel = rand() % 3 + 1;
        Fighter enemy(randomLevel);
        enemyLevels[i] = randomLevel;
        enemy.displayStats("ENEMY " + to_string(i));
        for (int j = 0; j < 6; ++j) {
            Fighter adventurer(classes[j]);
            for (int k = 0; k < NUM_BATTLES; ++k) {
                int turn = 0;
                Fighter fighters[] = { adventurer , enemy };

                while (fighters[0].getHealth() > 0 && fighters[1].getHealth() > 0) {
                    int pF1 = turn % 2; 
                    int pF2 = (turn + 1) % 2; 

                    int damage = fighters[pF1].attack();
                    fighters[pF2].defend(damage);
                    ++turn;

                    if (fighters[1].getHealth() <= 0) {
                        ++matrix[i][j];
                    }
                }
            }
        }
    }

    createCSV("battle_results.csv");

    /*for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << "Press ENTER to end the program...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return 0;
}


void initialMessage() {
    cout << "  /$$$$$$   /$$                 /$$           /$$$$$$$              /$$     /$$     /$$                \n";
    cout << " /$$__  $$ | $$                | $$          | $$__  $$            | $$    | $$    | $$                \n";
    cout << "| $$  \\__//$$$$$$    /$$$$$$  /$$$$$$        | $$  \\ $$  /$$$$$$  /$$$$$$ /$$$$$$  | $$  /$$$$$$       \n";
    cout << "|  $$$$$$|_  $$_/   |____  $$|_  $$_/        | $$$$$$$  |____  $$|_  $$_/|_  $$_/  | $$ /$$__  $$      \n";
    cout << " \\____  $$ | $$      /$$$$$$$  | $$          | $$__  $$  /$$$$$$$  | $$    | $$    | $$| $$$$$$$$      \n";
    cout << " /$$  \\ $$ | $$ /$$ /$$__  $$  | $$ /$$      | $$  \\ $$ /$$__  $$  | $$ /$$| $$ /$$| $$| $$_____/      \n";
    cout << "|  $$$$$$/ |  $$$$/|  $$$$$$$  |  $$$$/      | $$$$$$$/|  $$$$$$$  |  $$$$/|  $$$$/| $$|  $$$$$$$    \n";
    cout << " \\______/   \\___/   \\_______/   \\___/        |_______/  \\_______/   \\___/   \\___/  |__/ \\_______/   \n\n";
    this_thread::sleep_for(chrono::seconds(1));
};

void createCSV(const string& filename) {
    ofstream file(filename);

    if (!file) {
        cerr << "Error!" << endl;
        return;
    }

    for (int j = 0; j < 6; ++j) {
        file << classes[j];
        if (j < 5) {
            file << ",";
        }
    }
    file << ",Enemy Level" << endl;

    for (int i = 0; i < N_RECORDS; ++i) {
        for (int j = 0; j < 6; ++j) {
            file << matrix[i][j];
            if (j < 5) {
                file << ",";
            }
        }
        file << "," << enemyLevels[i] << endl;
    }
    file.close();
}