#ifndef LIST_H
#define LIST_H

#include "Implementer.h"
#include <list>

template<typename T>
class List : public Implementer<T>
{
	public:
	
		bool empty()const
		{
			return lst.empty();
		}
		T& back() const
		{
			const T&  cBack = lst.back();
			return const_cast<T&> (cBack);	
		}

		void pop_back()
		{
			if (!lst.empty())
				lst.pop_back();
		}

		void push_back(const T& elem)
		{
			lst.push_back(elem);
		}

		T& front() const
		{
			if (!lst.empty())
			{
				const T&  cFront = lst.front();
				return const_cast<T&> (cFront);	
			}
		}
		void pop_front()
		{
			if (!lst.empty())
				return lst.pop_front();
		}
		void push_front(const T& elem)
		{
			lst.push_front(elem);
		}

	private:
		std::list<T> lst;
};



#endif // 