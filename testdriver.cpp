#include "myString.h"
#include "testdriver.h"
#include "tests.h"
#include <iostream>
#include <string>

TestDriver::TestDriver(){
}

bool TestDriver::failTest(){
	std::cout << "failed!" << std::endl;
	return false;
}

bool TestDriver::failTest(MyString& actual, MyString& expected){
	std::cout << "failed!\n" << "Expected: " << expected << "\nActual: " << actual << std::endl;
	return false;
}

bool TestDriver::passTest(){
	std::cout << "passed!" << std::endl;
	return true;
}

bool TestDriver::assertEquals(MyString& str, std::string& otherStr){
	int size = str.size();
	if(size != otherStr.size()){
		return failTest();
	}
	for(int i= 0; i < size; i++){
		if(str[i] != otherStr[i]){
			return failTest();
		}
	}
	return passTest();
}

bool TestDriver::assertEquals(MyString& actual, MyString& expected){
	int size = actual.size();
	if(size != expected.size()){
		return failTest(actual, expected);
	}
	for(int i= 0; i < size; i++){
		if(actual[i] != expected[i]){
			return failTest(actual, expected);
		}
	}
	return passTest();
}

bool runSingle(Tests& tests, std::map<std::string, bool (Tests::*)()>::iterator iter, std::map<std::string, bool (Tests::*)()> testFuncts){
	std::string str = iter->first;

	bool (Tests::*fpointer)() = iter->second;
	return(tests.*fpointer)();
}

void printResults(int passed, int failed){
	std::cout << "-----------------------" << std::endl;
	std::cout << "Totals:" << std::endl;
	std::cout << "Passed: " << passed << " tests" << std::endl;
	std::cout << "Failed: " << failed << " tests" << std::endl;
}

void TestDriver::run(){
	passed = 0;
	failed = 0;

	Tests tests;
	std::map<std::string, bool (Tests::*)()> testFuncts = tests.getTestFunctions();
	std::map<std::string, bool (Tests::*)()>::iterator iter;

	int testNum = 1;
	std::cout << "Running tests...." << std::endl;
	for(iter = testFuncts.begin(); iter != testFuncts.end(); ++iter){
		std::cout << "Test "<< passed + failed << "/" << testFuncts.size() << " " << iter->first  << " executing... ";
		if(runSingle(tests, iter, testFuncts)){
			passed++;
		}else{
			failed++;
		}
	}
	printResults(passed, failed);
	
}




