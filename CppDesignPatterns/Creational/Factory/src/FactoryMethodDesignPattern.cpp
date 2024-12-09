//Factory Method
//Product               : IShape
//Concrete Product      : Circle, Rectangle
//ConcreteCreaton       : ShapeFactory

#include <iostream>
#include <memory>

class IShape {
public:
    virtual void draw() const = 0;
    virtual ~IShape() = default;
};

class Rectangle : public IShape {
public:
    void draw() const override {
        std::cout << "RECTANGLE draw()\n" << std::endl;
    }
};

class Circle : public IShape {
public:
    void draw() const override {
        std::cout << "CIRCLE draw() \n" << std::endl;
    }
};

class ShapeFactory {
public:
    static std::unique_ptr<IShape> getShape(char shapeType) {
        if (shapeType == 'C' || shapeType == 'c') {
            return std::make_unique<Circle>();
        } else if (shapeType == 'R' || shapeType == 'r') {
            return std::make_unique<Rectangle>();
        }
        return nullptr;
    }
};

int main() {
    char choice;
    while (true) {
        std::cout << "Enter 'C' for Circle, 'R' for Rectangle, or 'Q' to quit:\n>> ";
        std::cin >> choice;

        if (choice == 'Q' || choice == 'q') {
            std::cout << "Exiting program." << std::endl;
            break;
        }

        std::unique_ptr<IShape> shape = ShapeFactory::getShape(choice);
        if (shape) {
            shape->draw();
        } else {
            std::cout << "Invalid shape type entered!\n" << std::endl;
        }
    }
    return 0;
}
