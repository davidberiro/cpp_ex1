/**
 * MySet.h
 *
 * --------------------------------------------------------------------------------------
 * General: This class represents a Set, a data structure of distinct objects 
 *
 *  Methods: 
 *   MySet() - Constructor
 *  ~MySet()         - Destructor
 *
 *  add                  - Add a string (key) and a double (data) to the MySet. 
 *                         If the element already exists , change its data to the
 *                         input parameter.
 *
 *  remove               - Remove a string (and it's double) from the MySet. 
 *                         Return the numbr of removed elements (0/1)
 *
 *  isInSet            - Return true if the element is in the Set, or false otherwise.
 *                         If the element exists in the Set, return in 'data' its appropriate data
 *                         value. Otherwise don't change the value of 'data'.
 *
 *  size                 - Return number of elements stored in the Set.
 *
 *  sumSet               - Return sum of all data elements stored in the Set.
 *
 *  printSet             - print Set contents.
 *
 *
 *  totWeight            - Return the total myHashFunction weight of all the Set keys
 *
 * --------------------------------------------------------------------------------------
 */
#ifndef MY_SET_H
#define MY_SET_H


/**
 * The definition of the Set
 */
class MySet
{
public:
	/**
	 * The hash function.
	 * Input parameter - any C++ string.
	 * Return value: the hash value - the sum of all the characters of the string
	 *   (according to their ASCII value). The hash value of the
	 *   empty string is 0 (since there are no characters, their sum according to
	 *   the ASCII value is 0).
	 * NOTE: In a better design the function would have belong to the string class
	 *	 (or to a class that is derived from std::string). We implement it as a "stand 
	 *	 alone" function since you didn't learn inheritance yet. Keep the function
	 *	 global (it's important to the automatic tests).
	 */
	static int myHashFunction(const std::string &str);


};

#endif
