# include <iostream>
#include <string>
#include <vector>
#include <memory>

struct GraphicObject {
    virtual void draw() = 0;
};

/**
 * @brief Scaler object
 * 
 */
struct Circle: GraphicObject {
    void draw() override {
        std::cout << "Circle" << std::endl;
    }
};

/**
 * @brief Group object
 * 
 */
struct Group : GraphicObject {
    std::string _name;
    std::vector<std::unique_ptr<GraphicObject>> objects;
    explicit Group (std::string name): _name(name), GraphicObject() {}
    void draw() override {
        std::cout << "Group " << _name.c_str() << std::endl;
        for(auto && o : objects) {
            o->draw();
        }
    }
};

int main() {
    Group group{"Root"};
    auto subGroup = std::make_unique<Group>(std::string("Flat Drawing"));
    Circle c1, c2;;
    group.objects.push_back(std::move(std::make_unique<Circle>(c1)));
    subGroup->objects.push_back(std::move(std::make_unique<Circle>(c2)));
    group.objects.push_back(std::move(subGroup));

    group.draw();


    return 0;
}