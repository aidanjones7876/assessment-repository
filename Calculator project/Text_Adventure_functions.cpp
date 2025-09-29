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
void swordsman::levelIncrease(float num) {
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

void welcomeScreen() {
	cout << "===== WELCOME TO THE MIDIEVAL TEXT ADVENTURE =====" << endl;
	cout << "You are in the starting room with a few items (PICKING ONE OF THESE ITEMS WILL DETERMINE YOUR CLASS): " << endl;
	cout << "sword" << endl;
	cout << "staff" << endl;
	cout << "bow" << endl;
	string choice;
	cin >> choice;
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
		 swordsman chosen;
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
void roomChoices() {
	int rooms[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	};
}