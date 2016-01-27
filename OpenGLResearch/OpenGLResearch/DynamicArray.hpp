

template<class T>
void DynamicArray<T>::Add(T& _newElement)
{
	elements.push_back(_newElement);
}

template<class T>
void DynamicArray<T>::ReserveMemory(unsigned int _nbElements)
{
	elements.push_back(T());
}

template<class T>
T& DynamicArray<T>::GetElement(unsigned int _position)
{
	if (_position >= GetNbElements())
	{
		ReserveMemory(_position - (GetNbElements() - 1));
	}
	return elements.at(_position);
}

template<class T>
T* DynamicArray<T>::GetElements()
{
	T* tabElements = new T[elements.size()];
	for (int i = 0; i < elements.size(); i++)
	{
		tabElements[i] = elements.at(i);
	}
	return tabElements;
}

template<class T>
unsigned int DynamicArray<T>::GetNbElements()
{
	return elements.size();
}