#include <iostream>
#include "./util/string.h"

int main(){
    String dave("Hello");
    std::cout << dave.FindSubstr("ll") << std::endl;
    std::cout << dave.GetSubstr(1,3) << std:: endl;
    std::cout << "SUCCESS" << std::endl;
    return 0;
}