/*compile with this command:
g++ -Wall -std=c++11 myString.cpp tests.cpp main.cpp testdriver.cpp -o stringtest
*/

#include "myString.h"
#include "tests.h"
#include "testdriver.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <map>

MyString test(){
}

int main(int argc, char* argv[]){

	std::string testArg = "run";
	std::string debugArg = "debug";

	if(argc == 1){
		MyString a = "moro";
		MyString b = a;
	}
	else if(testArg.compare(argv[1]) == 0){
		TestDriver t;
		t.run();
	}else if(debugArg.compare(argv[1]) == 0){
		MyString::debug = true;
	}
	
/*	std::cout << "---------" << std::endl;

	std::string expected = "world!";
	//passed = TestDriver::assertEquals(a, expected);
	
	expected = "Hello";
	//passed = TestDriver::assertEquals(b, expected);
	
	c.swap(a);
	expected = "world!";
	//passed = TestDriver::assertEquals(c, expected);
*/

	return 0;
}

