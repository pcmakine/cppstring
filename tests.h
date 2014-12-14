#ifndef TESTS_H
#define TESTS_H
#include "testdriver.h"
#include <map>
#include <string>

class Tests{

std::map<std::string, bool (Tests::*)()> testFunctions;
void testToMap(std::string fname, bool (Tests::*fpt)());

public:
	Tests();
	
	bool testConstructor();
	bool testConstructorWithEmptyString();
	bool testCopyConstructor();
	bool testCopyAssignment();
	bool testMoveConstructor();
	bool testMoveAssignment();

	bool testInsertStringLiteralToBeginning();
	bool testInsertStringLiteralToMiddle();
	bool testInsertStringLiteralToEnd();
	
	bool testInsertMyStringToBeginning();
	bool testInsertMyStringToMiddle();
	bool testInsertMyStringToEnd();
	
	bool testInsertCharToBeginning();
	bool testInsertCharToMiddle();
	bool testInsertCharToEnd();
	
	bool testSize();
	bool testElements();
	bool testSwap();
	bool testPush_back();
	bool testPop_back();
	
	bool testOutputInput();
	bool testBracketOperatorGet();
	bool testBracketOperatorSet();
	
	bool testErase();

    std::map<std::string, bool (Tests::*)()> getTestFunctions();
	
	~Tests();
};
#endif
