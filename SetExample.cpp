/**
 * Simple checks for the MySet implementation
 */
#include <iostream>
#include <string>
#include "MySet.h"
#define EPSILON 0.0001

static double myAbs(double d)
{
	if (d < 0)
	{
		return -d;
	}
	return d;
}

// Input: two doubles.
// Output: true if the two doubles are equal (different smaller than EPSILON), false otherwise.
static bool isDoublesEq(double d1, double d2)
{

	if (myAbs(d1-d2) <= EPSILON)
	{
		return true;
	}
	return false;

}

int main()
{

	MySet mylist;
	std::string firstWord = "aa";
	double firstVal = 1.5;
	std::string secondWord = "bc";
	double secVal = 15.0;
	std::string thirdWord = "bb";
	double thirdVal = 2.2;
	std::string forthWord = "ab";
	double forthVal = 1.0;


	mylist.printSet();
	std::cout << "Done print list" << std::endl << std::endl;

	mylist.add(firstWord, firstVal);
	std::cout << "Hello" << std::endl;
	mylist.add(secondWord, secVal);
	std::cout << "Hello1" << std::endl;
	mylist.add(firstWord, thirdVal);
	std::cout << "Hello2" << std::endl;
	mylist.add(thirdWord, firstVal);
	std::cout << "Hello3" << std::endl;
	mylist.add(forthWord, firstVal);
	std::cout << "Hello4" << std::endl;
	mylist.add(forthWord, forthVal);


	mylist.printSet();
	std::cout << "Done print list" << std::endl << std::endl;

	double d;
	if (!mylist.isInSet(thirdWord, d))
	{
		// isInSet - check if thirdWord exists at least once in the list.
		// If it does - change 'd' so it will contain the data value of
		// one of thirdWord appearances and return 'true'. Otherwise
		// return 'false' and don't change the value of 'd'.
		std::cerr << "Error: Word " << thirdWord << " should exists in list." << std::endl;
		return 1;
	}
	else
	{
		if (!isDoublesEq(d, firstVal))
		{
			std::cerr << "Error: the appropriate value for the word " << thirdWord << " is " <<
						 firstVal << " while isInSet returned " << d << std::endl;
			return 1;
		}
	}

	if (!mylist.remove(thirdWord))
	{
		// remove *all* appearances of thirdWord in the list (in our case one appearance)
		std::cerr << "Error: Removing " << thirdWord << " should have succeeded." << std::endl;
		return 1;
	}

	if (mylist.isInSet(thirdWord, d))
	{
		std::cerr << "Error: Word " << thirdWord << " should not exists in list." << std::endl;
		return 1;
	}
	else
	{
		if (!isDoublesEq(d, firstVal))
		{
			std::cerr << "Error: value of 'd' shouldn't be changed by isInSet for" << std::endl <<
						 "	   a word that doesn't exists in the list. " << std::endl;
			return 1;
		}
	}

	mylist.printSet();
	std::cout << "Done print list" << std::endl << std::endl;

	std::cout << "Done test." << std::endl;
	return 0;
}

