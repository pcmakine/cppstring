#include "myString.h"
#include <cstring>
#include <iostream>
#include <stdexcept>

bool MyString::debug = false;

MyString::MyString() : MyString(""){
}

MyString::MyString(const char* str):
	sz(strlen(str)), arr(new char[sz+1]){
	if(debug){
		std::cout << "constructor called" << std::endl;
	}
	try{
	   std::strncpy(arr, str, sz*sizeof *arr);
	}catch(...){
		delete[] arr;
		sz = 0;
		throw std::runtime_error("could not create MyString");
	}
	arr[sz] = '\0';
}

MyString::MyString(MyString const& str): 
	sz(str.size()), arr(new char[str.size()+1]){
	if(debug){
		std::cout << "copy constructor called" << std::endl;
	}
    std::strncpy(arr, str.elements(), (sz+1)*sizeof *arr);
}

//copy assignment
MyString& MyString::operator = (MyString const& str){
	if(debug){
		std::cout << "copy assignment called" << std::endl;
	}
	char* temp = new char[str.size()+1];		//let caller handle possible bad alloc
	
	std::strncpy(temp, str.elements(), (str.size()+1)*sizeof *temp);		//+1 to get the end character	
	delete[] arr;
	arr = temp;
	sz = str.size();
	
	return *this;
}

//move constructor; must be compiled with -std=c++11
MyString::MyString(MyString&& str)
   :sz{str.sz}, arr{str.arr}{
   	if(debug){
		std::cout << "move constructor called" << std::endl;
	}

    str.sz = 0;
    str.arr = nullptr;
}

void MyString::print() const{
    std::cout << arr << this << std::endl;
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
	try{
		char* temp = resize(sz + 1);
		std::strncpy(arr, temp,  sz*sizeof *arr);
	}catch(...){
		throw std::runtime_error("MyString resize failed!");
	}
	arr[sz - 1] = c;
	arr[sz] = '\0';
}

void throwForInvalidIndex(int index, int size){
	if(index < 0 || index >= size){
		throw std::out_of_range("index out of range!");
	}
}

void MyString::insert(int index, const char* const str){
	throwForInvalidIndex(index, sz+1);	//+1 because we can insert also after the string
	size_t strSz = strlen(str);
	size_t newSz = sz + strSz;
	
	const char* temp = resize(newSz);	//may throw, but the string's state is fine, let the caller handle the exception
	strCopy(arr, temp, 0, index, 0);
	strCopy(arr, str, index, (index + strSz), 0);
	strCopy(arr, temp, (index + strSz), newSz, index);
	arr[newSz] = '\0';
}

void MyString::insert(int index, const MyString& str){
	insert(index, str.elements());
}

void MyString::insert(int index, char c){
	char charAsArray[2];
	charAsArray[0] = c;
	charAsArray[1] = '\0';
    insert(index, charAsArray);
}

char* MyString::resize(size_t newSz){
	char temp[newSz];
	try{
		if(sz <= newSz){
			std::strncpy(temp, arr, sz*sizeof *arr);
		}else{
			std::strncpy(temp, arr, newSz*sizeof *arr);
		}
	}catch(...){
		throw std::runtime_error("Could not resize MyString");
	}
	delete[] arr;
	
	try{
		arr = new char[newSz+1];	
	}catch(std::bad_alloc const& e){
		arr = new char[sz];			//if the allocation did not work, reverse the array as it was
		std::strncpy(arr, temp, sz*sizeof *temp);
		throw e;
	}

	sz = newSz;
	char* p = temp;
	return p;
}


char MyString::pop_back(){	//pop_back as demonstrated in the instructions
	char c = '\0';
	if(sz > 0){
		c = arr[sz - 1];
		try{
			char* temp = resize(sz-1);
			std::strncpy(arr, temp,  sz*sizeof *arr);
		}catch(...){
			throw std::runtime_error("MyString resize failed!");
		}
		arr[sz] = '\0';
	}
	return c;
}

void MyString::erase(int start, int end){
	if(start < 0 || end >= sz || start > end){
		throw std::out_of_range("Bad index!");
	}
	
	char backup[sz+1];
	
	strncpy(backup, arr, sz*sizeof *arr);
	backup[sz] = '\0';
	
	size_t newSz = sz - (end - start +1);	//+1 because the function is inclusive for both start and end
	char temp[newSz];
	strCopy(temp, arr, 0, start, 0);
	strCopy(temp, arr, start, sz, end+1);
	
	delete[] arr;
	
	try{
		arr = new char[newSz+1];
		std::strncpy(arr, temp, sz*sizeof *temp);
	}catch(std::bad_alloc const& e){
		arr = new char[sz];			//if the allocation did not work, reverse the array as it was
		std::strncpy(arr, backup, sz*sizeof *backup);
		arr[sz] = '\0';
		throw e;
	}
	sz = newSz;
}

void MyString::strCopy(char* dest, const char* src, int fromIndex, int toIndex, int srcExtractIndex){
	for(int i = fromIndex; i < toIndex; i++){
		dest[i] = src[srcExtractIndex];
		srcExtractIndex++;
	}
}

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

//move assignment
MyString& MyString::operator = (MyString&& str){
	if(this == &str){	//same address (same object)
		return *this;	//just return *this
	}
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

std::istream& operator>>(std::istream &is, MyString& str ){
	is.seekg (0, is.end);
    int size = is.tellg();
    is.seekg (0, is.beg);
	
	try{
		str.resize(size);
		is >> str.arr;     
		str.arr[size] = '\0';		
	}catch(...){
		throw std::runtime_error("Could not read the stream to MyString!");
	}

	return is;
}

char MyString::operator [](int index) const{
	throwForInvalidIndex(index, sz);
    return *(arr+index);
}

char& MyString::operator [](int index){
	throwForInvalidIndex(index, sz);
    return arr[index];
}

bool MyString::operator==(const MyString& str){
	if(sz != str.size()){
		return false;
	}
	for(int i= 0; i < sz; i++){
		if(arr[i] != str[i]){
			return false;
		}
	}
	return true;
}

bool MyString::operator!=(const MyString& str){
	return !(*this == str);
}

MyString::~MyString(){
   	if(debug){
		std::cout << "destructor called" << std::endl;
	}
    delete[] arr;
}


