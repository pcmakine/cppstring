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


void test(){
    std::cout << "test success" << std::endl;
}

int main(){
TestDriver t;

t.run();


/*MyString a = "abc";

a.insert(0, "yz");
a.print();

a.insert(a.size() -1, "blablaa");
a.print();

MyString b = "";
b.insert(0, "morooo");
b.print();
std::cout << b.size() << std::endl;

b.insert(2, a);

b.print();

b.insert(b.size(), 'u');
b.print();

Tests t;
t.testInsertStringLiteral();

//std::vector<void (*)()> vectoroffunctions;
void (*testpointer)() = test;
//vectoroffunctions.push_back(testpointer);

std::map<void (*)(),std::string> map;

map[testpointer] = "jee";
map.begin()->first();

//vectoroffunctions[0]();

//testpointer();
//test();



/*
std::cout << a << std::endl;

a.swap(b);

std::cout << a << std::endl;

std::cout << b << std::endl;

b.push_back('r');
//b.push_back('a');

std::cout << b << std::endl;

char last = b.pop_back();

std::cout << last << std::endl;*/
//std::cout << t.assertEquals() << std::endl;

return 0;
}

