// Copyright Giorgio Gamba
// This code is a test implementation for the map datastructure implementation

#include <iostream>

#include "linkedList.cpp"

int main()
{
	std::cout << "Map test" << std::endl;

        LinkedList* List = new LinkedList(new Node(0));

	List->Add(new Node(1));
	List->Add(new Node(2));
	List->Add(new Node(3));

        List->Print();

	List->Remove(3);

	std::cout << "Remove Test" << std::endl;
	List->Print();

	delete List;

        return 0;
}

