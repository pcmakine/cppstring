#include "iterator.h"


MyIterator::MyIterator(MyString& mystr, int myoffset): str(mystr),  offset(myoffset){

}

/*char& MyIterator::operator*() {
    return str[offset];
}*/

MyIterator& MyIterator::operator++() { ++offset; return *this; }

