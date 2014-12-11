#ifndef TESTS_H
#define TESTS_H
#include "testdriver.h"
#include <map>
#include <string>

class Tests{

std::map<std::string, bool (Tests::*)()> testFunctions;
void insertPointerToFunctionMap(std::string fname, bool (Tests::*fpt)());

public:
	Tests();
	
	bool testConstructor();

	bool testInsertStringLiteralToBeginning();
	bool testInsertStringLiteralToMiddle();
	bool testInsertStringLiteralToEnd();
	
	bool testInsertMyStringToBeginning();
	bool testInsertMyStringToMiddle();
	bool testInsertMyStringToEnd();
	
	bool testInsertCharToBeginning();
	bool testInsertCharToMiddle();
	bool testInsertCharToEnd();

    std::map<std::string, bool (Tests::*)()> getTestFunctions();
	
	~Tests();
};
#endif
