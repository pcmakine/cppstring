#ifndef TESTDRIVER_H
#define TESTDRIVER_H
#include "myString.h"
#include <string>
#include <map>
#include "tests.h"

class Tests; //forward declaration; needed for the compiler
class TestDriver{
	int passed;
	int failed;
	std::map<std::string, bool (Tests::*)()> testFuncts;
	Tests* tests;

	template<typename T, typename V>
	static bool failTest(T actual, V expected){
		std::cout << "Assert " << "failed!\n" << "Expected: " << expected << "\nActual: " << actual << std::endl;
		return false;
	}
	static bool passTest();

public:

	TestDriver();
	static bool assertEquals(MyString& actual, MyString& expected);
	static bool assertEquals(MyString& actual, std::string& expecte);
	static bool assertEquals(const char* actual, std::string& expected);
	template<typename C>
	static bool assertEqualsPrimitive(C actual, C expected){
		if(actual == expected){
			return passTest();
		}
		return failTest(actual, expected);
	}

	void run();
	bool runSingle(std::string functionName);
	bool runSingle(std::map<std::string, bool (Tests::*)()>::iterator iter, std::map<std::string, bool (Tests::*)()> testFuncts);
	~TestDriver();
};
#endif
