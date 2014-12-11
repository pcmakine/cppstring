#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
class MyString{
    size_t sz;
    char *arr;
	
	void strCopy(char* dest, const char* src, int fromIndex, int toIndex, int extractIndex);
	
	char* resize(size_t newSz);
public:
	MyString();

    MyString(const char *s);

	//copy constructor
    MyString(MyString const& str);

    //move constructor
    MyString(MyString&& str);

    //move assignment
    MyString& operator = (MyString&& str);

    int size() const;

    void print();

    const char *elements() const;
	
	void swap(MyString& str);
	
	void push_back(char c);
	
	void insert(int index, const char* str);
	
	void insert(int index, MyString& str);

    void insert(int index, char c);
	
	char pop_back();

	friend std::ostream& operator<<(std::ostream& os, const MyString& dt);

    //copy assignment
    MyString& operator = (MyString const& str);

    char operator [](int index);
	
	~MyString();
};
#endif
