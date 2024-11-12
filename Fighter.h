#pragma once
#include <string>
using namespace std;

class Fighter{
public:
	Fighter(string fClass);

	Fighter(string fClass, int level);

	int attack();

	void defend(int damage);

private: 
	int health;
	int armor;
	int attackDmg;
	int speed;
	int crit;
};

