#include "Wave.h"
#include "Shape.h"

void Wave::add(Shape* shape)
{
    shapes.push_back(shape);
}

void Wave::print() const
{
    for (int i = 0; i < shapes.size(); ++i)
    {
        shapes.at(i)->print();
    }
}