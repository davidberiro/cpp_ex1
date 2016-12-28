#include <iostream>
#include <string>



class MySet
{
public:
	MyNode* headerNode = nullptr;
	
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
	static int myHashFunction(const std::string &str)
	{
		int sum = 0;
		for (int i = 0; i < str.length(); i++)
		{
			sum += int(str[i]);
		}
		return sum;
	}

	bool operator == (const MySet &set)
	{
		return (this.totWeight() == set.totWeight());
	}

	bool operator < (const MySet &set) const
	{
		return (this.totWeight() < set.totWeight());
	}

	bool operator > (const MySet &set) const
	{
		return (this.totWeight() > set.totWeight());
	}

	MySet operator = (const MySet &set)
	{
		MySet result;
		MyNode* currentNode = headerNode;
		if (headerNode != nullptr)
		{
			while (headerNode->nextNode != nullptr)
			{
				this.remove(headerNode->nextNode->key);
			}
			this.remove(headerNode->key);
		}
		MyNode* currentNode = set.headerNode;
		while (currentNode != nullptr)
		{
			this.add(currentNode);
			currentNode = currentNode->nextNode;
		}
	}

	MySet operator | (const MySet &set)
	{
		MySet result = set;
		MyNode* currentNode = this.headerNode;
		while (currentNode != nullptr)
		{
			result.add(currentNode->key, currentNode->value);
			currentNode = currentNode->nextNode;
		}
		return result;
	}

	MySet operator & (const MySet &set)
	{
		MySet result;
		MyNode* currentNode = this.headerNode;
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

	int remove(std::string key)
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
			return 1;
		}
		while (currentNode->nextNode != nullptr)
		{
			if (currentNode->nextNode->key == key)
			{
				currentNode->nextNode = currentNode->nextNode->nextNode;
				return 1;
			}
			currentNode = currentNode->nextNode;
		}
		return 0;
	}

	bool isElement(std::string key)
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

	bool isInSet(std::string key, double& value)
	{
		MyNode* currentNode = headerNode;
		while (currentNode != nullptr)
		{
			if (currentNode->key == key)
			{
				currentNode->value = value;
				return true;
			}
			currentNode = currentNode->nextNode;
		}
		return false;
	}

	double sumSet()
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

	double totWeight()
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

	int add(std::string key, double value)
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
				currentNode->nextNode = currentNode;
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
		}
		return 0;
	}

private:
	class MyNode
	{
	public:
		double value;
		int weight;
		std::string key;
		MyNode* nextNode = nullptr;
		MyNode(std::string nodeKey, double nodeValue)
		{
			key = nodeKey;
			value = nodeValue;
			weight = myHashFunction(nodeKey);
		}
	}
};