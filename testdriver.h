#ifndef TESTDRIVER_H
#define TESTDRIVER_H
#include "myString.h"
class TestDriver{
public:

	TestDriver();
	bool assertEquals(MyString& str, MyString& otherStr);
};
#endif