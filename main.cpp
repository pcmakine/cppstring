/*compile with this command:
g++ -std=c++11 -Wall -o stringtest.exe main.cpp myString.cpp tests.cpp testdriver.cpp iterator.cpp -DNDEBUG
*/

#include "myString.h"
#include "tests.h"
#include "testdriver.h"

int main(){
	TestDriver t;
	//t.runSingleByName("testErase");
	t.run();

	return 0;
}

