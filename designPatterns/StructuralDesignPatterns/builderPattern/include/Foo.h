#ifndef FOO_H
#define FOO_H

#include "pimpl.hpp"

class Foo {
    private:
        class FooImpl;
        pimpl<FooImpl> _fooImpl;
        uint8_t _age;
    public:
        explicit Foo(uint8_t age);
        ~Foo();
        void doTheThings();
};

#endif /* FOO_H */