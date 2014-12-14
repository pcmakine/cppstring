#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

class MyString{

public:
	static bool debug;
	MyString();

    MyString(const char *s);

	//copy constructor
    MyString(MyString const& str);

    //move constructor
    MyString(MyString&& str);

    size_t size() const;

    void print() const;
	
	void swap(MyString& str);
	
	void insert(int index, const char* const str);
	
	void insert(int index, const MyString& str);

    void insert(int index, char c);
	
	void push_back(char c);
	
	char pop_back();
	
	void erase(unsigned int start, unsigned int end);
	
	bool compare(const MyString& str);

	//move assignment
    MyString& operator = (MyString&& str);
	
	friend std::ostream& operator<<(std::ostream& os, const MyString& dt);
	
	friend std::istream& operator>>(std::istream &is, MyString& str );
	
	bool operator==(const MyString& str);
	
	bool operator!=(const MyString& str);

    //copy assignment
    MyString& operator = (MyString const& str);

    char operator [](int index) const;
	
	char& operator [](int index);
	
	~MyString();
		
	class Iterator{
		
	public:
		Iterator(MyString& str, int index);
		
		char& operator*();
		
		Iterator& operator++();
		
		Iterator operator++(int);
		
		char* operator->();
		
		Iterator& operator=(const Iterator& other);
		
		bool operator==(const Iterator&other);
		
		bool operator!=(const Iterator&other);
		
	private:
		MyString& myStr;
		int myIndex;

	};
	
	typedef MyString::Iterator iterator;
	
	iterator begin();
	
	iterator end();
	
private:
	friend class Tests;
	friend class TestDriver;
    size_t sz;
    char *arr;
	void strCopy(char* dest, const char* src, int fromIndex, int toIndex, int extractIndex);
	
	char* resize(size_t newSz);
	const char* elements() const;
};
#endif
