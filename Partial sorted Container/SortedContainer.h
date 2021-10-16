#ifndef SORTEDCONT_H
#define SORTEDCONT_H

/*
	Container have unique elements order,  at first there holds negative numbers, then zero afther zoro values hold positive numbers
	Merge two container same idea
*/

template<typename T>
class SortedContainter
{
		struct node;
	public:

		class Iterator;	
		using value_type = T;
		using nodePtr = node*;
		using reference = node&;
		using pointer = nodePtr;
		using iterator = Iterator; 

	public:
		SortedContainter();
		~SortedContainter();
		
		size_t find(value_type k);
		void insert(value_type k);
		bool erase(int p); // --
		size_t size() 					{ return m_size; }

		bool empty();

		void swap(int pos); // --

		iterator begin();
		iterator end();
		
	private:
		int m_size;
		int m_maxSize;	
		pointer	m_base;
		pointer m_firstZero;
		pointer m_firstPositive;
		pointer m_last;

		struct node
		{
			node(value_type val, nodePtr next = nullptr, nodePtr prev = nullptr) :
				data(val), ptrNext(next), ptrPrev(prev) { }

			value_type data;
			nodePtr ptrNext;
			nodePtr ptrPrev;	
		};


};

// =====================================================================================
// nested class Iterator from SortedContainter class implementation
//

template<typename T>
class SortedContainter<T>::Iterator
{
	public:
		explicit Iterator(nodePtr pt) : ptr (pt) {}
		
		reference operator*()
		{
			return *ptr;
		}

		iterator operator=(const reference elem)
		{
			ptr->data = elem;
			return *this;
		}

		iterator operator++()
		{
			ptr = ptr->ptrNext;
			return *this;
		}

		iterator operator++(int)
		{
			iterator temp = *this;
			ptr = ptr->ptrNext;
			return temp;
		}
		bool operator==(const iterator& other)
		{
			return ptr == other.ptr;
		}
		bool operator!=(const iterator& other)
		{
			return ptr != other.ptr;
		}

	private:
		nodePtr ptr;
};

// =====================================================================================
// SortedContainter class implementation
//

template<typename T>
SortedContainter<T>::SortedContainter()
	: m_size(0), m_maxSize(0)
{
	m_base = nullptr;
	m_firstPositive = nullptr;
	m_firstZero = nullptr;
	m_last = nullptr;
}

template<typename T>
SortedContainter<T>::~SortedContainter()
{
	auto it = begin();

	for (; it != end(); )
	{
		nodePtr temp = &(*it);
		++it;
		delete temp;
	}
}
	
template<typename T>
bool SortedContainter<T>::empty()
{
	if (m_base || m_firstPositive || m_firstZero)
		return true;
	else 
		return false;	
}

template<typename T>
typename SortedContainter<T>::iterator SortedContainter<T>::begin()
{
	pointer temp;
	if (m_base) temp = m_base;
	else if (m_firstZero) temp = m_firstZero;
	else if (m_firstPositive) temp = m_firstPositive;
	
	return iterator(temp);
}

template<typename T>
typename SortedContainter<T>::iterator SortedContainter<T>::end()
{
	return iterator(m_last);
}


