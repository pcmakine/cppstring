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

int main(){
/*	MyString a;
	a.print();
	*/
	TestDriver t;
	t.run();


	return 0;
}

