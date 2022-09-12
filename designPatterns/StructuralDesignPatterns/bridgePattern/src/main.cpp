#include "../include/Person.h"
#include "../include/Foo.h"

#include <iostream>
#include <string>
#include <memory>

// add bridge example
// Draw triangle and square
// can Render the shape, vector or raster renderer

struct Renderer
{
  virtual std::string what_to_render_as() const = 0;
};

struct VectorRenderer : Renderer
{
    std::string what_to_render_as() const override {
        return " as lines";
    }
};

struct RasterRenderer : Renderer
{
    std::string what_to_render_as() const override {
        return " as pixels";
    }
};

struct Shape
{ 
    std::unique_ptr<Renderer> _renderer;
    std::string name;
    
    virtual std::string str() const = 0;
};

template<typename T>
struct Triangle : Shape
{
    Triangle() 
    {
        this->_renderer = std::make_unique<T>();
        this->name = "Triangle";
    }
    
    std::string str() const override {
         return "Drawing " + this->name + this->_renderer->what_to_render_as();
    }
};


template<typename T>
struct Square : Shape
{
    Square()
    {
        this->_renderer = std::make_unique<T>();
        this->name = "Square";
    }
    std::string str() const override {
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

    // bridge example
    std::cout << Square<RasterRenderer>().str();

    return 0;
}