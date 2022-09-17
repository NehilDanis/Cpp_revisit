# include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

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

/**
 * In case a class has many differend fields, it s good to use coposite pattern.
 * Because if a new field needs to be added the other funtions do not need to be changed.
 * For example, if there are functions which return sum or the average of all the fields, 
 * these functions need to be updated when a new field is added.
 */

class Creature {
    enum Abilities {strength, agility, intelligence, count};
    std::array<int, count> abilities;

    public:
        int get_strength() const { return abilities[strength]; }
        void set_strength(int value) { abilities[strength] = value; }

        int get_agility() const { return abilities[agility]; }
        void set_agility(int value) { abilities[agility] = value; }

        int get_intelligence() const { return abilities[intelligence]; }
        void set_intelligence(int value) { abilities[intelligence] = value; }

        int sum() const { 
            size_t sum = 0;
            for(auto const &ability: this->abilities) {
                sum += ability;
            }
            return sum;
        }
        double avg() const {
            return sum() / count;
        }

        int max() const {
            return std::max(std::max(abilities[strength], abilities[agility]), abilities[intelligence]);
        }

        friend std::ostream & operator<<(std::ostream &os, const Creature & c) {
            os << "Sum: " << c.sum() << " Average: " << c.avg() << " Max: " << c.max() << std::endl;
            return os;
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

    /* New Example */

    Creature orc;
    orc.set_strength(10);
    orc.set_agility(7);
    orc.set_intelligence(3);
    std::cout << orc;

    return 0;
}