template<typename T>
void SortedContainter<T>::insert(value_type elem)
{
	if (elem < 0)
	{

		nodePtr nextAvalable = (m_firstZero) ? m_firstZero : (m_firstPositive) ? m_firstPositive : m_last;
		if (m_base == nullptr)
		{
			m_base = new node(elem, nextAvalable, nullptr);
		}
		else
		{
			nodePtr temp = m_base;
			m_base = new node(elem, temp, temp->ptrPrev);
			temp->ptrPrev = m_base;	
		}

		if (m_firstZero != nullptr)
		  m_firstZero->ptrPrev = m_base;
	}
	else if (elem == 0)
	{

		nodePtr tempNegative = m_base;
		if (tempNegative !=nullptr)
		{
			while (true)
			{
				if (tempNegative->ptrNext == nullptr)
					break;
				else if (tempNegative->ptrNext == m_firstZero)
					break;

				tempNegative = tempNegative->ptrNext;
			}
		}
		

		if (m_firstZero == nullptr)
		{
			nodePtr nextAvalable =  (m_firstPositive) ? m_firstPositive : m_last;
			m_firstZero = new node(elem, nextAvalable, tempNegative);	
			if (m_firstPositive != nullptr)
				m_firstPositive->ptrPrev = m_firstZero;
			else if (nextAvalable != nullptr)
				nextAvalable->ptrPrev = m_firstZero;
		
		}
		else
		{
			nodePtr tempZerro = m_firstZero;
			m_firstZero = new node(elem,tempZerro, tempZerro->ptrPrev);
			tempZerro->ptrPrev = m_firstZero;	
		}

		if (tempNegative!=nullptr)
			tempNegative->ptrNext = m_firstZero;
	}
	else
	{
		nodePtr firstAvalable =  (m_firstZero) ? m_firstZero : (m_base) ? m_base : m_last;
		nodePtr tempZerro = m_firstZero;
		if (firstAvalable != nullptr)
		{
			while (true)
			{
				if (firstAvalable->ptrNext == nullptr)
					break;
				else if (firstAvalable->ptrNext == m_firstPositive)
					break;

				firstAvalable = firstAvalable->ptrNext;
			}
		}

		if (m_firstPositive == nullptr)
		{
			m_firstPositive = new node(elem, m_last, firstAvalable);
		}
		else
		{
			nodePtr tempPos = m_firstPositive;
			m_firstPositive = new node(elem, tempPos, tempPos->ptrPrev);
			tempPos->ptrPrev = m_firstPositive;
		}
		if (firstAvalable != nullptr)
			firstAvalable->ptrNext = m_firstPositive;
	}
	++m_size; 
}

template<typename T>
size_t SortedContainter<T>::find(value_type elem)
{
	Iterator itBegin = begin();
	Iterator itEnd = end();
	int pos = 0;

	for (; itBegin != itEnd; ++itBegin, ++pos)
	{
		if ((*itBegin).data == elem)
			break;
	}
	return pos;
}
template<typename T>
bool SortedContainter<T>::erase(int delPos)
{

	auto updateKeyPointer = [&]( nodePtr curr) {

		if (curr == this->m_base)
		{
			this->m_base = curr->ptrNext;
		}
		else if (curr == this->m_firstZero)
		{
			this->m_firstZero = curr->ptrNext;
		}
		else if (curr == this->m_firstPositive)
		{
			this->m_firstPositive = curr->ptrNext;
		}

	};

	if (delPos >= size())
		return false;
	auto it = begin();
	if (delPos == 0)
	{
		nodePtr temp = (*it).ptrNext;
		nodePtr current = &(*it);
		updateKeyPointer(current);
		delete current;
		temp->ptrPrev = nullptr;
	}
	else
	{
		while (--delPos)
		{
			it++;
		}
		
		nodePtr tempPrev = (*it).ptrPrev;
		nodePtr tempNext = (*it).ptrNext;
		nodePtr current = &(*it);
		updateKeyPointer(current);
		delete current;
		tempPrev->ptrNext = tempNext;
		tempNext->ptrPrev = tempPrev;
	}	
	--m_size;
	return true;
}

template<typename T>
SortedContainter<T> merge(SortedContainter<T>& cont1,  SortedContainter<T>& cont2) // ---------
{

	SortedContainter<T> newCont;
	
	SortedContainter<int>::iterator itCont1Begin = cont1.begin();
	SortedContainter<int>::iterator itCont1End = cont1.end();
	
	SortedContainter<int>::iterator itCont2Begin = cont2.begin();
	SortedContainter<int>::iterator itCont2End = cont2.end();

	for ( ; itCont1Begin != itCont1End && itCont2Begin != itCont2End;)
	{
		if ((*itCont1Begin).data < (*itCont2Begin).data)
		{
			newCont.insert((*itCont1Begin).data);
			++itCont1Begin;
		}
		else
		{
			newCont.insert((*itCont2Begin).data);
			++itCont2Begin;
		}
	}

	for (;itCont1Begin != itCont1End; ++itCont1Begin)
	{
		newCont.insert((*itCont1Begin).data);
	}
	
	for (;itCont2Begin != itCont2End; ++itCont2Begin)
	{
		newCont.insert((*itCont2Begin).data);
	}
	return newCont;
}

#endif