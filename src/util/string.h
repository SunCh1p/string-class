#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string>
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
        void init(int& size, char n[]);
        //bool CheckEqual(String& otherString);
        //concantenate two strings with + operator
        //find substring and return starting index of substring
        //return substring that is length of substring
        //able to be displayed with cout
        //return length of string object
        //return character at index
        //copy string types from one to the other through functions or assignment
        //set string to new string using assignment operator
        //override + operator
        //return const char* version of the string
        //operator functions
        bool operator==(const String& string) const;
        String operator+(const String& string) const;
        String& operator=(const String& string);

        //friend functions

        friend std::ostream& operator<<(std::ostream& out, String& string);
        
    private:
        char* stringArr;
        size_t mSize;
};

#endif