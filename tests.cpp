#include "tests.h"
#include "myString.h"
#include <iostream>

bool Tests::testConstructor(){
    MyString a = "Hello";
	std::string correct = "Hello";
	return TestDriver::assertEquals(a, correct);
}

bool Tests::testConstructorWithEmptyString(){
    MyString a = "";
	std::string correct = "";
	return TestDriver::assertEquals(a, correct);
}

bool Tests::testCopyConstructor(){
    MyString a = "Hello";
	MyString b = a;
	return TestDriver::assertEquals(b, a);
}

bool Tests::testCopyAssignment(){
	MyString expected = "Hello";
	MyString b = "world!";
	b = expected;
	return TestDriver::assertEquals(b, expected);
}

bool Tests::testMoveConstructor(){
	MyString expected = "hello";
	MyString a = "a";
	a = std::move(expected);
	expected = "hello";
	return TestDriver::assertEquals(a, expected);
}

bool Tests::testInsertStringLiteralToEnd(){
    MyString a = "Hello";
    a.insert(a.size(), " world!");
    MyString b = "Hello world!";
	return TestDriver::assertEquals(a, b);
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
	MyString b = "w";
    a.insert(3, b);
    MyString correct = "Helwlo";
	return TestDriver::assertEquals(a, correct);
}

bool Tests::testInsertMyStringToEnd(){
    MyString a = "Hello";
	MyString b = " world!";
    a.insert(a.size(), b);
    MyString correct = "Hello world!";
	return TestDriver::assertEquals(a, correct);
}

bool Tests::testInsertCharToBeginning(){
    MyString a = "Hello";
	char b = 'c';
    a.insert(0, b);
    MyString correct = "cHello";
	return TestDriver::assertEquals(a, correct);
}

bool Tests::testSize(){
    MyString a = "Hello";
	MyString b = " world!";
    a.insert(2, b);
	int actual = a.size();
	return TestDriver::assertEquals(actual, 12);
}

bool Tests::testElements(){
    MyString a = "Hello";
	const char* actual = a.elements();
	std::string expected = "Hello";
	return TestDriver::assertEquals(actual, expected);
}

bool Tests::testSwap(){
	bool passed = true;
    MyString a = "Hello";
	MyString b = "world!";
	MyString c = "t";
	a.swap(b);

	std::string expected = "world!";
	passed = TestDriver::assertEquals(a, expected);
	
	expected = "Hello";
	passed = TestDriver::assertEquals(b, expected);
	
	c.swap(a);
	expected = "world!";
	passed = TestDriver::assertEquals(c, expected);
	
	return passed;
}

bool Tests::testPush_back(){
    char a = 'a';
	MyString b = "world!";
	b.push_back(a);
	std::string expected = "world!a";

	return TestDriver::assertEquals(b, expected);
}

Tests::Tests(){
	testToMap("testConstructor", &Tests::testConstructor);
	testToMap("testConstructorWithEmptyString", &Tests::testConstructorWithEmptyString);
	testToMap("testCopyConstructor", &Tests::testCopyConstructor);
	testToMap("testCopyAssignment", &Tests::testCopyAssignment);
	testToMap("testMoveConstructor", &Tests::testMoveConstructor);
	
	testToMap("testInsertStringLiteralToMiddle", &Tests::testInsertStringLiteralToMiddle);
	testToMap("testInsertStringLiteralToEnd", &Tests::testInsertStringLiteralToEnd);
	testToMap("testInsertStringLiteralToBeginning", &Tests::testInsertStringLiteralToBeginning);
	testToMap("testInsertMyStringToBeginning", &Tests::testInsertMyStringToBeginning);
	testToMap("testInsertMyStringToMiddle", &Tests::testInsertMyStringToMiddle);
	testToMap("testInsertMyStringToEnd", &Tests::testInsertMyStringToEnd);
	testToMap("testInsertCharToBeginning", &Tests::testInsertCharToBeginning);
	
	testToMap("testElements", &Tests::testElements);
	testToMap("testSize", &Tests::testSize);
	testToMap("testSwap", &Tests::testSwap);
	testToMap("testPush_back", &Tests::testPush_back);
}

void Tests::testToMap(std::string fname, bool (Tests::*fpt)()){
	testFunctions[fname] = fpt;
}

std::map<std::string, bool (Tests::*)()>  Tests::getTestFunctions(){
    return testFunctions;
}

Tests::~Tests(){
}
