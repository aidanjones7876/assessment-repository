#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"
#include "Text_Adventure_functions.h"
#include "MathForGames.h"

using namespace std;

int main() {
	//functionCalls();
	/*testFunc first;
	first.constructorsTest();
	first.lengthTest();
	first.characterAtTest();
	first.equalToTest();
	first.appendTest();
	first.prependTest();
	first.toLowerTest();
	first.toUpperTest();
	first.findTest();
	first.replaceTest();
	first.allTests();*/
	
	//==== TEXT ADVENTURE FUNCTIONS====
	/*welcomeScreen();
	dungeon();*/
	//end of text adventure functions
	
	player player;
	cout << "Starting level: " << player.level << ", XP: " << player.currentXP << ", XP to next level: " << player.xpToNextLevel << endl;

	player.gainXP(40);
	player.gainXP(70); //triggers level up
	player.gainXP(800); //trigger multiple level ups
	

	//loot table
	LootTable garage;

	garage.addItem("old civic", 80);
	garage.addItem("350Z", 15);
	garage.addItem("Lambo", 4);
	garage.addItem("MClaren Senna", 1);

	garage.displayTable();

	cout << "==== Roll simulation ====" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "Drop" << (i + 1) << ": " << garage.rollLoot() << endl;
	}
}