#include "testdriver.h"
#include "tests.h"
#include "myString.h"
#include <iostream>

Tests::Tests(){
	driver = new TestDriver();
    void (Tests::*stringLiteralPtr)() = &Tests::testInsertStringLiteral;
    testFunctions[stringLiteralPtr] = "testInsertStringLiteral";

}

void Tests::testInsertStringLiteral(){
    MyString a = "Hello";
    a.insert(a.size(), " world!");
    MyString b = "Hello world!";
    if(driver->assertEquals(a, b, "failed")){
        std::cout << "testInsertStringLiteral success!" << std::endl;
    }
}

void testInsertChar(){

}

std::map<void (Tests::*)(),std::string>  Tests::getTestFunctions(){
    return testFunctions;
}

Tests::~Tests(){
	delete driver;
}
