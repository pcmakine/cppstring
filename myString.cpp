#include "myString.h"
#include <cstring>
#include <iostream>

MyString::MyString() : MyString(""){
}

MyString::MyString(const char* str){
//	std::cout << "constructor called" << std::endl;
    sz = strlen(str);	
    arr = new char[sz+1];
	std::memcpy(arr, str, sz*sizeof *arr);
	arr[sz] = '\0';
}

MyString::MyString(MyString const& str){
//	std::cout << "copy constructor called" << std::endl;
    sz = str.size();
    arr = new char[sz];
    std::memcpy(arr, str.elements(), sz*sizeof *arr);
}

//copy assignment
MyString&  MyString::operator = (MyString const& str){
//	std::cout << "copy assignment called" << std::endl;
    sz = str.size();
    arr = new char[sz];
    std::memcpy(arr, str.elements(), sz*sizeof *arr);
}

//move constructor; must be compiled with -std=c++11
MyString::MyString(MyString&& str)
//	std::cout << "move constructor called" << std::endl;
   :sz{str.sz}, arr{str.arr}{
    str.sz = 0;
    str.arr = nullptr;
}

void MyString::print(){
    std::cout << arr << std::endl;
}

int MyString::size() const{
    return sz;
}

const char *MyString::elements() const{
    const char *p = arr;
    return p;
}

void MyString::swap(MyString& str){
	MyString temp = str;
	str = *this;
	*this = temp;
}

void MyString::push_back(char c){
	char* temp = resize(sz + 1);
	std::memcpy(arr, temp,  sz*sizeof *arr);
	arr[sz - 1] = c;
	arr[sz] = '\0';
}

//what to do if index is bigger than the size of the original string?
void MyString::insert(int index, const char* str){
	size_t strSz = strlen(str);
	size_t newSz = sz + strSz;
	
	const char* temp = resize(newSz);
	strCopy(arr, temp, 0, index, 0);
	strCopy(arr, str, index, (index + strSz), 0);
	strCopy(arr, temp, (index + strSz), newSz, index);
	arr[newSz] = '\0';
}

void MyString::insert(int index, MyString& str){
	insert(index, str.elements());
}

void MyString::insert(int index, const char c){
    const char* p = &c;
    insert(index, p);
}

void MyString::strCopy(char* dest, const char* src, int fromIndex, int toIndex, int srcExtractIndex){
	for(int i = fromIndex; i < toIndex; i++){
		dest[i] = src[srcExtractIndex];
		srcExtractIndex++;
	}
}

char* MyString::resize(size_t newSz){
	char temp[newSz];
	if(sz <= newSz){
		std::memcpy(temp, arr, sz*sizeof *arr);
	}else{
		std::memcpy(temp, arr, newSz*sizeof *arr);
	}

	delete[] arr;
	sz = newSz;
	arr = new char[sz + 1];
	char* p = temp;
	return p;
}


char MyString::pop_back(){	//pop_back as demonstrated in the instructions
	char c = '\0';
	if(sz > 0){
		c = arr[sz - 1];
		char* temp = resize(sz-1);
		std::memcpy(arr, temp,  sz*sizeof *arr);
		arr[sz] = '\0';
	}
	return c;
}

//move assignment
MyString& MyString::operator = (MyString&& str){
   delete[] arr;
   arr = str.arr;
   sz = str.sz;

   str.arr = nullptr;
   str.sz = 0;
   return *this;
}

std::ostream& operator<<(std::ostream& os, const MyString& str){
    os << str.arr;
    return os;
}

char MyString::operator [](int index){
    char p = *(arr + index);
    return p;
}

MyString::~MyString(){
    delete[] arr;
}



