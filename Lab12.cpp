#include <iostream>
#include <cmath>

class GraphicObject {
protected:
    std::string color;

public:
    GraphicObject(const std::string& c = "undefined") : color(c) {}

    virtual void draw() const {
        std::cout << "Drawing a graphic object of color: " << color << std::endl;
    }

    virtual ~GraphicObject() = default;
};

class Circle : public GraphicObject {
private:
    double radius;

public:
    Circle(const std::string& c, double r) : GraphicObject(c), radius(r) {}

    void draw() const override {
        std::cout << "Drawing a circle of color: " << color 
                  << " with radius: " << radius << std::endl;
    }

    double calculateArea() const {
        return M_PI * radius * radius;
    }
};

int main() {
    GraphicObject obj("red");
    obj.draw();

    Circle circle("blue", 5.0);
    circle.draw();
    std::cout << "Area of the circle: " << circle.calculateArea() << std::endl;

    return 0;
}
