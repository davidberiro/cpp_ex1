/**
 * Simple test for the MySet implementation
 */
#include <iostream>
#include <string>
#include "MySet.h"

#define NUM_ARRAYS 3

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

    if (!((setsArr[0] & setsArr[1]) == setsArr[0]))
    {
        std::cout << "ERROR: Fail test comparing intersection" << std::endl;
        return 1;
    }

    MySet res1 = setsArr[0] | setsArr[1];


    std::cout << "Passed binary operations test" << std::endl;

}