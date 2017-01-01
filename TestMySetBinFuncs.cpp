/**
 * Simple test for the MySet implementation
 */
#include <iostream>
#include <string>
#include "MySet.h"

#define NUM_ARRAYS 3
#define EQ_RETURN_VAL 0

int main()
{
	MySet setsArr[NUM_ARRAYS];
	setsArr[0].add("a", 5.);
	setsArr[0].add("b", 0.6);
	setsArr[1].add("a", 2.);
	setsArr[1].add("b", 2.);
	setsArr[1].add("c", 2.);
	setsArr[2].add("d", -2.);
	setsArr[2].add("e", -2.);
	if (setsArr[0] > setsArr[1])
	{
		std::cout << "ERROR: Fail test comparing weight gt" << std::endl;
		return 1;
	}
	if (setsArr[1] < setsArr[0])
	{
		std::cout << "ERROR: Fail test comparing weight lt" << std::endl;
		return 1;
	}
	if (setsArr[0] == setsArr[1])
	{
		std::cout << "ERROR: Fail test comparing weight eq" << std::endl;
		return 1;
	}
	MySet min = setsArr[0] - setsArr[1];
	if (min.size() != 0)
	{
		std::cout << "ERROR: Fail test Minus1" << std::endl;
		return 1;
	}
	 min = setsArr[0] - setsArr[0];
	if (min.size() != 0 )
	{
		setsArr[0].printSet();
		std::cout << "ERROR: Fail test Minus2" << std::endl;
		min.printSet();
		
		return 1;
	}
	MySet uni = setsArr[0] | setsArr[1];
	if (uni.totWeight() < 7.5)
	{
		std::cout << "ERROR: Fail test Union" << std::endl;
		return 1;
	}
	MySet intersect = setsArr[0] & setsArr[2];
	if (intersect.size() != 0)
	{
		std::cout << "ERROR: Fail test Intersection" << std::endl;
		return 1;
	}

	std::cout << "Pass basic binary MySet tests." << std::endl;
	return 0;
}
