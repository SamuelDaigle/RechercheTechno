#pragma once

using namespace std;

template<class T>
class DynamicArray
{
public:
	void Add(T& _newElement);
	void ReserveMemory(unsigned int _nbElements);
	T& GetElement(unsigned int _position);
	T* GetElements();
	unsigned int GetNbElements();

private:
	vector<T> elements;
};

#include "DynamicArray.hpp"