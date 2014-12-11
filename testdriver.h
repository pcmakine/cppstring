#ifndef TESTDRIVER_H
#define TESTDRIVER_H
#include "myString.h"
#include <string>
#include "tests.h"

class TestDriver{
	int passed;
	int failed;

	static bool failTest();
	static bool failTest(MyString& expected, MyString& actual);
	static bool passTest();

public:

	TestDriver();
    static bool assertEquals(MyString& str, MyString& otherStr, std::string printIfFailed);
	static bool assertEquals(MyString& str, MyString& otherStr);
	static bool assertEquals(MyString& str, std::string& otherStr);
	void run();
};
#endif
