// Giorgio Gamba
// Example class containing an implementation of a hash map

#include "linkedList.cpp"

/*
	#TODO
	1. Create child node structure to contains couples key-value
	2. Create overload function to insert elements in list starting from values
	3. Enable string keys
*/

#define STANDARD_ARRAY_SIZE 10 // arbitrary measure, we should check the hash function probability

/*
Design:

We are gonna implement a map as an array of lists, a very classical way.
This way we are gonna keep the advantages of using an array, which is the constant time access

*/
class map
{

public:

	map()
	{
		CurrMapIndicesSize = STANDARD_ARRAY_SIZE;
	};

	void Add(const int InKey, const int InValue)
	{
		// Based on the key provided, look for which list insert the provided value
		const int ListIndex = Hash(InKey);

		if (ListIndex < CurrMapIndicesSize)
		{
			Lists[ListIndex].Add(InValue);
		}
	}

	int Hash(const int InValue)
	{
		return InValue % CurrMapIndicesSize;
	}

	// Creates a bigger inner array and reallocates all the elements inside the map
	void Rebalance()
	{
		CurrMapIndicesSize *= 2;
	}

private:

	int CurrMapIndicesSize;

	LinkedList Lists[STANDARD_ARRAY_SIZE];

};
