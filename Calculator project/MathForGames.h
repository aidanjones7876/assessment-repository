#pragma once
using namespace std;
#include <string>
#ifndef MATH_H
#define MATH_H

class player {
public: 
	int level;
	long long currentXP;
	long long xpToNextLevel;

	//constructor
	player() : level(1), currentXP(0), xpToNextLevel(100) {}

	void gainXP(int num) {
		currentXP += num;
		cout << "You have gained " << num << " XP. Current XP: " << currentXP << endl;

		//check level up
		while (currentXP >= xpToNextLevel) {
			levelUp();
		}
	}
private:
	void levelUp() {
		level++;
		currentXP -= xpToNextLevel; //deduct xp required for level
		xpToNextLevel = calculateXPFornextLevel(level); // calculate new xp requirement
		cout << "Level up! New Level: " << level << ". XP to next level: " << xpToNextLevel << endl;
	}

	long long calculateXPFornextLevel(int currentLevel) {
		//example: XP required increases exponentially
		return 100LL * currentLevel * (currentLevel / 2);
	}
};
struct LootItem {
	string name;
	int weight;
};

class LootTable {
private:
	LootItem items[5];
	int itemCount;
	int totalWeight;

public:
	LootTable();
	void addItem(string name, int weight);
	string rollLoot();
	void displayTable();
};
#endif
