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
	cout << "Your level increases by " << num << "!" << endl;
	cout << "Damage: " << damage << endl;
	cout << "Health: " << maxHealth << endl;
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

class allSpells {
private:
	string spells[5];
	int spellCount;

public:
	allSpells() {
		spells[0] = "strength";
		spells[1] = "fireball";
		spells[3] = "heal";
		spellCount = 3;
	}
	int strength(int damage) {
		return 2 * chosen.attack();
	}
	int fireball() {
		return 45;
	}
	float heal() {
		return 1.4 * chosen.health();
	}
};
allSpells spells;
class item {
public:
	virtual void use() {
		cout << "not useable" << endl;
	}
	virtual void unUse() {
		cout << "Not un useable" << endl;
	}
};
class lift : public item {
public:
	void use() override {
		
		chosen.levelIncrease(1);
	}
};
class lamp : public item {
public:
	void use() override {
		cout << "You have turned on the lamp" << endl;
	}
	void unUse() override {
		cout << "You have turned off the lamp" << endl;
	}
};
class chest : public item {
public: 
	void use() override {
		cout << "You open the chest and see the skeleton of a great general of the past." << endl;
		cout << "You consume his intelligence and skills!" << endl;
		chosen.levelIncrease(10);
	}
};
chest chestOpen;
lamp active;
void commands() {
	cout << "======== LIST OF COMMANDS ========" << endl;
	cout << "Enter 'stats' to check you statistics" << endl;
	cout << "movement options: north, south, east, west" << endl;
	cout << "Enter 'attack' (only used for boss)" << endl;
	cout << "Enter 'spells' to see spells" << endl;
	
}
void spellList() {
	
}
void stats() {
	chosen.swordsmanInfo();
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
	if (choice == "stats") {
		stats();
		cin >> choice;
	}
	if (choice == "spells") {
		spellList();
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
		chestOp();
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
		lampUse();
		movement(1, 0);
		
	}
	if (rooms[x][y] == rooms[1][1]) {
		cout << "{O, O, O}" << endl;
		cout << "{O, X, O}" << endl;
		cout << "{O, O, O}" << endl;
		cout << "You find a room with what seems to be a bottomless pit." << endl;
		movement(1, 1);
	}
	if (rooms[x][y] == rooms[1][2]) {
		cout << "{O, O, O}" << endl;
		cout << "{O, O, X}" << endl;
		cout << "{O, O, O}" << endl;
		cout << "You find a room filled with candy?" << endl;
		movement(1, 2);
	}
	if (rooms[x][y] == rooms[2][0]) {
		cout << "{O, O, O}" << endl;
		cout << "{O, O, O}" << endl;
		cout << "{X, O, O}" << endl;
		cout << "You find a room that just seems to be a long corridor. Nothing special about it." << endl;
		movement(2, 0);
	}
	if (rooms[x][y] == rooms[2][1]) {
		cout << "{O, O, O}" << endl;
		cout << "{O, O, O}" << endl;
		cout << "{O, X, O}" << endl;
		cout << "====== BOSS ======" << endl;
		cout << "I hope you leveled up" << endl;
		attackBoss();
		
	}
	if (rooms[x][y] == rooms[2][2]) {
		cout << "{O, O, O}" << endl;
		cout << "{O, O, O}" << endl;
		cout << "{O, O, X}" << endl;
		cout << "You find a room with computers (You have no comprehension of what this is since you're midieval)." << endl;
		movement(2, 2);
	}
}
void chestOp() {
	cout << "You are in a dark, moss covered room with what seems to have a rotting chest." << endl;
	string choice;
	cout << "Would you like to open the chest?(yes or no)" << endl;
	
	if (choice == "help") {
		commands();
		cin >> choice;
	}
	if (choice == "stats") {
		stats();
		cin >> choice;
	}
	while (choice != "yes" && choice != "no") {
		cout << "Not a choice" << endl;
		cin >> choice;
	}
	if (choice == "yes") {
		chestOpen.use();
	}
	if (choice == "no") {
		cout << "Then get out of the room bozo" << endl;
	}

}
 void lampUse() {
	 cout << "You are in a room covered in old weapons and tools with a lamp." << endl;
	
	string choice;
	cout << "Would you like to turn on the lamp?(yes or no)" << endl;
	cin >> choice;
	if (choice == "help") {
		commands();
		cin >> choice;
	}
	if (choice == "stats") {
		stats();
		cin >> choice;
	}
	while (choice != "yes" && choice != "no") {
		cout << "Not a choice" << endl;
		cin >> choice;
		}
	if (choice == "yes") {
		active.use();
		cout << "Would you like to turn off the lamp?(yes or no)" << endl;
		cin >> choice;
		if (choice == "no") {
			cout << "Then get a move on. Don't die to the monster" << endl;
		}
		if (choice == "yes") {
			active.unUse();
			cout << "Would you like to turn on the lamp?(yes or no)" << endl;
			cin >> choice;
			if (choice == "no") {
				cout << "Then get a move on. Don't die to the monster" << endl;
			}
			if (choice == "yes") {
				active.use();
				cout << "Would you like to turn off the lamp?(yes or no)" << endl;
				cin >> choice;
				if (choice == "no") {
					cout << "Then get a move on. Don't die to the monster" << endl;
				}
				if (choice == "yes") {
					active.unUse();
					cout << "Would you like to turn on the lamp?(yes or no)" << endl;
					cin >> choice;
					if (choice == "no") {
						cout << "Then get a move on. Don't die to the monster" << endl;
					}
					if (choice == "yes") {
						cout << "You have broke the lamp" << endl;
						if (choice == "no") {
							cout << "Then get a move on. Don't die to the monster" << endl;
						}


					}
				}
			}

		}
	}
}
void workout() {
	cout << "You find a room with some interesting looking weights. Would you like to lift? " << endl;
	string choice;
	cin >> choice;
	while (choice == "yes") {
		lift shredded;
		shredded.use();
		cout << "again?" << endl;
		cin >> choice;
	}
	if (choice == "no") {
		cout << "lame" << endl;
	}
	if (choice == "stats") {
		stats();
		cin >> choice;
	}
}
void dungeon() {
	//hit 'em with a yes
	string choice;
	do {
		cout << "You are outside of the dungeon, would you like to enter?(yes or no)" << endl;
		cin >> choice;
		if (choice == "help") {
			commands();
			cin >> choice;
		}
		if (choice == "stats") {
			stats();
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
	cout << "(ATTACK or RUN or CAST)" << endl;
	cin >> choice;
	
	if (choice == "stats") {
		stats();
		cin >> choice;
	}
	
	while (choice == "run") {
		cout << "You can't escape" << endl;
		chosen.takeDamage(final.attack());
		cin >> choice;
		
	}
	
	if (choice == "help") {
		commands();
	}
	if (choice == "spells") {
		cout << "fireball" << endl;
		cout << "strength" << endl;
		cout << "heal" << endl;

	}
	else {
		cout << "Choose something else" << endl;
	}
	while (choice == "cast fireball" || choice == "fireball") {
		cout << "It does nothing since he's a demon" << endl;
		cout << "(ATTACK or RUN or CAST)" << endl;
		cin >> choice;
	}
	while (choice == "cast strength" || choice == "strength") {
		spells.strength(chosen.attack());
		cout << "(ATTACK or RUN or CAST)" << endl;
		cin >> choice;
	}
	while (choice == "cast heal" || choice == "heal") {
		spells.heal();
		cout << "(ATTACK or RUN or CAST)" << endl;
		cin >> choice;
	}
	while (choice == "attack") {
		final.takeDamage(chosen.attack());

		if (final.healthy() > 0) {
			chosen.takeDamage(final.attack());
			if (chosen.health() <= 0) {
				cout << "Sleepin with the fish" << endl;
				break;
			}
			while (choice == "cast fireball" || choice == "fireball") {
				cout << "It does nothing since he's a demon" << endl;
				chosen.takeDamage(final.attack());
				cout << "(ATTACK or RUN or CAST)" << endl;
				cin >> choice;
			}
			while (choice == "cast strength" || choice == "strength") {
				spells.strength(final.takeDamage(chosen.attack()));
				chosen.takeDamage(final.attack());
				cout << "(ATTACK or RUN or CAST)" << endl;
				cin >> choice;
			}
			while (choice == "cast heal" || choice == "heal") {
				spells.heal();
				chosen.takeDamage(final.attack());
				cout << "(ATTACK or RUN or CAST)" << endl;
				cin >> choice;
			}
			if (chosen.health() > 0) {
				cout << "attack or run or cast" << endl;
				cin >> choice;
			}
			while (choice == "cast fireball" || choice == "fireball") {
				cout << "It does nothing since he's a demon" << endl;
				chosen.takeDamage(final.attack());
				cout << "(ATTACK or RUN or CAST)" << endl;
				cin >> choice;
			}
			while (choice == "cast strength" || choice == "strength") {
				spells.strength(final.takeDamage(chosen.attack()));
				chosen.takeDamage(final.attack());
				cout << "(ATTACK or RUN or CAST)" << endl;
				cin >> choice;
			}
			while (choice == "cast heal" || choice == "heal") {
				spells.heal();
				chosen.takeDamage(final.attack());
				cout << "(ATTACK or RUN or CAST)" << endl;
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
	if (choice == "stats") {
		stats();
		cin >> choice;
	}
	
	while (choice != "west" && choice != "east" && choice != "north" && choice != "south") {
		cout << "That is not an option, pick again" << endl;
		cin >> choice;
	}
	if (choice == "north") {

		x--;
		if (x < 0)
		{
			x = 0;
			cout << "You've reached a dead end";
		}
		roomChoices(x, y);
	}
	if (choice == "south") {
		x++;
		if (x > 2)
		{
			x = 2;
			cout << "You've reached a dead end";
		}
		roomChoices(x, y);
	}
	if (choice == "east") {
		if (y > 2)
		{
			y = 2;
			cout << "You've reached a dead end";
		}
		y++;
		roomChoices(x, y);
	}
	if (choice == "west") {
		if (y < 0)
		{
			y = 0;
			cout << "You've reached a dead end";
		}
		y--;
		roomChoices(x, y);
	}
	
}