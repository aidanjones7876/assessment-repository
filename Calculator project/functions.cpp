#include <algorithm>
#include <iostream>
#pragma
#include <fstream>
#include <string>
#include "functions.h"

using namespace std;
void testFunc::runTest(string name, bool result) {
	totalTests++;
	cout << name;

	//adds space for neatness.
	for (int i = name.length(); i < 30; i++) {
		cout << " ";
	}

	if (result) {
		cout << "PASS" << endl;
		passedTests++;
		writeToLog(name + "- PASSED");
	}
	else {
		cout << "FAIL" << endl;
		writeToLog(name + "- FAILED");
	}
}

void testFunc::writeToLog(string name) {

	ofstream logFile("test_functions.txt", ios::app);

	if (logFile.is_open()) {
		logFile << name << endl;
	}
}

stringClass::stringClass(){//calls the default constructor
	holder = "";
	cout << "default constructor called" << endl;
}

stringClass::stringClass(string str) {//calls constructor with data
	holder = str;
	cout << "constructor parameter called: " << str << endl;
}

int stringClass::length() {//calls the length of data
	return holder.length();
	
}

char stringClass::characterAt(int index) {//calls character in a certain location
	if (index < 0 || index >= holder.length()) {
		return '/0';
	}
	return holder[index];
}

bool stringClass::equalTo(stringClass excess) {//detects if excess is equal to holder. if not it returns false
	return holder == excess.holder;
}

string stringClass::append(stringClass app) {//adds app infront of holder
	return holder = holder + app.holder;
}

string stringClass::prepend(stringClass pre) {//adds pre behind holder
	return holder = pre.holder + holder;
}

string stringClass::toLower() {//makes all letters lowercase
	for (int i = 0; i < holder.length(); i++) {
		if (holder[i] >= 'A' && holder[i] <= 'Z') {
			holder[i] = holder[i] + 32;
		}
	}
	return holder;
}

string stringClass::toUpper() {//makes all letters uppercase
	for (int i = 0; i < holder.length(); i++) {
		if (holder[i] >= 'a' && holder[i] <= 'z') {
			holder[i] = holder[i] - 32;
		}
	}
	return holder;
}

int stringClass::Find(stringClass findStr) {//runs through holder to find findStr. if not it returns -1
	
	int pos = holder.find(findStr.holder);
	if (pos >= 0) {
		return pos;
	}
	else {
		return -1;
	}
}

int stringClass::Find(int startIndex, stringClass findStr) {//same thing as before, but you can use index to start at whatever point you want
	if (startIndex < 0 || startIndex >= holder.length()) {
		return -1;
	}
	int pos = holder.find(findStr.holder, startIndex);
	if (pos >= 0) {
		return pos;
	}
	else {
		return -1;
	}
}

void stringClass::replacement(stringClass toReplace, stringClass replacement) {//replaces holder with whatever repStr is
	
	int pos = 0;

	while ((pos = holder.find(toReplace.holder, pos)) >= 0) {
		cout << holder.replace(pos, toReplace.length(), replacement.holder);
		pos += replacement.holder.length();
	}
	
}

void stringClass::readFromConsole() {//reads from the console
	cout << holder << endl;
}

void stringClass::writeToConsole() {//inputs into the console
	cout << "Just input whatever" << endl;
	string str;
	cin >> str;
	cout << str << endl;
	cout << "Also, here's your data: " << holder << endl;
}
void functionCalls() {
	stringClass();
	stringClass obj1("I have a sword");
	stringClass obj2("shield");
	stringClass obj3("sword");
	stringClass obj4("ATTack");
	obj1.replacement(obj3, obj2);
	cout << obj1.length() << endl;
	cout << obj1.characterAt(4) << endl;
	cout << obj1.equalTo(obj2) << endl;
	cout << obj1.equalTo(obj1) << endl;
	cout << obj1.append(obj2) << endl;
	cout << obj1.prepend(obj3) << endl;
	cout << obj4.toLower() << endl;
	cout << obj4.toUpper() << endl;
	cout << obj1.Find(obj3) << endl;
	cout << obj1.Find(4, obj3) << endl;
	cout << obj1.Find(60, obj3) << endl;
	obj1.replacement(obj3, obj2);
	obj1.readFromConsole();
	obj1.writeToConsole();
}

void testFunc::lengthTest() {
	cout << "Length test" << endl;

	stringClass str("World");

	runTest("Length of 'World'", str.length() == 5);
}
void testFunc::constructorsTest() {
	cout << "constructor tet" << endl;

	stringClass str1;
	runTest("Default constructor", str1.length() == 0);

	stringClass str2("Hello");
	runTest("string constructor", str2.length() == 5);
}
void testFunc::characterAtTest() {
	cout << "characterAtTest" << endl;

	stringClass character("Hello");

	runTest("CharacterAtTest", character.characterAt('H') == 0);

}
void testFunc::equalToTest() {
	cout << "equal to test" << endl;

	stringClass str1("Hello");
	stringClass str2("Hello");

	runTest("equal to test", str1.equalTo(str2));
}
string stringClass::getString() {
	return holder;
}
void testFunc::appendTest() {
	cout << "append test" << endl;

	stringClass str("World");
	stringClass str2("Hello");

	runTest("append test", str.append(str2) == "Hello World");
}
void testFunc::prependTest() {
	cout << "prepend test" << endl;

	stringClass str("Hello");
	stringClass str2("World");
	str.prepend(str2);
	runTest("prepend test", str.getString() == "Hello World");
}
void testFunc::toLowerTest() {
	cout << "to lower test" << endl;

	stringClass str("Hello");
	str.toLower();
	runTest("to lower test", str.getString() == "hello");
}
void testFunc::toUpperTest() {
	cout << "to upper test" << endl;

	stringClass str("Hello");
	str.toUpper();
	runTest("to upper test", str.getString() == "HELLO");
}
void testFunc::findTest() {
	cout << "find test" << endl;

	stringClass str("Hello World");
	stringClass str2("Hello");

	runTest("find test", str.Find(str2) == 0);
}
void testFunc::replaceTest() {
	cout << "replace test" << endl;

	stringClass str("Hello World");
	stringClass str2("World");
	stringClass str3("Universe");
	str.replacement(str2, str3);

	runTest("replace test", str.getString() == "Hello Universe");

}

void testFunc::allTests() {
	cout << "You completed: " << totalTests << endl;

	cout << "You failed: " << totalTests - passedTests << endl;
}