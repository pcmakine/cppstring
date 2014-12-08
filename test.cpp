#include "myString.h"
#include "testdriver.cpp"
#include <iostream>
#include <cstring>

int main(){
MyString a = "moroooooafjdjlfsjlkj";

a.print();

MyString b = a;

//assertEquals(b, a);
a = "jjj";
b.print();

b = a;

b.print();
b.push_back('a');
b.print();

std::cout << b.pop_back() << std::endl;
b.print();

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

