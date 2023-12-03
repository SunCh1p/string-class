#include <iostream>
#include "./util/string.h"

int main(){
    String dave("Hello");
    String tmp("Dave");
    std::cout << "TEST\n";
    String result("David");
    result = dave + tmp;
    std::cout << result << std::endl;
    result = "asdef";
    std::cout << result << std::endl;
    std::cout << result[0] << std::endl;
    return 0;
}