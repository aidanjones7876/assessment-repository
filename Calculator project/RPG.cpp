#include <algorithm>
#include <iostream>
#pragma
#include <fstream>
#include <string>
#include "RPG.h"

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
	}
	if (choice == "no" || choice == "No") {
		cout << "Alright fine, then I'll just end the code since you wanna be a bum" << endl;
	}
}