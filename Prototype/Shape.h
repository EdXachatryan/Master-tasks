#pragma once

#include <iostream>
using posCenter = std::pair<int, int>;


class Shape {

public:
	Shape() = default;
	Shape(posCenter center, int size) : m_center(center), m_size(size) { };
	virtual Shape* clone(posCenter center, int size) = 0;

	posCenter getCenterPoses() const
	{
		return m_center;
	}

	const int getSize() const
	{
		return m_size;
	}

	virtual void print() const = 0; 
private:
	posCenter m_center;
	int m_size;
};