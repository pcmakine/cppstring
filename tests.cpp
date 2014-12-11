#include "tests.h"
#include "myString.h"
#include <iostream>

void Tests::insertPointerToFunctionMap(std::string fname, bool (Tests::*fpt)()){
	testFunctions[fname] = fpt;
}

Tests::Tests(){
	insertPointerToFunctionMap("testInsertStringLiteralToMiddle", &Tests::testInsertStringLiteralToMiddle);
	insertPointerToFunctionMap("testInsertStringLiteralToEnd", &Tests::testInsertStringLiteralToEnd);
	insertPointerToFunctionMap("testInsertStringLiteralToBeginning", &Tests::testInsertStringLiteralToBeginning);
	insertPointerToFunctionMap("testConstructor", &Tests::testConstructor);
}

bool Tests::testConstructor(){
    MyString a = "Hello";
	std::string correct = "HEllo";
	TestDriver::assertEquals(a, correct);
}

bool Tests::testInsertStringLiteralToEnd(){
    MyString a = "Hello";
    a.insert(a.size(), " world!");
    MyString b = "Hello world!";
	TestDriver::assertEquals(a, b, "failed");
}

bool Tests::testInsertStringLiteralToBeginning(){
    MyString a = "Hello";
    a.insert(0, "world! ");
    MyString b = "world! Hello";
	TestDriver::assertEquals(a, b);
}

bool Tests::testInsertStringLiteralToMiddle(){
    MyString a = "Hello";
    a.insert(2, "world!");
    MyString b = "Heworld!llo";
	TestDriver::assertEquals(a, b);
}

bool testInsertChar(){

}

std::map<std::string, bool (Tests::*)()>  Tests::getTestFunctions(){
    return testFunctions;
}

Tests::~Tests(){
}
