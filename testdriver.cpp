#include "myString.h"
#include "testdriver.h"
#include "tests.h"
#include <iostream>
#include <string>
#include <stdexcept>

TestDriver::TestDriver(){
	tests = new Tests();
	testFuncts = tests->getTestFunctions();
}

bool TestDriver::passTest(){
	std::cout << "Assert passed!" << std::endl;
	return true;
}

bool TestDriver::assertEqualsStdString(MyString& actual, std::string& expected){
	if(expected.compare(actual.elements()) == 0){
		return passTest();
	}
	return failTest(actual, expected);
}

void printResults(int passed, int failed, std::vector<int>& failedTests){
	std::cout << "-----------------------" << std::endl;
	std::cout << "Totals:" << std::endl;
	std::cout << "Passed: " << passed << " tests" << std::endl;
	std::cout << "Failed: " << failed << " tests" << std::endl;
	
	if(failedTests.size() > 0){
		std::cout << "Failed tests were: " << std::endl;
	}
	
	for(std::vector<int>::size_type i= 0; i != failedTests.size(); i++){
		if(i != failedTests.size()-1){
			std::cout << failedTests[i] << ", ";
		}else{
			std::cout << failedTests[i] << std::endl;
		}
	}
}

void TestDriver::run(){                         
	passed = 0;
	failed = 0;

	std::map<std::string, bool (Tests::*)()>::iterator iter;

	int testNum = 1;
	std::cout << "Running tests...." << std::endl;
	for(iter = testFuncts.begin(); iter != testFuncts.end(); ++iter){
		std::cout << "Test "<< passed + failed +1 << "/" << testFuncts.size() << " " << iter->first  << " executing... " << std::endl;
		try{
			if(runSingle(iter, testFuncts)){
				passed++;
			}else{
				failedTests.push_back(passed + failed + 1);
				failed++;
			}
		}catch(const std::exception &exc){
			std::cerr << "Test caused an unexpected error: "<< exc.what() << std::endl;
			std::cout << "Test failed" << std::endl;
			failed++;
		}
	}
	printResults(passed, failed, failedTests);
}


bool TestDriver::runSingle(std::map<std::string, bool (Tests::*)()>::iterator iter, std::map<std::string, bool (Tests::*)()> testFuncts){
	bool (Tests::*fpointer)() = iter->second;
	return(tests->*fpointer)();
}

bool TestDriver::runSingleByName(std::string functionName){
	bool success = false;
	std::map<std::string, bool (Tests::*)()>::iterator iter;
	
	iter = testFuncts.find(functionName);
	bool (Tests::*fpointer)() = iter->second;
	if(iter != testFuncts.end()){
		std::string str = iter->first;
		
		try{
			success = (tests->*fpointer)();
		}catch(const std::exception &exc){
			std::cerr << "Test caused an unexpected error: "<< exc.what() << std::endl;
			std::cout << "Test failed" << std::endl;
		}
		success;
	}
	return false;
}

TestDriver::~TestDriver(){
	delete tests;
}

