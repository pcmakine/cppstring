#ifndef TESTDRIVER_H
#define TESTDRIVER_H
#include "myString.h"
#include <string>
#include <map>
#include <vector>
#include "tests.h"

class Tests; //forward declaration; needed for the compiler
class TestDriver{

public:
	TestDriver();
	
	static bool assertEqualsStdString(MyString& actual, std::string& expected);
	
	template<typename T>
	static bool assertEquals(T actual, T expected){
		if(actual == expected){
			return passTest();
		}
		return failTest(actual, expected);
	}
		
	template<typename T>
	static bool assertNotEquals(T actual, T expected){
		if(actual != expected){
			return passTest();
		}
		return failTest(actual, expected);
	}

	void run();
	bool runSingleByName(std::string functionName);
	bool runSingle(std::map<std::string, bool (Tests::*)()>::iterator iter, std::map<std::string, bool (Tests::*)()> testFuncts);
	~TestDriver();
	
private:
	int passed;
	int failed;
	std::map<std::string, bool (Tests::*)()> testFuncts;
	std::vector<int> failedTests;
	Tests* tests;

	template<typename T, typename V>
	static bool failTest(T actual, V expected){
		std::cout << "Assert " << "failed!\n" << "Expected: " << expected << "\nActual: " << actual << std::endl;
		return false;
	}
	static bool passTest();
};
#endif
