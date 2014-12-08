#include "myString.h"
#include "testdriver.cpp"
#include <iostream>
#include <cstring>

int main(){
MyString a = "abc";

a.insert(0, "yz");
a.print();

a.insert(a.size() -1, "blablaa");
a.print();

MyString b = "";
b.insert(0, "morooo");
b.print();
std::cout << b.size() << std::endl;
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

TestDriver t;
//std::cout << t.assertEquals() << std::endl;

return 0;
}

