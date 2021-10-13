#pragma once

#include "Shape.h"

class Triangle : public Shape {

public:
    Triangle() = default;
    Triangle(posCenter cent, int sz) : Shape(cent, sz) { }

    Triangle* clone(posCenter cent, int sz) override
    {
        return new Triangle(cent,sz);
    }

    void print() const override
    {
        std::cout << "Triangle " << getCenterPoses().first << ", " << getCenterPoses().second << ", " << getSize() << std::endl ;
    }
};