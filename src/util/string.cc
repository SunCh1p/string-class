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

void String::init(int& size, char* n){
    if(stringArr != nullptr){
        delete [] stringArr;
        mSize = 0;
    }
    mSize = size;
    stringArr = new char[mSize+1];
    for(size_t i = 0; i < mSize; i++){
        stringArr[i] = n[i];
    }
    stringArr[mSize] = '\0';
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

String& String::operator=(const std::string& string){
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
    return *this;
}

char String::operator[](size_t i) const{
    assert(i < mSize && "String-Operator[]: index parameter must be less than String.mSize");
    return stringArr[i];
}

//WORK ON NEXT
size_t String::FindSubstr(std::string string) const{
    size_t n = string.length();
    if(n == 0 || mSize < n){
        return std::string::npos;
    }
    for(size_t i = 0; i <= mSize-n; i++){
        if(stringArr[i] == string[0]){
            bool ans = true;
            for(size_t j = 0; j < string.length(); j++){
                if(stringArr[i+j] != string[j]){
                    ans = false;
                    break;
                }
            }
            if(ans == true){
                return i;
            }
        }
    }
    return std::string::npos;
}

std::string String::GetSubstr(size_t index, size_t len){
    if(index > mSize || mSize < len || (len+index) > mSize){
        return "";
    }
    std::string ans = "";
    for(size_t i = 0; i < len; i++){
        ans += stringArr[index+i];
    }
    return ans;
}