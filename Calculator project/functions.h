#pragma once
using namespace std;
#include <string>
#ifndef jonesy_H
#define jonesy_H
void functionCalls();
class stringClass {
protected:
	string holder;
public:
	stringClass();
	stringClass(string str);
	int length();
	char characterAt(int index);
	bool equalTo(stringClass excess);
	string append(stringClass app);
	string prepend(stringClass pre);
	string toLower();
	string toUpper();
	int Find(stringClass findStr);
	int Find(int startIndex, stringClass findStr);
	void replacement(stringClass toReplace, stringClass replacement);
	void readFromConsole();
	void writeToConsole();
};

#endif