#include "myString.h"
#include "testdriver.h"
#include "tests.h"
#include <iostream>
#include <string>

TestDriver::TestDriver(){
	tests = new Tests();
	testFuncts = tests->getTestFunctions();
}

bool TestDriver::passTest(){
	std::cout << "Assert passed!" << std::endl;
	return true;
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

bool TestDriver::assertEquals(const char* actual, std::string& expected){
	if(expected.compare(actual) == 0){
		return passTest();
	}
	return failTest(actual, expected);
}

bool TestDriver::assertEquals(MyString& actual, std::string& expected){
	if(expected.compare(actual.elements()) == 0){
		return passTest();
	}
	return failTest(actual, expected);
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

	std::map<std::string, bool (Tests::*)()>::iterator iter;

	int testNum = 1;
	std::cout << "Running tests...." << std::endl;
	for(iter = testFuncts.begin(); iter != testFuncts.end(); ++iter){
		std::cout << "Test "<< passed + failed +1 << "/" << testFuncts.size() << " " << iter->first  << " executing... " << std::endl;
		if(runSingle(iter, testFuncts)){
			passed++;
		}else{
			failed++;
		}
	}
	printResults(passed, failed);
}

bool TestDriver::runSingle(std::string functionName){
	std::map<std::string, bool (Tests::*)()>::iterator iter;
	
	iter = testFuncts.find(functionName);
	
	if(iter != testFuncts.end()){
		std::string str = iter->first;
		
		bool (Tests::*fpointer)() = iter->second;
		return(tests->*fpointer)();
	}
	return false;
}

bool TestDriver::runSingle(std::map<std::string, bool (Tests::*)()>::iterator iter, std::map<std::string, bool (Tests::*)()> testFuncts){
	std::string str = iter->first;

	bool (Tests::*fpointer)() = iter->second;
	return(tests->*fpointer)();
}

TestDriver::~TestDriver(){
	delete tests;
}

