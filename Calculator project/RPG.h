#pragma once
using namespace std;
#include <string>
#ifndef RPG_H
#define RPG_H

class weapon {
protected:
	string name;
	int damage;
};

class chipped_Sword : public weapon {
public:
	chipped_Sword() {
		name = "Chipped sword";
		damage = 5;
	}
	void swordInfo() {
		cout << "Weapon Name: " << name << endl;
		cout << "Weapon Damage: " << damage << endl;
	}
	int inflict() {
		return damage;
	}
	string weap() {
		return name;
	}
};

class axee : public weapon {
public:
	axee() {
		name = "axe";
		damage = 6;
	}
	void swordInfo() {
		cout << "Weapon Name: " << name << endl;
		cout << "Weapon Damage: " << damage << endl;
	}
	int inflict() {
		return damage;
	}
	string weap() {
		return name;
	}
};

class scimitarr : public weapon {
public:
	scimitarr() {
		name = "scimitar";
		damage = 7;
	}
	void swordInfo() {
		cout << "Weapon Name: " << name << endl;
		cout << "Weapon Damage: " << damage << endl;
	}
	int inflict() {
		return damage;
	}
	string weap() {
		return name;
	}
};

class swordd : public weapon {
public:
	swordd() {
		name = "sword";
		damage = 8;
	}
	void swordInfo() {
		cout << "Weapon Name: " << name << endl;
		cout << "Weapon Damage: " << damage << endl;
	}
	int inflict() {
		return damage;
	}
	string weap() {
		return name;
	}
};

class katanaa : public weapon {
public:
	katanaa() {
		name = "katana";
		damage = 10;
	}
	void swordInfo() {
		cout << "Weapon Name: " << name << endl;
		cout << "Weapon Damage: " << damage << endl;
	}
	int inflict() {
		return damage;
	}
	string weap() {
		return name;
	}
};

class greatSwordd : public weapon {
public:
	greatSwordd() {
		name = "Great Sword";
		damage = 16;
	}
	void swordInfo() {
		cout << "Weapon Name: " << name << endl;
		cout << "Weapon Damage: " << damage << endl;
	}
	int inflict() {
		return damage;
	}
	string weap() {
		return name;
	}
};

class axeAndFlaill : public weapon {
public:
	axeAndFlaill() {
		name = "axeAndFlail";
		damage = 17;
	}
	void swordInfo() {
		cout << "Weapon Name: " << name << endl;
		cout << "Weapon Damage: " << damage << endl;
	}
	int inflict() {
		return damage;
	}
	string weap() {
		return name;
	}
};

class paladinBlade : public weapon {
public:
	paladinBlade() {
		name = "Paladin's Blade";
		damage = 20;
	}
	void swordInfo() {
		cout << "Weapon Name: " << name << endl;
		cout << "Weapon Damage: " << damage << endl;
	}
	int inflict() {
		return damage;
	}
	string weap() {
		return name;
	}
};

class whipp : public weapon {
public:
	whipp() {
		name = "Vampire Killer";
		damage = 30;
	}
	void swordInfo() {
		cout << "Weapon Name: " << name << endl;
		cout << "Weapon Damage: " << damage << endl;
	}
	int inflict() {
		return damage;
	}
	string weap() {
		return name;
	}
};






class player {
private:
	int health;
	int damage;
	string weapon;
	int weaponDamage;
public:
	player() {
		health = 100;
		damage = 10;
		weapon;
		weaponDamage;
	}
	string toolName(string chosenWeapon) {
		weapon = chosenWeapon;
		return weapon;
	}
	int toolDamage(int damageWeapon) {
		weaponDamage = damageWeapon;
		return weaponDamage;
	}
	void playerInfo() {
		cout << "Health: " << health << endl;
		cout << "Damage: " << damage << endl;
		cout << "Current weapon: " << weapon << endl;
	}
	int inflict() {
		return damage;
	}
	int healthy() {
		return health;
	}
	int attack(int enemyHealth) {
		enemyHealth -= damage + weaponDamage;
		cout << "Damage done: " << damage + weaponDamage << endl;
		cout << "Enemy health left: " << enemyHealth << endl;
		return enemyHealth;
	}
	
	int takeDamage(int receive) {
		health -= receive;
		cout << "Damage taken: " << receive << endl;
		cout << "Player Health remaining: " << health << endl;
		return health;
	}
	void levelIncrease(float num);
};

class enemy {
protected:
	int health;
	int damage;
};


class gob : public enemy {
public:
	gob() {
		health = 35;
		damage = 5;
	}
	int takeDamage(int receive) {
		health -= receive;
		cout << "enemy damage taken: " << receive << endl;
		cout << "enemy health left: " << health << endl;
		return health;
	}
	int inflict() {
		return damage;
	}
	int healthy() {
		return health;
	}
	void attack();
};

class experience {
public:
	int level;
	long long currentXP;
	long long xpToNextLevel;

	//constructor
	experience() : level(1), currentXP(0), xpToNextLevel(100) {}

	void gainXP(int num) {
		currentXP += num;
		cout << "You have gained " << num << " XP. Current XP: " << currentXP << endl;

		//check level up
		while (currentXP >= xpToNextLevel) {
			levelUp();
		}
	}


private:
	

	void levelUp();
	
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
	LootItem items [15];
	int itemCount;
	int totalWeight;

public:
	LootTable() {
		totalWeight = 0;
		itemCount = 0;
		srand(time(0));
	}
	void addItem(string name, int weight) {
		if (itemCount < 15) {
			items[itemCount].name = name;
			items[itemCount].weight = weight;
			totalWeight += weight;
			itemCount++;
		}
	}
	string rollLoot() {
		if (itemCount == 0) {
			return "nothing";
		}

		int roll = rand() % totalWeight;
		int cumulative = 0;

		for (int i = 0; i < itemCount; i++) {
			cumulative += items[i].weight;
			if (roll < cumulative) {
				return items[i].name;
			}
		}
		return items[0].name;
	}
	void displayTable() {
		cout << "===== ROLLING LOOT =====" << endl;
		for (int i = 0; i < itemCount; i++) {
			float chance = (items[i].weight / (float)totalWeight * 100);
			cout << items[i].name << ": " << chance << "%" << endl;
		}
	}
};
void welcomeRPG();
void secondScreen();
void battling(int monsterDamage, int monsterHealth);
void weaponLootTable();
void callItself();

#endif


