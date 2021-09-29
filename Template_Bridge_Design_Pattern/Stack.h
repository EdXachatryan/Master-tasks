#ifndef STACK_H
#define STACK_H

#include "Abstraction.h"

template<typename T, class Implementer>
class Stack : public Absraction<T, Implementer>
{
	public:
		
		bool empty()const
		{
			return  this->impl.empty();
		}

		T& top()
		{
			if (!this->impl.empty())
				return this->impl.back();
		}

		void pop()
		{
			if (!this->impl.empty())
				this->impl.pop_back();
		}

		void push(const T& elem)
		{
			this->impl.push_back(elem);
		}
};

#endif //