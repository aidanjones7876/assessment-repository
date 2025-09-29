#pragma once
using namespace std;
#include <string>
#ifndef adventure_H
#define adventure_H

void welcomeScreen();
class playerClass {
protected:
	string className;
	float maxHealth;
	float damage;
	string weapon;
};
class swordsman : public playerClass {
public:
	swordsman();
	void levelIncrease(float num);
	void swordsmanInfo();

};

#endif
