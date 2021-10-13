#include "Wave.h"
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"
#include <memory>
#include "Client.h"


template<typename t>
void safeDeleter(t* ptr)
{
    if (ptr != nullptr)
        delete ptr;

    ptr = nullptr;
}


int main()
{

    Circle oCirle;
    Client clientCircle(&oCirle); 
    Wave* circleWave = clientCircle.makeWave();
    circleWave->print();

  
    Triangle oTriangle;
    Client clientTriangle(&oTriangle); 
    Wave* triangleWave = clientTriangle.makeWave();
    triangleWave->print();

    Square oSquare;
    Client clientSquare(&oSquare); 
    Wave* squareWave = clientSquare.makeWave();
    squareWave->print();

    safeDeleter<Wave>(circleWave);
    safeDeleter(triangleWave);
    safeDeleter(squareWave);

    return 0;
};