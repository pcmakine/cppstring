#include "myString.h"
class TestDriver{

        bool assertEquals(MyString& str, MyString& otherStr){
            if(str.size() != otherStr.size()){
                return false;
            }
            int size = str.size();
            for(int i= 0; i < size; i++){
                if(str[i] != otherStr[i]){
                    return false;
                }
            }
            return true;
        }
};
