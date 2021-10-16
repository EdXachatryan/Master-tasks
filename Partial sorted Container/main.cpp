#include <iostream>
#include "SortedContainer.h"
#include <assert.h>


void prtintContainter(SortedContainter<int>& sortedContainter)
{
	SortedContainter<int>::iterator itBeg = sortedContainter.begin();
	SortedContainter<int>::iterator itEnd = sortedContainter.end();

	for (; itBeg != itEnd; ++itBeg)
	{
		std::cout << (*itBeg).data << " " ;
	}
	std::cout << std::endl;
}

void print(std::string msg)
{
	std::cout << msg << std::endl ;
}

int main()
{
	SortedContainter<int> sortedContainter;

	assert(!sortedContainter.size());		
	print("Insert -2 , 0");
	sortedContainter.insert(-2);
	sortedContainter.insert(0);
	prtintContainter(sortedContainter);
	print("Insert 7, 9, 0, -3");
	sortedContainter.insert(7);
	sortedContainter.insert(9);
	sortedContainter.insert(0);
	sortedContainter.insert(-3);
	assert(sortedContainter.size() == 6);
	prtintContainter(sortedContainter);
	assert(sortedContainter.find(0) == 2);
	print("erase item from position 0, 3, 5");
	sortedContainter.erase(0);
	sortedContainter.erase(3);
	sortedContainter.erase(5);
	prtintContainter(sortedContainter);

	SortedContainter<int> sortedContainter2;
	print("Insert to second container -9 , 100");
	sortedContainter2.insert(-9);
	sortedContainter2.insert(100);
	prtintContainter(sortedContainter2);
	print("merge two containers");
	SortedContainter<int> merged = merge(sortedContainter, sortedContainter2);
	prtintContainter(merged);
}

