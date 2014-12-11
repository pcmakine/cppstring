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
	insertPointerToFunctionMap("testInsertMyStringToBeginning", &Tests::testInsertMyStringToBeginning);
	insertPointerToFunctionMap("testInsertMyStringToMiddle", &Tests::testInsertMyStringToMiddle);
	insertPointerToFunctionMap("testInsertMyStringToEnd", &Tests::testInsertMyStringToEnd);
}

bool Tests::testConstructor(){
    MyString a = "Hello";
	std::string correct = "Hello";
	return TestDriver::assertEquals(a, correct);
}

bool Tests::testInsertStringLiteralToEnd(){
    MyString a = "Hello";
    a.insert(a.size(), " world!");
    MyString b = "Hello world!";
	return TestDriver::assertEquals(a, b, "failed");
}

bool Tests::testInsertStringLiteralToBeginning(){
    MyString a = "Hello";
    a.insert(0, "world! ");
    MyString b = "world! Hello";
	return TestDriver::assertEquals(a, b);
}

bool Tests::testInsertStringLiteralToMiddle(){
    MyString a = "Hello";
    a.insert(2, "world!");
    MyString b = "Heworld!llo";
	return TestDriver::assertEquals(a, b);
}

bool Tests::testInsertMyStringToBeginning(){
    MyString a = "Hello";
	MyString b = "world!";
    a.insert(0, b);
    MyString correct = "world!Hello";
	return TestDriver::assertEquals(a, correct);
}

bool Tests::testInsertMyStringToMiddle(){
    MyString a = "Hello";
	MyString b = "world!";
    a.insert(3, b);
    MyString correct = "Helworld!lo";
	return TestDriver::assertEquals(a, correct);
}

bool Tests::testInsertMyStringToEnd(){
    MyString a = "Hello";
	MyString b = " world!";
    a.insert(a.size(), b);
    MyString correct = "Hello world!";
	return TestDriver::assertEquals(a, correct);
}

bool testInsertChar(){

}

std::map<std::string, bool (Tests::*)()>  Tests::getTestFunctions(){
    return testFunctions;
}

Tests::~Tests(){
}
