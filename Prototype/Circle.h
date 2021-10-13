#pragma once

#include "Shape.h"

class Circle : public Shape {

public:
    Circle() = default;

    Circle(posCenter cent, int sz) : Shape(cent, sz) { }

    Circle* clone(posCenter cent, int sz) override
    {
        return new Circle(cent,sz);
    }

    void print() const override
    {
        std::cout << "Circle " << getCenterPoses().first << ", " << getCenterPoses().second << ", " << getSize() << std::endl ;
    }
};