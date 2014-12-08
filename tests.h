#ifndef TESTS_H
#define TESTS_H
#include "testdriver.h"
class Tests{
TestDriver* driver;

public:
	Tests();
	void testInsertStringLiteral();
	
	~Tests();
};
#endif