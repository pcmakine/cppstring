#ifndef ITERATOR_H
#define ITERATOR_H
#include "myString.h"

class MyIterator{


public:

    MyIterator(MyString& mystr, int myoffset);

    char& operator*();

    MyIterator& operator++();

    ~MyIterator();
};

#endif // ITERATOR_H
