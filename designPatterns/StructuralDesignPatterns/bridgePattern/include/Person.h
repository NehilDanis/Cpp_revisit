#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <memory>

/*
Pimple idiom(Pointer to implementation): manifestation of the bridge pattern
it is used to hide the implementation details because
you only ship the header to your customer. This way if you have some secret implementation 
that you dont even want to show the function name in the private part of you class's header.
*/


class Person {
    public:
        Person(std::string name);
        ~Person();
        // move operators
        Person(Person && p) = default;
        Person& operator=(Person &&p) = default;

        // delete copy constructors
        Person(const Person& p) = delete;
        Person& operator=(const Person &p) = delete;

        void greet();
    private:
        std::string _name;
        class PersonImpl;
        std::unique_ptr<PersonImpl> _impl;
};


#endif /* PERSON_H */