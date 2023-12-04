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
        size_t FindSubstr(std::string string) const;
        std::string GetSubstr(size_t i, size_t len);
        
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