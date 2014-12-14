#include "myString.h"

//iterator functions
MyString::iterator MyString::begin(){
	return Iterator(*this, 0);
}

MyString::iterator MyString::end(){
	return Iterator(*this, sz);
}

MyString::Iterator::Iterator(MyString& str, int index):
myStr(str), myIndex(index){
}

char& MyString::iterator::operator*(){
	return myStr[myIndex];
}

MyString::iterator& MyString::iterator::operator++(){
	myIndex++;
	return (*this);
}

MyString::iterator MyString::iterator::operator++(int){
	Iterator clone(*this);
	myIndex++;
	return clone;
}

MyString::iterator& MyString::iterator::operator=(const Iterator& other){ 
	myStr[myIndex] = other.myStr[myIndex];
	return (*this);
}

bool MyString::iterator::operator==(const Iterator&other){
	return &myStr == &other.myStr && myIndex == other.myIndex;
}

bool MyString::iterator::operator!=(const Iterator&other){
	return !(*this == other);
}

char* MyString::iterator::operator->(){
	return (&*(*this));
}