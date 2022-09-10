#include "../include/Person.h"
#include <iostream>

class Person::PersonImpl {
    public:
        void greet(const Person &p);
};

void Person::PersonImpl::greet(const Person &p) {
    std::cout << "Hello " << p._name << std::endl;
}


Person::Person(std::string name):
        _name(name),
        _impl(std::make_unique<Person::PersonImpl>()) 
{

}

Person::~Person() {
    
}

void Person::greet() {
    _impl->greet(*this);
}
