//#include <algorithm>
//#include <iostream>
//#pragma
//#include <fstream>
//#include <string>
//#include "MathForGames.h"
//
//int XPForLevel(int level) {
//	return 100 * pow(level, 1.8);
//}
//
//LootTable::LootTable() {
//	totalWeight = 0;
//	itemCount = 0;
//	srand(time(0));
//}
//
//void LootTable::addItem(string name, int weight) {
//	if (itemCount < 5) {
//		items[itemCount].name = name;
//		items[itemCount].weight = weight;
//		totalWeight += weight;
//		itemCount++;
//	}
//}
//
//string LootTable::rollLoot() {
//	if (itemCount == 0) {
//		return "nothing";
//	}
//
//	int roll = rand() % totalWeight;
//	int cumulative = 0;
//
//	for (int i = 0; i < itemCount; i++) {
//		cumulative += items[i].weight;
//		if (roll < cumulative) {
//			return items[i].name;
//		}
//	}
//	return items[0].name;
//}
//
//void LootTable::displayTable() {
//	cout << "==== Loot Table ====" << endl;
//	for (int i = 0; i < itemCount; i++) {
//		float chance = (items[i].weight / (float)totalWeight * 100);
//		cout << items[i].name << ": " << chance << "%" << endl;
//	}
//}