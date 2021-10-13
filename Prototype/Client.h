#pragma once
#include "Wave.h"
class Client
{
public:

	Client(Shape* shape) : m_pShape(shape) {}

	Wave* makeWave()
	{
		Wave* result = new Wave();
		result->add(m_pShape->clone({0,0},1)); 
		result->add(m_pShape->clone({0,0},2));
		result->add(m_pShape->clone({0,0},3));
		return result;
	}


private:
	Shape* m_pShape;
};