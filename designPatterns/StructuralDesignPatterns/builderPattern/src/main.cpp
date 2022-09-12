#include "../include/Person.h"
#include "../include/Foo.h"

#include <iostream>
#include <string>
#include <memory>

// add builder example
// Draw triangle and square
// can Render the shape, vector or raster renderer

struct Renderer
{
  virtual string what_to_render_as() const = 0;
};

struct VectorRenderer : Renderer
{
    string what_to_render_as() const override {
        return " as lines";
    }
};

struct RasterRenderer : Renderer
{
    string what_to_render_as() const override {
        return " as pixels";
    }
};

struct Shape
{ 
    unique_ptr<Renderer> _renderer;
    string name;
    
    virtual string str() const = 0;
};

template<typename T>
struct Triangle : Shape
{
    Triangle() 
    {
        this->_renderer = make_unique<T>();
        this->name = "Triangle";
    }
    
    string str() const override {
         return "Drawing " + this->name + this->_renderer->what_to_render_as();
    }
};


template<typename T>
struct Square : Shape
{
    Square()
    {
        this->_renderer = make_unique<T>();
        this->name = "Square";
    }
    string str() const override {
        return "Drawing " + this->name + this->_renderer->what_to_render_as();
    }
};


int main() {

    // pimpl example
    Person p("Nehil");
    p.greet();

    // shrink-wrapped pimpl example
    Foo f(27);
    f.doTheThings();

    // builder example
    std::cout << Square<RasterRenderer>().str();

    return 0;
}