#include "Fighter.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

Fighter::Fighter(string fClass) {
	wClass = fClass;
	setBaseStats(fClass);
};

Fighter::Fighter(int level) {
	health = 600;
	armor = 8;
	attackDmg = 60;
	speed = 5;
	crit = 2;

	wLevel = level;
	setRandomStat(level);
};

void Fighter::setBaseStats(string fClass) {
	if (fClass == "Warrior") {
		health = 640; // 100 + 9*60
		armor = 16; // 8 * 2
		attackDmg = 60; // 10 + 10*5
		speed = 7; // 5 + 2
		crit = 5; // 5 * 1
	}
	else if (fClass == "Mage") {
		health = 340;
		armor = 6;
		attackDmg = 110;
		speed = 9;
		crit = 20;
	}
	else if (fClass == "Archer") {
		health = 400;
		armor = 8;
		attackDmg = 90;
		speed = 12;
		crit = 15;
	}
	else if (fClass == "Assassin") {
		health = 280;
		armor = 4;
		attackDmg = 90;
		speed = 11;
		crit = 30;
	}
	else if (fClass == "Paladin") {
		health = 520;
		armor = 14;
		attackDmg = 60;
		speed = 8;
		crit = 15;
	}
	else {// Berserker
		health = 460;
		armor = 6;
		attackDmg = 100;
		speed = 9;
		crit = 15;
	}
};

void Fighter::setRandomStat(int level) {
	int points = 0;

	switch (level) {
	case 1:
		points = 5;
		break;
	case 2:
		points = 10;
		break;
	case 3:
		points = 15;
		break;
	default:
		points = 0;
		break;
	}

	//srand(time(0));

	for (int i = 0; i < points; ++i) {
		int randomStat = rand() % 5;
		switch (randomStat) {
		case 0: health += 10; break;
		case 1: armor += 1; break;
		case 2: attackDmg += 5; break;
		case 3: speed += 1; break;
		case 4: crit += 2; break;
		}
	}
};

int Fighter::attack() {
	int baseDamage = attackDmg;

	int critChance = rand() % 100;
	if (critChance < crit) baseDamage *= 2;

	return baseDamage;
};

void Fighter::defend(int damage) {
	if (armor > 0) damage -= static_cast<int>(damage * (armor / 100.0));
	if (damage < 0) damage = 0;
	health -= damage;

	if (health < 0) health = 0;
};

int Fighter::getHealth() const {
	return health;
};

int Fighter::getwLevel() const {
	return wLevel;
};

int Fighter::getSpeed() const {
	return speed;
};

string Fighter::getwClass() const {
	return wClass;
};

void Fighter::displayStats(string title) const {
	int totalLength = 25;
	int titleLength = title.length();
	int padding = (totalLength - titleLength - 2) / 2;  

	cout << string(padding, '=') << " " << title << " " << string(padding, '=');
	
	if ((totalLength - titleLength - 2) % 2 != 0) {
		cout << "=";
	}

	cout << endl;
	cout << "Class: " << wClass << endl;
	cout << "Level: " << wLevel << endl;
	cout << "Health: " << health << endl;
	cout << "Armor: " << armor << endl;
	cout << "Attack Damage: " << attackDmg << endl;
	cout << "Speed: " << speed << endl;
	cout << "Crit Chance: " << crit << "%" << endl;
	cout << "=========================\n" << endl;
}