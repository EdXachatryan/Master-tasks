
#ifndef IMPLEMENTER_H
#define IMPLEMENTER_H


template<typename T>
class Implementer
{
	public:
		virtual bool empty() const = 0;
		virtual T& back() const = 0; //precondition: !empty()
		virtual void pop_back()= 0; //precondition: !empty()
		virtual void push_back(const T& elem) = 0;
		virtual T& front()const = 0; //precondition: !empty()
		virtual void pop_front() = 0; //precondition: !empty()
		virtual void push_front(const T& elem) = 0;
};


#endif