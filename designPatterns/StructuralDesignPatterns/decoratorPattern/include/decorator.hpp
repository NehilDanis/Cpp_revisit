#include <sstream>
#include <iostream>
#include <string>
#include <concepts>

struct Shape {
    virtual std::string str() const = 0;
};

struct Circle: Shape
{
    float _radius;
    Circle() = default;
    explicit Circle(float radius): _radius(radius) {}

    void resize(float factor) {
        _radius *= factor;
    }
    std::string str() const override {
        std::ostringstream oss;
        oss << "A circle of radius " << _radius ;
        return oss.str();
    }
};

struct Square: Shape
{
    float _side;
    Square() = default;
    explicit Square(float side): _side(side) {}

    void resize(float factor) {
        _side *= factor;
    }
    std::string str() const override {
        std::ostringstream oss;
        oss << "A square with side " << _side ;
        return oss.str();
    }
};

enum class Color { red, green, blue };


namespace dynamicDecorator {


    // if at this point user wants to also be able to specify the color sometimes,
    // it does not make sense to go and chance all the classes because it breaks the 
    // single responsibility principle. The shape class should only handle the details
    // regarding the size of the geometry.
    // One way could be to add a new colored shape class which takes a shape object and 
    // color. This way a shape cane be decorated with color dynamically.


    struct ColoredShape :  Shape {
        Shape & _shape;
        Color _color;

        ColoredShape(Shape & shape, Color color): _shape(shape), _color(color) {
        }

        std::string getColor() const {
            switch(_color)
            {
                case Color::red  : return "Red";
                case Color::green: return "Green";
                case Color::blue : return "Blue";
            }
        }

        std::string str() const override {
            std::ostringstream oss;
            oss << _shape.str() << " has the color " << getColor();
            return oss.str();
        }

    };
} // namespace dynaicDecorator


namespace staticDecorator{

    // we need to make sure that T will only be type of shape.
    // good place to use Cpp20 feature, concepts.
    // This way the user is not allowed to use some other type than Shape
    // while creating 

    template <typename T>
    concept IsAShape = std::is_base_of<Shape, T>::value;

    template <IsAShape T> struct ColoredShape : T {
        Color _color;

        ColoredShape(): _color{Color::red} {};
        template<typename ...Args>
        ColoredShape(const Color &color, Args ...args)    
        : T(std::forward<Args>(args)...), _color{color} {}

        std::string getColor() const {
            switch(_color)
            {
                case Color::red  : return "Red";
                case Color::green: return "Green";
                case Color::blue : return "Blue";
            }
        }

        std::string str() const override {
            std::ostringstream oss;
            oss << T::str() << " has the color " << getColor();
            return oss.str();
        }
    };

    template <IsAShape T> struct TransparentShape : T {
        uint8_t _transparency;

        template<typename ...Args>
        TransparentShape(const uint8_t transparency,  Args ...args)
        : T(std::forward<Args>(args)...), _transparency{transparency} {}


        std::string str() const override {
            std::ostringstream oss;
            oss << T::str() << " has " << static_cast<float>(_transparency) / 255.f * 100.f << "% transparency.";
            return oss.str();
        }
    };

} // staticDecorator