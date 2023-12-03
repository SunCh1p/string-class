#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
class String{
    public:
        //default constructor
        String();
        //parameterized constructor
        String(std::string string);
        //Destructor
        ~String();
        //copy constructor
        String(const String& other);

        //getter functions
        inline size_t Size(){return mSize;}

        //basic functions
        std::ostream& print(std::ostream& outs) const;
        bool CheckEqual(const String& otherString) const;
        void init(int& size, char* n);

        //find substring and return starting index of substring
        size_t substr(std::string& string) const;
        //return substring that is length of substring
        //copy string types from one to the other through functions or assignment
        //return const char* version of the string
        
        //operator functions
        bool operator==(const String& string) const;
        String operator+(const String& string) const;
        String& operator=(const String& string);
        String& operator=(const std::string& string);
        char operator[](size_t i) const;

        //friend functions
        friend std::ostream& operator<<(std::ostream& out, String& string);
        
    private:
        char* stringArr;
        size_t mSize;
};

#endif