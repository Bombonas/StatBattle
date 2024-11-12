#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Fighter.h"
using namespace std;

void initialMessage();

int main() {
	srand(time(0));

    initialMessage();
	
	Fighter fighter1("Mage");

	string classes[] = { "Warrior", "Mage", "Archer", "Assassin", "Paladin", "Berserker" };
	string randomClass = classes[rand() % 6];
	int randomLevel = rand() % 3 + 1;
	Fighter fighter2(randomClass, randomLevel);

	cout << "Fighter 1" << endl;
    fighter1.displayStats();
	cout << "Fighter 2" << endl;
    fighter2.displayStats();

    int turn = 0;
    Fighter fList[] = {fighter1 , fighter2};

    while (fList[0].getHealth() > 0 && fList[1].getHealth() > 0) {
        int pF1 = turn % 2; // attaker 
        int pF2 = (turn + 1) % 2; // defender

        if (fList[pF2].getSpeed() > fList[pF1].getSpeed()) {
            int speedAdvantageChance = rand() % 100;
            if (fList[pF2].getSpeed() - fList[pF1].getSpeed() < speedAdvantageChance) {
                // change attack/defend roles
                int temp = pF1;
                pF1 = pF2;
                pF2 = temp;
            }
        }
        int damage = fList[pF1].attack();
        fList[pF2].defend(damage);
        cout << "=============================" << endl;
        cout << "Fighter 1 Health: " << fList[0].getHealth() << endl;
        cout << "Fighter 2 Health: " << fList[1].getHealth() << endl;

        ++turn;
    }

    if (fList[0].getHealth() <= 0) {
        cout << "Fighter 2 wins!" << endl;
    }
    else if (fList[1].getHealth() <= 0) {
        cout << "Fighter 1 wins!" << endl;
    }

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