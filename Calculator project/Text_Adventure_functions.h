#pragma once
using namespace std;
#include <string>
#ifndef adventure_H
#define adventure_H

//holds all the playerclass choice information
class playerClass {
protected:
	string className;
	float maxHealth;
	float damage;
	string weapon;
public:
	void levelIncrease(float num);
};
//swordsman
class swordsman : public playerClass {
public:
	swordsman();
	
	void swordsmanInfo();
	int attack() {
		return damage;
	}
	void takeDamage(int damage) {
		maxHealth -= damage;
		if (maxHealth < 0) {
			maxHealth = 0;
		}
		cout << "You have " << maxHealth << " health left" << endl;
	}
	int health() {
		return maxHealth;
	}

};
//mage
class mage : public playerClass {
public:
	mage();
	void mageInfo();
	int attack() {
		return damage;
	}
	void takeDamage(int damage) {
		maxHealth -= damage;
		if (maxHealth < 0) {
			maxHealth = 0;
		}
		cout << "You have " << maxHealth << " health left" << endl;
	}
	int health() {
		return maxHealth;
	}
};
//archer
class archer : public playerClass {
public:
	archer();
	void archerInfo();
	int attack() {
		return damage;
	}
	void takeDamage(int damage) {
		maxHealth -= damage;
		if (maxHealth < 0) {
			maxHealth = 0;
		}
		cout << "You have " << maxHealth << " health left" << endl;
	}
	int health() {
		return maxHealth;
	}
};

//enemies
class boss {
private:
	int health = 100;
	int damage = 25;
public:
	boss();
	void bossInfo() {
		cout << health;
		cout << damage;
	}
	int attack() {
		return damage;
	}
	int takeDamage(float damage) {
		health -= damage;
		if (health < 0) {
			health = 0;
		}
		cout << "Boss has " << health << " health left" << endl;
		return health;
	}
	int healthy() {
		return health;
	}
	
};
class movementChoice {
private:
	string UP;
	string DOWN;
	string RIGHT;
	string LEFT;
};
void welcomeScreen();
void roomChoices(int x, int y);
void dungeon();
void commands();
void workout();
void attackBoss();
void movement(int x, int y);
void stats();
void lampUse();
void chestOp();
void spellList();

#endif
