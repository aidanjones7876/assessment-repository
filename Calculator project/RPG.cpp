#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include "RPG.h"
#include "Text_Adventure_functions.h"

player user;
void gob::attack() {
	user.healthy() - damage;
	cout << "Player takes " << damage << " damage!" << endl;
	cout << "Player Health Remaining: " << user.healthy() << endl;
}
void player::levelIncrease(float num) {
	float damageMultiplier = num / 7;
	float healthMultiplier = num / 14;
	health = health * (1 + healthMultiplier);
	damage = damage * (1 + damageMultiplier);
	cout << "Damage: " << damage << endl;
	cout << "Health: " << health << endl;
}
void experience::levelUp() {
	level++;
	currentXP -= xpToNextLevel; //deduct xp required for level
	xpToNextLevel = calculateXPFornextLevel(level); // calculate new xp requirement
	cout << "Level up! New Level: " << level << ". XP to next level: " << xpToNextLevel << endl;
	user.levelIncrease(1);
}
gob goblin;
chipped_Sword chipped;
axee axe;
scimitarr scimitar;
swordd sword;
katanaa katana;
greatSwordd greatSword;
axeAndFlaill FlailAxe;
paladinBlade paladinSword;
whipp whip;
experience xp;
//Loot Table for weapons
LootTable weaponTable;

void weaponLootTable() {
	weaponTable.addItem(chipped.weap(), 22);
	weaponTable.addItem(axe.weap(), 19);
	weaponTable.addItem(scimitar.weap(), 15);
	weaponTable.addItem(sword.weap(), 19);
	weaponTable.addItem(katana.weap(), 10);
	weaponTable.addItem(greatSword.weap(), 7);
	weaponTable.addItem(FlailAxe.weap(), 5);
	weaponTable.addItem(paladinSword.weap(), 2);
	weaponTable.addItem(whip.weap(), 1);

	weaponTable.displayTable();
	string outcome = weaponTable.rollLoot();
	cout << "==== ROLLING FOR LOOT ====" << endl;
	for (int i = 0; i < 1; i++) {
		cout << "You got: " << outcome << endl;
	}

	string choice;
	cout << "would you like to equip this item?" << endl;
	cin >> choice;
	if (choice == "yes") {
		if (outcome == chipped.weap()) {
			user.toolName(chipped.weap());
			user.toolDamage(chipped.inflict());
		}
		if (outcome == axe.weap()) {
			user.toolName(axe.weap());
			user.toolDamage(axe.inflict());
		}
		if (outcome == scimitar.weap()) {
			user.toolName(scimitar.weap());
			user.toolDamage(scimitar.inflict());
		}
		if (outcome == sword.weap()) {
			user.toolName(sword.weap());
			user.toolDamage(sword.inflict());
		}
		if (outcome == katana.weap()) {
			user.toolName(katana.weap());
			user.toolDamage(katana.inflict());
		}
		if (outcome == greatSword.weap()) {
			user.toolName(greatSword.weap());
			user.toolDamage(greatSword.inflict());
		}
		if (outcome == FlailAxe.weap()) {
			user.toolName(FlailAxe.weap());
			user.toolDamage(FlailAxe.inflict());
		}
		if (outcome == paladinSword.weap()) {
			user.toolName(paladinSword.weap());
			user.toolDamage(paladinSword.inflict());
		}
		if (outcome == whip.weap()) {
			user.toolName(whip.weap());
			user.toolDamage(whip.inflict());
		}
	}
	if (choice == "no") {
		cout << "Bet" << endl;
	}
}

void welcomeRPG() {


	cout << "===== WELCOME TO THIS RANDOM RPG =====" << endl;
	cout << "In this game, you will fight constant waves of monsters. These monsters may or may not drop loot and will give you xp." << endl;
	string choice;
	cout << "Are you ready? (Yes or No)" << endl;
	cin >> choice;
	while (choice != "Yes" && choice != "yes" && choice != "No" && choice != "no") {
		cout << "Not a choice, choose again." << endl;
		cin >> choice;
	}
	if (choice == "yes" || choice == "Yes") {
		cout << "Let the battling commence" << endl;
		secondScreen();
	}
	if (choice == "no" || choice == "No") {
		cout << "Alright fine, then I'll just end the code since you wanna be a bum" << endl;
	}
}


void secondScreen() {

	cout << "Here are you starting stats: " << endl;
	user.playerInfo();
	cout << "You will fight monsters that drop xp in order for you to level up." << endl;
	cout << "They may also drop loot, but it won't always be the same." << endl;
	cout << "Here comes your first monster!" << endl;
	battling(goblin.inflict(), goblin.healthy());
}

void callItself() {
	battling(goblin.inflict(), goblin.healthy());
}
void battling(int monsterDamage, int monsterHealth) {
	string choice;
	cout << "(attack OR run)" << endl;
	cin >> choice;
	
	while (choice != "run" && choice != "attack") {
		cout << "Not a choice try again (Do all lower case if inputted the right word)" << endl;
	}
	while (choice == "run" && user.healthy() > 0) {
		cout << "No running for you!" << endl;
		user.takeDamage(monsterDamage);
		cin >> choice;
	}

	while (choice == "attack" && user.healthy() > 0 && monsterHealth > 0) {
		monsterHealth = user.attack(monsterHealth); 
		if (monsterHealth <= 0) {
			cout << "Nice job, you'll be returning to the second screen until game is updated." << endl;
			xp.gainXP(100);
			weaponLootTable();
			user.playerInfo();
			callItself();
		}
		user.takeDamage(monsterDamage);
		cin >> choice;
	}

	if (user.healthy() <= 0) {
		cout << "What a shame... Run it back?" << endl;
		cin >> choice;
		if (choice == "yes") {
			welcomeRPG();
		}
		if (choice == "no") {
			cout << "shame" << endl;
		}
	}

	
}



