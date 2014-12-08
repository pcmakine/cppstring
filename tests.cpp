#include "testdriver.h"
#include "tests.h"
#include "myString.h"
#include <iostream>

Tests::Tests(){
	driver = new TestDriver();
}

void Tests::testInsertStringLiteral(){
	MyString a = "Hello";
	a.insert(a.size(), " world!");
	MyString b = "Hello world!";
	if(driver->assertEquals(a, b)){
		std::cout << "testInsertStringLiteral success!" << std::endl;
	}
}

Tests::~Tests(){
	delete driver;
}