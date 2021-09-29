#ifndef QUEUE_H
#define QUEUE_H

#include "Abstraction.h"

template<typename T, class Implementer>
class Queue : public Absraction<T, Implementer>
{
	public:
		
		bool empty()const
		{
			return this->impl.empty();
		}

		T& top()
		{
			if (!this->impl.empty())
				return this->impl.front();
		}

		void pop()
		{
			if (!this->impl.empty())
				this->impl.pop_front();
		}

		void push(const T& elem)
		{
			this->impl.push_back(elem);
		}
};

#endif //QUEUE_H