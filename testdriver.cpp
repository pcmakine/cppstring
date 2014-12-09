#include "myString.h"
#include "testdriver.h"
#include <iostream>
#include <string>

TestDriver::TestDriver(){
}

bool TestDriver::assertEquals(MyString& str, MyString& otherStr, std::string printIfFailed){
	if(str.size() != otherStr.size()){
		return false;
	}
	int size = str.size();
	for(int i= 0; i < size; i++){
		if(str[i] != otherStr[i]){
            std::cout << "failed: " << printIfFailed << std::endl;
			return false;
		}
	}

	return true;
}
