// Copyright 2025 Giorgio Gamba. All rights reserved.
// This code wants to define how a smart pointer should be implemented from scratch

#include <iostream>

template<typename T>
struct MySmartPtr
{
	// We remove the default constructor in order to always provide correct initialization
	MySmartPtr() = delete;

	// This should be the only constructor used
	MySmartPtr(T* InObj)
	{
		std::cout << "Smart pointer construction\n";

		Ptr = InObj;
		this->ReferenceCounting++;
	}

	// The destructor is responsible of deleting all the references
	~MySmartPtr()
	{
		std::cout << "Smart pointer destruction\n";
		this->ReferenceCounting--;
	}

	MySmartPtr(MySmartPtr<T>&& Other)
	{
		std::cout << "Copy constructor\n";

		Ptr = Other.Ptr;
		ReferenceCounting = Other.ReferenceCounting;
	}

private:

	T* Ptr;

	int* ReferenceCounting;

};

int main()
{
	std::cout << "My smart pointer implementation\n";

	MySmartPtr<int> Test(new int[3]);

	MySmartPtr<int> CopyTest(std::move(Test));	

	return 0;
}


