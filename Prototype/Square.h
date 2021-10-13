#pragma once

#include "Shape.h"

class Square : public Shape {

public:
    
    Square() =default;
    Square(posCenter center, int sz) : Shape(center, sz) { }

    Square* clone(posCenter cent, int sz) override
    {
        return new Square(cent, sz);
    }

    void print() const override
        {
        std::cout << "Square " << getCenterPoses().first << ", " << getCenterPoses().second << ", " << getSize() << std::endl ;
    }
};