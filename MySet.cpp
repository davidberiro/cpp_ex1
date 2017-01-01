#include <iostream>
#include <string>
#include "MySet.h"

/**
 * Node class used to represent MySet elements
 */
class MySet :: MyNode
{
public:
    double value;
    int weight;
    std::string key;
    MyNode *nextNode = nullptr;
    MyNode(std::string nodeKey, double nodeValue)
    {
        key = nodeKey;
        value = nodeValue;
        weight = myHashFunction(nodeKey);
    }
};
MySet ::MySet() {}

/**
 * destructor method
 */
MySet ::~MySet()
{
    if (headerNode == nullptr)
    {
        return;
    }
    while (headerNode->nextNode != nullptr)
    {
        this->remove(headerNode->nextNode->key);
    }
    delete(headerNode);
}

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
int MySet :: myHashFunction(const std::string &str)
{
    int sum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        sum += int(str[i]);
    }
    return sum;
}

/**
 * compares if two sets weights are equal (according to the totWeight function)
 * @param set - set we're comparing ourselves with
 * @return 1 iff weights are equal, 0 otherwise
 */
bool MySet :: operator == (const MySet &set)
{
    return (this->totWeight() == set.totWeight());
}

/**
 * compares the weights of two sets
 * @param set - set we're comparing ourselves with
 * @return returns 1 iff this weight is less than sets weight
 */
bool MySet :: operator < (const MySet &set)
{
    return (this->totWeight() < set.totWeight());
}

/**
 * compares the weights of two sets
 * @param set - set we're comparing ourselves with
 * @return returns 1 iff this weight is greater than sets weight
 */
bool MySet :: operator > (const MySet &set)
{
    return (this->totWeight() > set.totWeight());
}

MySet MySet::operator = (const MySet &set)
{
    MyNode* currentNode = headerNode;
    if (headerNode != nullptr)
    {
        while (headerNode->nextNode != nullptr)
        {
            this->remove(headerNode->nextNode->key);
        }
        delete(headerNode);
    }

    currentNode = set.headerNode;
    while (currentNode != nullptr)
    {
        this->add(currentNode->key, currentNode->value);
        currentNode = currentNode->nextNode;
    }
    return *this;
}

MySet MySet::operator - (const MySet &set)
{
    MySet result;
    MyNode* currentNode = this->headerNode;
    while(currentNode != nullptr)
    {
        if (!set.isElement(currentNode->key))
        {
            result.add(currentNode->key, currentNode->value);
        }
        currentNode = currentNode->nextNode;
    }
    return result;
}

/**
 * returns the union of two sets, giving priority to the value of our elements
 * @param set - the set we're
 * @return union of two sets
 */
MySet MySet::operator | (const MySet &set)
{
    MySet result = set;
    MyNode* currentNode = this->headerNode;
    while (currentNode != nullptr)
    {
        result.add(currentNode->key, currentNode->value);
        currentNode = currentNode->nextNode;
    }
    return result;
}

/**
 * returns the intersection of two sets
 * @param set
 * @return intersection, priority to RHS
 */
MySet MySet::operator & (const MySet &set)
{
    MySet result;
    MyNode* currentNode = this->headerNode;
    while(currentNode != nullptr)
    {
        if (set.isElement(currentNode->key))
        {
            result.add(currentNode->key, currentNode->value);
        }
        currentNode = currentNode->nextNode;
    }
    return result;
}

/**
 * Remove a string (and it's double) from the MySet.
 * Return the numbr of removed elements (0/1)
 * @param key - key of element to remove
 * @return 1 iff element was removed 0 otherwise
 */
int MySet::remove(std::string key)
{
    MyNode* currentNode = headerNode;
    //if list is empty return 0
    if (headerNode == nullptr)
    {
        return 0;
    }
    //if header node is what to remove, remove and update
    if (headerNode->key == key)
    {
        headerNode = headerNode->nextNode;
        delete currentNode;
        return 1;
    }
    MyNode* next;
    while (currentNode->nextNode != nullptr)
    {
        next = currentNode->nextNode;
        if (next->key == key)
        {
            currentNode->nextNode = next->nextNode;
            delete(next);
            return 1;
        }
        currentNode = currentNode->nextNode;
    }
    return 0;
}

bool MySet::isElement(std::string key) const
{
    MyNode* currentNode = headerNode;
    while (currentNode != nullptr)
    {
        if (currentNode->key == key)
        {
            return true;
        }
        currentNode = currentNode->nextNode;
    }
    return false;
}

/**
     * Return true if the element is in the Set, or false otherwise.
     * If the element exists in the Set, return in 'data' its appropriate data
     * value. Otherwise don't change the value of 'data'.
     * @param key - key of element we're checking
     * @param value - value of element we're checking
     * @return true if element is in the set, false otherwise
     */
bool MySet::isInSet(std::string key, double& value)
{
    MyNode* currentNode = headerNode;
    while (currentNode != nullptr)
    {
        if (currentNode->key == key)
        {
            value = currentNode->value;
            return true;
        }
        currentNode = currentNode->nextNode;
    }
    return false;
}

double MySet::sumSet()
{
    double sum = 0;
    MyNode* currentNode = headerNode;
    while (currentNode != nullptr)
    {
        sum += currentNode->value;
        currentNode = currentNode->nextNode;
    }
    return sum;
}

double MySet::totWeight() const
{
    int sum = 0;
    MyNode* currentNode = headerNode;
    while (currentNode != nullptr)
    {
        sum += currentNode->weight;
        currentNode = currentNode->nextNode;
    }
    return sum;
}

/**
     * Add a string (key) and a double (data) to the MySet.
     * If the element already exists , change its data to the
     * input parameter.
     * @param key - key of new element to add
     * @param value - value of new element to add
     * @return 1 if element was added 0 otherwise
     */
int MySet::add(std::string key, double value)
{
    MyNode* newNode = new MyNode(key, value);

    //setting header node if header node is nullptr
    if (headerNode == nullptr)
    {
        headerNode = newNode;
        return 1;
    }

    //resetting header node if new nodes weight is less
    if (newNode->weight < headerNode->weight)
    {
        newNode->nextNode = headerNode;
        headerNode = newNode;
        return 1;
    }

    //setting current node to iterate through linked list
    MyNode* currentNode = headerNode;
    //while the current node is not a duplicate
    while (currentNode->key != key)
    {
        if (currentNode->nextNode == nullptr)
        {
            currentNode->nextNode = newNode;
            return 1;
        }

        if ((currentNode->weight <= newNode->weight)
             && (newNode->weight < currentNode->nextNode->weight))
        {
            newNode->nextNode = currentNode->nextNode;
            currentNode->nextNode = newNode;
            return 1;
        }
        currentNode = currentNode->nextNode;
        //std::cout << "Next node key:" << currentNode->key << std::endl;
    }
    currentNode->value = newNode->value;
    delete newNode;
    return 0;
}

/**
     * print Set contents.
     */
void MySet :: printSet()
{
    if (headerNode == nullptr)
    {
        std::cout << "EMPTY" << std::endl;
        return;
    }
    MyNode* currentNode = headerNode;
    while (currentNode != nullptr)
    {
        std::cout << '<' << currentNode->key << ',' << currentNode->value << ">" << std::endl;
        currentNode = currentNode->nextNode;
    }
}

int MySet :: size()
{
    int size = 0;
    MyNode* currentNode = headerNode;
    while (currentNode != nullptr)
    {
        size++;
        currentNode = currentNode->nextNode;
    }
    return size;
}
