#include <algorithm>
#include <iostream>
#pragma
#include <fstream>
#include <string>
#include "Text_Adventure_functions.h"

swordsman::swordsman() {
	className = "swordsman";
	maxHealth = 150;
	damage = 12.5;
	weapon = "rusty sword";
}
boss::boss() {
	health;
	damage;
}
void playerClass::levelIncrease(float num) {
	float damageMultiplier = num / 8;
	float healthMultiplier = num / 16;
	maxHealth = maxHealth * (1 + healthMultiplier);
	damage = damage * (1 + damageMultiplier);
	cout << damage << endl;
	cout << maxHealth << endl;
}
void swordsman::swordsmanInfo() {
	cout << "Class: " << className << endl;
	cout << "Health: " << maxHealth << endl;
	cout << "Damage: " << damage << endl;
	cout << "Weapon: " << weapon << endl;
}

swordsman chosen;
playerClass player;
boss final;
class item {
public:
	virtual void use() {
		cout << "not useable" << endl;
	}
};
class lift : public item {
public:
	void use() override {
		chosen.levelIncrease(1);
	}
};
void commands() {
	cout << "======== LIST OF COMMANDS ========" << endl;
	cout << "Enter 'stats' to check you statistics" << endl;
	cout << "movement options: north, south, east, west" << endl;
	cout << "Enter 'attack' (only used for boss)" << endl;
	cout << "Enter 'spells' to see spells" << endl;
	cout << "Enter 'cast' and then the name of spell to cast" << endl;
}

void welcomeScreen() {
	cout << "===== WELCOME TO THE MIDIEVAL TEXT ADVENTURE =====" << endl;
	cout << "You are in the starting room with a few items (PICKING ONE OF THESE ITEMS WILL DETERMINE YOUR CLASS): " << endl;
	cout << "Enter 'help' at any point to see list of commands" << endl;
	cout << "sword" << endl;
	cout << "staff" << endl;
	cout << "bow" << endl;
	string choice;
	cin >> choice;
	if (choice == "help") {
		commands();
		cin >> choice;
	}
	while (choice != "sword" && choice != "staff" && choice != "bow") {
		cout << "That is not a choice. pick from these three: " << endl;
		cout << "sword" << endl;
		cout << "staff" << endl;
		cout << "bow" << endl;
		cin >> choice;
	}

	if (choice == "sword") {
		cout << "You have chosen the swordsman class!" << endl;
		cout << "Here are your stats: " << endl;
		
		 chosen.swordsmanInfo();
		 
		 
	}
	else if (choice == "staff") {
		cout << "You have chosen the mage class!" << endl;
	}
	else if (choice == "bow") {
		cout << "You have chosen the archer class!" << endl;
	}
	
	
	
}
//nlnk
const int ROWS = 3;
const int COLS = 3;
void roomChoices(int x, int y) {
	string rooms[ROWS][COLS] = {
		{"1", "2", "3"},
		{"4", "5", "6"},
		{"7", "8", "9"}
	};

	cout << rooms[x][y] << endl;

	if (rooms[x][y] == rooms[0][0]) {
		cout << "{X, O, O}" << endl;
		cout << "{O, O, O}" << endl;
		cout << "{O, O, O}" << endl;
		cout << "You are in a library full of books that hold folktale stories." << endl;
		movement(0, 0);
	}
	if (rooms[x][y] == rooms[0][1]) {
		cout << "{O, X, O}" << endl;
		cout << "{O, O, O}" << endl;
		cout << "{O, O, O}" << endl;
		cout << "You are in a dark, moss covered room with what seems to be a rotting chest." << endl;
		movement(0, 1);
	}
	if (rooms[x][y] == rooms[0][2]) {
		cout << "{O, O, X}" << endl;
		cout << "{O, O, O}" << endl;
		cout << "{O, O, O}" << endl;
		workout();
		movement(0, 2);
	}
	if (rooms[x][y] == rooms[1][0]) {
		cout << "{O, O, O}" << endl;
		cout << "{X, O, O}" << endl;
		cout << "{O, O, O}" << endl;
		cout << "====== BOSS ======" << endl;
		cout << "I hope you leveled up" << endl;
		attackBoss();
		movement(1, 0);
	}
	if (rooms[x][y] == rooms[1][1]) {
		cout << "{O, O, O}" << endl;
		cout << "{O, X, O}" << endl;
		cout << "{O, O, O}" << endl;
		movement(0, 0);
	}
	if (rooms[x][y] == rooms[1][2]) {
		cout << "{O, O, O}" << endl;
		cout << "{O, O, X}" << endl;
		cout << "{O, O, O}" << endl;
		movement(1, 2);
	}
	if (rooms[x][y] == rooms[2][0]) {
		cout << "{O, O, O}" << endl;
		cout << "{O, O, O}" << endl;
		cout << "{X, O, O}" << endl;
		movement(2, 0);
	}
	if (rooms[x][y] == rooms[2][1]) {
		cout << "{O, O, O}" << endl;
		cout << "{O, O, O}" << endl;
		cout << "{O, X, O}" << endl;
		movement(2, 1);
	}
	if (rooms[x][y] == rooms[2][2]) {
		cout << "{O, O, O}" << endl;
		cout << "{O, O, O}" << endl;
		cout << "{O, O, X}" << endl;
		movement(2, 2);
	}
}

void workout() {
	cout << "You find a room with some interesting looking weights. Would you like to lift? " << endl;
	string choice;
	cin >> choice;
	while (choice == "yes") {
		lift shredded;
		shredded.use();
		chosen.swordsmanInfo();
		cout << "again?" << endl;
		cin >> choice;
	}
	if (choice == "no") {
		cout << "lame" << endl;
	}
}
void dungeon() {
	
	string choice;
	do {
		cout << "You are outside of the dungeon, would you like to enter?(yes or no)" << endl;
		cin >> choice;
		if (choice == "help") {
			commands();
			cin >> choice;
		}
		if (choice != "yes") {
			cout << "I'm going to ask again. You are outside of the dungeon, would you like to enter ? (yes or no)" << endl;
				cin >> choice;
		}
	} while (choice != "yes");
	if (choice == "yes") {
		cout << "Welcome to the starting room. ";
		roomChoices(0, 0);
		
	}
}
void attackBoss() {
	string choice;
	cout << "(ATTACK or RUN)" << endl;
	cin >> choice;
	
	
	
	if (choice == "run") {
		cout << "You're cooked" << endl;
		chosen.takeDamage(final.attack());
		
	}
	
	if (choice == "help") {
		commands();
	}
	
	while (choice == "attack") {
		final.takeDamage(chosen.attack());

		if (final.healthy() > 0) {
			chosen.takeDamage(final.attack());
			if (chosen.health() <= 0) {
				cout << "Sleepin with the fish" << endl;
				break;
			}
			
			if (chosen.health() > 0) {
				cout << "attack or run" << endl;
				cin >> choice;
			}
			
		}
		if (final.healthy() <= 0) {
			cout << "You've defeated the boss!" << endl;
			break;
		}
	}
	
	

	
}
void movement(int x, int y) {
	
	
	cout << "Where would you like to move?(north, south, east, west)" << endl;
	string choice;
	cin >> choice;
	while (x < 0 || y < 0) {
		cout << "Can't go that way" << endl;
		cin >> choice;
	}
	if (choice == "north") {
		x++;
		roomChoices(x, y);
	}
	if (choice == "south") {
		x--;
		roomChoices(x, y);
	}
	if (choice == "east") {
		y--;
		roomChoices(x, y);
	}
	if (choice == "west") {
		y++;
		roomChoices(x, y);
	}
}