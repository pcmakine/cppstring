#ifndef TESTDRIVER_H
#define TESTDRIVER_H
#include "myString.h"
#include <string>

class TestDriver{
public:

	TestDriver();
    bool assertEquals(MyString& str, MyString& otherStr, std::string printIfFailed);
};
#endif
