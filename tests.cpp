#include "tests.h"
#include "myString.h"
#include <iostream>
#include <sstream>

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

bool Tests::testElements(){
    MyString a = "Hello";
	const char* actual = a.elements();
	std::string expected = "Hello";
	return TestDriver::assertEquals(actual, expected);
}

bool Tests::testSize(){
	bool passed = false;
    MyString a = "Hello";
	MyString b = " world!";
    a.insert(2, b);
	int actual = a.size();
	passed = TestDriver::assertEqualsPrimitive(12, 12);
	return passed;
}

bool Tests::testSwap(){
	bool passed = false;
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

bool Tests::testPop_back(){
	bool passed = false;
	MyString a = "Hello!";
	char popped = a.pop_back();
	std::string expected = "Hello";
	passed = TestDriver::assertEquals(a, expected);
	char expectedChar = '!';
	
	passed = TestDriver::assertEqualsPrimitive(popped, expectedChar);
	
	return passed;
}

bool Tests::testErase(){
	bool passed = false;
    MyString actual = "Hello";
	actual.erase(1, 3);
	std::string expected = "Ho";
	passed = TestDriver::assertEquals(actual, expected);
	
	actual.erase(0, 0);
	expected = "o";
	passed = TestDriver::assertEquals(actual, expected);
	
	actual.erase(0,0);
	expected = "";
	passed = TestDriver::assertEquals(actual, expected);
	
	actual = "Hello";

	actual.erase(1, actual.size()-1);

	expected = "H";
	passed = TestDriver::assertEquals(actual, expected);
	
	return passed;
}

bool Tests::testIteratorGet(){
	MyString a = "Hello";
	MyString::iterator iter = a.begin();
	char actual = *iter;
	
	return TestDriver::assertEqualsPrimitive(actual, 'H');
}

bool Tests::testIteratorAdvance(){
	MyString a = "Hello";
	MyString::iterator iter = a.begin();
	iter++;
	char actual = *iter;
	
	return TestDriver::assertEqualsPrimitive(actual, 'e');
}

bool Tests::testIterate(){
	bool passed = true;
	MyString a = "Hello";
	char array[5] = {'H', 'e', 'l', 'l', 'o'};
	int i = 0;
	
	for(MyString::iterator iter = a.begin(); iter != a.end(); ++iter){
		char actual = *iter;
		if(!TestDriver::assertEqualsPrimitive(actual, array[i])){
			passed = false;
			break;
		}
		i++;
	}
	
	return passed;
}

bool Tests::testOutputInput(){
    MyString a = "Hello";	
	std::stringstream ss;
	ss << a;
	MyString b = "";
	ss >> b;

	return TestDriver::assertEquals(a, b);
}

bool Tests::testBracketOperatorGet(){
	bool passed = false;
    MyString a = "Hello";
	char actual = a[0];
	
	passed = TestDriver::assertEqualsPrimitive(actual, 'H');
	actual = a[4];
	passed = TestDriver::assertEqualsPrimitive(actual, 'o');
	
	actual = a[2];
	passed = TestDriver::assertEqualsPrimitive(actual, 'l');
	
	return passed;
}

bool Tests::testBracketOperatorSet(){
    MyString actual = "Hello";
	actual[0] = 'Y';
	MyString expected = "Yello";
	return TestDriver::assertEquals(actual, expected);
}

bool Tests::testEqualityOperator(){
	bool passed = false;
    MyString first = "Hello";
	MyString other = "Hello";
	
	passed = TestDriver::assertEqualsPrimitive(first, other);
	
	first = "";
	other = "";
	
	passed = TestDriver::assertEqualsPrimitive(first, other);
	
	return passed;
}

bool Tests::testInEqualityOperator(){
    MyString first = "Hella";
	MyString other = "Hello";
	
	return TestDriver::assertNotEquals(first, other);
}


Tests::Tests(){

	//constructors
	testToMap("testConstructor", &Tests::testConstructor);
	testToMap("testConstructorWithEmptyString", &Tests::testConstructorWithEmptyString);
	testToMap("testCopyConstructor", &Tests::testCopyConstructor);
	testToMap("testCopyAssignment", &Tests::testCopyAssignment);
	testToMap("testMoveConstructor", &Tests::testMoveConstructor);
	
	//inserts
	testToMap("testInsertStringLiteralToMiddle", &Tests::testInsertStringLiteralToMiddle);
	testToMap("testInsertStringLiteralToEnd", &Tests::testInsertStringLiteralToEnd);
	testToMap("testInsertStringLiteralToBeginning", &Tests::testInsertStringLiteralToBeginning);
	testToMap("testInsertMyStringToBeginning", &Tests::testInsertMyStringToBeginning);
	testToMap("testInsertMyStringToMiddle", &Tests::testInsertMyStringToMiddle);
	testToMap("testInsertMyStringToEnd", &Tests::testInsertMyStringToEnd);
	testToMap("testInsertCharToBeginning", &Tests::testInsertCharToBeginning);
	
	//general functions
	testToMap("testElements", &Tests::testElements);
	testToMap("testSize", &Tests::testSize);
	testToMap("testSwap", &Tests::testSwap);
	testToMap("testPush_back", &Tests::testPush_back);
	testToMap("testPop_back", &Tests::testPop_back);
	testToMap("testErase", &Tests::testErase);
	
	//iterator
	testToMap("testIteratorGet", &Tests::testIteratorGet);
	testToMap("testIteratorAdvance", &Tests::testIteratorAdvance);
	testToMap("testIterate", &Tests::testIterate);
	
	//operators
	testToMap("testOutputInput", &Tests::testOutputInput);
	testToMap("testBracketOperatorGet", &Tests::testBracketOperatorGet);
	testToMap("testBracketOperatorSet", &Tests::testBracketOperatorSet);
	testToMap("testEqualityOperator", &Tests::testEqualityOperator);
	testToMap("testInEqualityOperator", &Tests::testInEqualityOperator);
}



void Tests::testToMap(std::string fname, bool (Tests::*fpt)()){
	testFunctions[fname] = fpt;
}

std::map<std::string, bool (Tests::*)()>  Tests::getTestFunctions(){
    return testFunctions;
}

Tests::~Tests(){
}
