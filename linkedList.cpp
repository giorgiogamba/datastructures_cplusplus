// Copyright Giorgio Gamba
// Example class for a simple Linked List class implementation

#include <iostream>

/*
Design:
We represent a linked list as a collection of NODE items connected through pointers between them
*/

class Node
{
public:

	Node() : Value(0)
	{};

	Node(const int InValue)
		: Value(InValue)
	{};

	int Value;

	Node* Next;
};


class LinkedList
{

public:

	LinkedList()
	{
		Head = nullptr;
	};

	LinkedList(Node* InHead)
		: Head(InHead)
	{}

	~LinkedList()
	{
		Node* CurrNode = Head;
		while (CurrNode)
		{
			Node* ToDelete = CurrNode;
			CurrNode = CurrNode->Next;

			delete ToDelete;
		}
	}

	// Looks for the list tail and adds the passed element
	void Add(Node* NewNode)
	{
		Node* CurrNode = Head;
		while (CurrNode->Next)
		{
			CurrNode = CurrNode->Next;
		}

		// At this point we should be on the tail of the list. Add new element
		CurrNode->Next = NewNode;
	}

	// Removes all the nodes containing the provided value
	void Remove(const int Value)
	{
		Node* CurrNode = Head;
		Node* Prev = nullptr;
		while (CurrNode)
		{
			if (CurrNode->Value == Value)
			{
				// This is the head
				if (!Prev)
				{
					Node* ToDelete = CurrNode;
					Head = CurrNode->Next;
					delete ToDelete;
					CurrNode = Head;
				}
				else
				{
					Prev->Next = CurrNode->Next;
					Node* ToDelete = CurrNode;
					CurrNode = CurrNode->Next;

					delete ToDelete;		
				}
			}
			else
			{
				Prev = CurrNode;
				CurrNode = CurrNode->Next;
			}
		}
	}

	void Print() const
	{
		Node* CurrNode = Head;
		while (CurrNode)
		{
			std::cout << CurrNode->Value << std::endl;
			CurrNode = CurrNode->Next;
		}
	}

private:

	Node* Head;

};
