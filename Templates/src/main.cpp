#include <iostream>
#include <string>
#include "../includes/Template.hpp"
#include <concepts>

using namespace testtemplate;

template<typename T>
concept Printable = requires (T a)
{
    std::cout << a;
};


template<Printable T>
void print(T element) {
    std::cout << "Templated Print" << std::endl;
    std::cout << element << std::endl;
};

void print(int num) {
    std::cout << "Non templated print";
    std::cout << num << std::endl;
}

struct Test {
    int num;
};

/*
The Test object can only be printable if a proper output operator is defined as below.
*/
std::ostream & operator<<(std::ostream & out, const Test &obj) {
    out << obj.num;
    return out;
}

int main() {

    TemplateTest<std::string> textObj("Hello");
    TemplateTest<int> intObj(5);
    std::cout << textObj << std::endl;
    std::cout << intObj << std::endl;

    /*
    If the compiler finds a function which directly fits the type of the parameters passed, it will
    use non template version.
    */
    print(5); // will call the non templated print

    /*
    However if the function call is done by explicitly using <>, even it the type is not defined, the compiler 
    will do the type inference by looking at the parameter passed.
    */
    print<>(5); // will call the templated version


    /*
    Tho if the proper << operator is defined for the given type then the oject will be printable.
    */
    print<Test>(Test());  // will not compile  since the type doesnt match with the printable concept



    return 0;
}