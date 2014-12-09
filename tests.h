#ifndef TESTS_H
#define TESTS_H
#include "testdriver.h"
#include <map>
#include <string>

class Tests{
TestDriver* driver;

std::map<void (Tests::*)(),std::string> testFunctions;

public:
	Tests();
	void testInsertStringLiteral();
    void testInsertChar();
    void testInsertMyString();
    std::map<void (Tests::*)(),std::string> getTestFunctions();
	
	~Tests();
};
#endif
