#ifndef TESTDRIVER_H
#define TESTDRIVER_H
#include "myString.h"
#include <string>
#include "tests.h"

class TestDriver{
	int passed;
	int failed;

	template<typename T, typename V>
	static bool failTest(T expected, V actual);
	static bool passTest();

public:

	TestDriver();
	static bool assertEquals(MyString& str, MyString& otherStr);
	static bool assertEquals(MyString& str, std::string& otherStr);
	static bool assertEquals(const char* actual, std::string& expected);
	static bool assertEquals(int actual, int expected);
	static bool assertEquals(char actual, char expected);
	void run();
};
#endif
