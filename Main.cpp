#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
#include "Fighter.h"
using namespace std;

int const N_RECORDS = 30;
int const NUM_BATTLES = 100;
string const  classes[] = { "Warrior", "Mage", "Archer", "Assassin", "Paladin", "Berserker" };
int matrix[NUM_BATTLES][6] = { 0 };

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
        string randomClass = classes[rand() % 6];
        int randomLevel = rand() % 3 + 1;
        Fighter enemy(randomLevel);
        enemy.displayStats("ENEMY " + to_string(i));
        for (int j = 0; j < 6; ++j) {
            Fighter adventurer(classes[j]);
            for (int k = 0; k < NUM_BATTLES; ++k) {
                int turn = 0;
                Fighter fighters[] = { adventurer , enemy };

                while (fighters[0].getHealth() > 0 && fighters[1].getHealth() > 0) {
                    int pF1 = turn % 2; // attaker 
                    int pF2 = (turn + 1) % 2; // defender

                    /*if (fighters[pF2].getSpeed() > fighters[pF1].getSpeed()) {
                        int speedAdvantageChance = rand() % 100;
                        if ((fighters[pF2].getSpeed() - fighters[pF1].getSpeed())/2 < speedAdvantageChance) {
                            // change attack/defend roles
                            int temp = pF1;
                            pF1 = pF2;
                            pF2 = temp;
                        }
                    }*/
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
    file << endl;

    for (int i = 0; i < N_RECORDS; ++i) {
        for (int j = 0; j < 6; ++j) {
            file << matrix[i][j];
            if (j < 5) {
                file << ",";
            }
        }
        file << endl;
    }
    file.close();
}