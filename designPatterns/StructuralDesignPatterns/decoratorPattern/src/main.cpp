#include <iostream>
#include "../include/decorator.hpp"

int main() {

    // one downside of the dynamic decorator is that once you decorated your object
    // you don't have access to the underlying object. For example if the user wants
    // to call resize on the colored square it would not be possible.

    Square square {5};
    dynamicDecorator::ColoredShape c_square{square, Color::red};
    std::cout << c_square.str() << std::endl; 

    // Static decorator can prevent the above mentioned problem
    staticDecorator::TransparentShape<staticDecorator::ColoredShape<Circle>> my_circle(0, Color::blue, 10);
    std::cout << my_circle.str() << std::endl;
    my_circle.resize(3);
    std::cout << my_circle.str() << std::endl;
    return 0;
}