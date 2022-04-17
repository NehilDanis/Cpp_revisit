#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <ostream>

namespace testtemplate {

    template<class T>
    class TemplateTest
    {
    private:
        T obj_;
    public:
        TemplateTest(T obj) { obj_ = std::move(obj); }
        ~TemplateTest() {/**/}
        T getObj() const { return obj_; }  
    };

    template <class T>
    std::ostream & operator<<(std::ostream& out, const TemplateTest<T> &test) {
        out << test.getObj();
        return out;
    } 
} /* namespace testtemplate */


#endif /* TEMPLATE_HPP */