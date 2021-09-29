#ifndef ABSTRACTION_H
#define ABSTRACTION_H


#include "Implementer.h"
template<typename T, class Implementer>
class Absraction
{
	public: 
		virtual bool empty() const = 0;
		virtual T& top() = 0;
		virtual void pop() = 0;
		virtual void push(const T& elem) = 0;
		virtual ~Absraction() {}
	protected:
		Implementer impl;
};

#endif // ABSTRACTION_H