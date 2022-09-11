#include "../include/Foo.h"

#include <iostream>
#include <string>

class Foo::FooImpl {
    public:
        void doThings(const Foo & fooObj) {
            std::cout << "Age: " << std::to_string(fooObj._age) << std::endl;
        }
};


Foo::Foo(uint8_t age) : _fooImpl{}, 
             _age(age) {}

Foo::~Foo() { }

void Foo::doTheThings() {
    _fooImpl->doThings(*this);
}