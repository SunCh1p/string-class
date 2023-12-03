#include "string.h"

String::String(){
    stringArr = new char[0];
    mSize = 0;
}

String::String(std::string string){
    if(stringArr!=nullptr or mSize != 0){
        delete [] stringArr;
        stringArr = nullptr;
        mSize = 0;
    }
    mSize = string.length();
    stringArr = new char[mSize];
    for(size_t i = 0; i < mSize; i++){
        stringArr[i] = string[i];
    }   
}

String::~String(){
    delete [] stringArr;
}

String::String(const String& other){
    //check if strings are not the same or not nullptr
    if(stringArr != nullptr){
        delete [] stringArr;
        mSize = 0;
    }
    if(this != &other){
        stringArr = new char[other.mSize];
        mSize = other.mSize;
        for(size_t i = 0; i < mSize; i++){
            stringArr[i] = other.stringArr[i];
        }
    }
}

std::ostream& String::print(std::ostream& outs) const{
    for(size_t i = 0; i < mSize; i++){
        outs << stringArr[i];
    }
    return outs;
}

std::ostream& operator<<(std::ostream& out, String& string){
    string.print(out);
    return out;
}

bool String::CheckEqual(const String& otherString) const{
    if(mSize != otherString.mSize){
        return false;
    }
    for(size_t i = 0; i < mSize; i++){
        if(stringArr[i] != otherString.stringArr[i]){
            return false;
        }
    }
    return true;
}

bool String::operator==(const String& string) const{
    return CheckEqual(string);
}

void String::init(int& size, char n[]){
    if(stringArr != nullptr){
        delete [] stringArr;
        mSize = 0;
    }
    mSize = size;
    stringArr = new char[mSize+1];
    for(size_t i = 0; i < mSize; i++){
        stringArr[i] = n[i];
    }
    //stringArr[mSize] = '\0';
}

String String::operator+(const String& string) const{
    int size = mSize+string.mSize;
    char data[size];
    for(size_t i = 0; i < mSize; i++){
        data[i] = stringArr[i];
    }
    for(size_t i = mSize; i < size; i++){
        data[i] = string.stringArr[i-mSize];
    }
    String res;
    res.init(size, data);
    return res;
}

String& String::operator=(const String& string){
    if(stringArr != nullptr){
        delete [] stringArr;
        mSize = 0;
    }
    mSize = string.mSize;
    stringArr = new char[mSize];
    for(size_t i = 0; i < mSize; i++){
        stringArr[i] = string.stringArr[i];
    }

    return *this;
}