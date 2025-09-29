#pragma once
using namespace std;
#include <string>
#ifndef jonesy_H
#define jonesy_H
void functionCalls();
class testFunc {
private:
	int totalTests;
	int passedTests;
	ofstream logFile;

	void runTest(string name, bool result);
	void writeToLog(string name);

public:


	//function tests
	void constructorsTest();
	void lengthTest();
	void characterAtTest();
	void equalToTest();
	void appendTest();
	void prependTest();
	void toLowerTest();
	void toUpperTest();
	void findTest();
	void replaceTest();
	void allTests();

};
class stringClass {
private:
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
	string getString();
};

#endif