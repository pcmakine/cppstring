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

template<typename T>
bool test(T arg1, T arg2){
	if(arg1 == arg2){
		return true;
	}
	return false;
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
		//t.runSingle("testSize");
		t.run();
	}else if(debugArg.compare(argv[1]) == 0){
		MyString::debug = true;
	}

	return 0;
}

