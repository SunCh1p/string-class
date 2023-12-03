#include <iostream>
#include "./util/string.h"

int main(){
    String dave("Hello");
    String tmp("Dave");
    std::cout << "TEST\n";
    String result("David");
    result = dave + tmp;
    //String result = dave + tmp;
    std::cout << "TEST\n";
    std::cout << result << std::endl;
    std::cout << result.Size() << std::endl;
    return 0;
}