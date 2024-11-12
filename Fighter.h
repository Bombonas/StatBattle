#pragma once
#include <iostream>
#include <string>
using namespace std;

class Fighter{
public:
	Fighter(string fClass);

	Fighter(int level);

	int attack();

	void defend(int damage);

	int getHealth() const;

	int getSpeed() const;

	void displayStats(string title) const;

private: 
	void setBaseStats(string fClass);
	void setRandomStat(int level);

	int health;
	int armor;
	int attackDmg;
	int speed;
	int crit;
	string wClass;
	int wLevel = 0;
};

