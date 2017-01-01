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

    class MyNode;
    MyNode *headerNode = nullptr;
    MySet();
    ~MySet();

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

    /**
     * print Set contents.
     */
    void printSet();

    /**
     * Add a string (key) and a double (data) to the MySet.
     * If the element already exists , change its data to the
     * input parameter.
     * @param key - key of new element to add
     * @param value - value of new element to add
     * @return 1 if element was added 0 otherwise
     */
    int add(std::string key, double value);

    /**
     * Return true if the element is in the Set, or false otherwise.
     * If the element exists in the Set, return in 'data' its appropriate data
     * value. Otherwise don't change the value of 'data'.
     * @param key - key of element we're checking
     * @param value - value of element we're checking
     * @return true if element is in the set, false otherwise
     */
    bool isInSet(std::string key, double& value);

    /**
     * Remove a string (and it's double) from the MySet.
     * Return the numbr of removed elements (0/1)
     * @param key - key of element to remove
     * @return 1 iff element was removed 0 otherwise
     */
    int remove(std::string key);

    /**
     * compares if two sets weights are equal (according to the totWeight function)
     * @param set - set we're comparing ourselves with
     * @return 1 iff weights are equal, 0 otherwise
     */
    bool operator == (const MySet &set);

    /**
     * compares the weights of two sets
     * @param set - set we're comparing ourselves with
     * @return returns 1 iff this weight is less than sets weight
     */
    bool operator < (const MySet &set);

    /**
     * compares the weights of two sets
     * @param set - set we're comparing ourselves with
     * @return returns 1 iff this weight is greater than sets weight
     */
    bool operator > (const MySet &set);

    /**
     * returns the union of two sets, giving priority to the value of our elements
     * @param set - the set we're
     * @return union of two sets
     */
	MySet operator | (const MySet &set);

    /**
     * returns the intersection of two sets
     * @param set
     * @return intersection, priority to RHS
     */
	MySet operator & (const MySet &set);

    /**
     * assignment operator
     * @param set our assigment
     * @return
     */
    MySet operator = (const MySet &set);

    /**
     *
     * @param set
     * @return
     */
	MySet operator - (const MySet &set);

    /**
     *
     * @param key
     * @return
     */
    bool isElement(std::string key) const;

    /**
     *
     * @return
     */
    double totWeight() const;

    /**
     *
     * @return
     */
    double sumSet();

    /**
     *
     * @return
     */
	int size();

private:

};

#endif
