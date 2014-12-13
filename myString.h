#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

class MyString{
	friend class Tests; //forward declaration; needed for the compiler
	friend class TestDriver; //forward declaration; needed for the compiler
    size_t sz;
    char *arr;
	void strCopy(char* dest, const char* src, int fromIndex, int toIndex, int extractIndex);
	
	char* resize(size_t newSz);
	const char* elements() const;
public:
	static bool debug;
	MyString();

    MyString(const char *s);

	//copy constructor
    MyString(MyString const& str);

    //move constructor
    MyString(MyString&& str);

    //move assignment
    MyString& operator = (MyString&& str);

    int size() const;

    void print() const;
	
	void swap(MyString& str);
	
	void insert(int index, const char* str);
	
	void insert(int index, MyString& str);

    void insert(int index, char c);
	
	void push_back(char& c);
	
	char pop_back();

	friend std::ostream& operator<<(std::ostream& os, const MyString& dt);
	
	friend std::istream& operator>>(std::istream &is, MyString& str );

    //copy assignment
    MyString& operator = (MyString const& str);

    char operator [](int index);
	
	~MyString();

};
#endif
