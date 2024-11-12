#pragma once
#include <iostream>
#include <string>
using namespace std;

class Fighter{
public:
	Fighter(string fClass);

	Fighter(string fClass, int level);

	int attack();

	void defend(int damage);

private: 
	void setBaseStats(string fClass);
	void setRandomStat(int level);

	int health;
	int armor;
	int attackDmg;
	int speed;
	int crit;
};

