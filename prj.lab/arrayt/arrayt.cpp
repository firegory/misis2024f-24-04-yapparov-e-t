#include "arrayt.hpp"

#include <iostream>
#include<sstream>
#include<string>
#include<initializer_list>

/*template <class T>
ArrayT<T>::ArrayT()
{
	len = 0;
	allocatedMemory = 0;
	startAdress = new T[0];
}
template <class T>
ArrayT<T>::ArrayT(const ptrdiff_t length)
{
	if (length <= 0)
	{
		throw std::out_of_range("Can not make an arry with tis length");
	}
	len = length;
	allocatedMemory = length;
	startAdress = new T[allocatedMemory];
	std::memset(startAdress, 0, sizeof(T) * len);
}
template <class T>
ArrayT<T>::ArrayT(const std::initializer_list<T> array)
{
	len = array.size();
	allocatedMemory = len;
	startAdress = new double[allocatedMemory];
	for (int i = 0; i < len; i++)
	{
		startAdress[i] = array.begin()[i];
	}
}
template <class T>
ArrayT<T>::ArrayT(const ArrayT& obj)
{
	len = obj.len;
	allocatedMemory = obj.allocatedMemory;
	startAdress = new T[allocatedMemory];
	std::copy(obj.startAdress, obj.startAdress + len, startAdress);
}
template <class T>
ArrayT<T>::ArrayT(ArrayT&& obj)
{
	std::swap(len, obj.len);
	std::swap(allocatedMemory, obj.allocatedMemory);
	startAdress = obj.startAdress;
	obj.startAdress = nullptr;
}

template <class T>
void ArrayT<T>::Resize(const ptrdiff_t size) 
{
	if (size < 0)
	{
		throw std::out_of_range("Can not make an arry with tis length");
	}
	if (size == len)
	{
		return;
	}
	if (size < len)
	{
		T* temp = new T[size];
		std::copy(startAdress, startAdress + size, temp);
		startAdress = temp;
		allocatedMemory = size;
		len = size;
	}
	else
	{
		if (allocatedMemory < size)
		{
			if (allocatedMemory*2 < size)
			{
				allocatedMemory = size;
			}
			else
			{
				allocatedMemory *= 2;
			}
			T* temp = new T[allocatedMemory];
			std::copy(startAdress, startAdress + len, temp);
			std::memset(&temp[len], 0, sizeof(T) * (allocatedMemory - len));
			startAdress = temp;
		}
		len = size;
	}
}
template <class T>
void ArrayT<T>::Insert(const ptrdiff_t ind, const T value)
{
	if (ind > len || ind < 0)
	{
		throw std::out_of_range("index out of range");
	}
	this->Resize(len + 1);
	std::copy(&startAdress[ind], startAdress + len, &startAdress[ind + 1]);
	startAdress[ind] = value;

}
template <class T>
void ArrayT<T>::Remove(const ptrdiff_t ind)
{
	if (ind >= len || ind < 0)
	{
		throw std::out_of_range("index out of range");
	}
	std::copy(&startAdress[ind + 1], startAdress + len, &startAdress[ind]);
	this->Resize(len - 1);
}
template <class T>
ptrdiff_t ArrayT<T>::Size() const noexcept {
	return len;
}
template <class T>
T& ArrayT<T>::operator[](const ptrdiff_t ind) {
	if (ind>=len || ind < 0)
	{
		throw std::out_of_range("index out of range");
	}
	return startAdress[ind];
}
template <class T>
const T& ArrayT<T>::operator[](const ptrdiff_t ind) const {
	if (ind >= len || ind < 0)
	{
		throw std::out_of_range("index out of range");
	}
	return startAdress[ind];
}

template <class T>
ArrayT<T>::~ArrayT()
{
	delete(startAdress);
}

template <class T>
ArrayT<T>& ArrayT<T>::operator=(const ArrayT& rhs)
{
	if (this != &rhs)
	{
		len = rhs.len;
		allocatedMemory = len;
		startAdress = new T[allocatedMemory];
		std::copy(rhs.startAdress, rhs.startAdress + len, startAdress);
	}
	return *this;
}
template <class T>
ArrayT<T>& ArrayT<T>::operator=(ArrayT&& rhs) noexcept
{
	if (this != &rhs)
	{
		std::swap(len, rhs.len);
		std::swap(allocatedMemory, rhs.allocatedMemory);
		startAdress = rhs.startAdress;
		rhs.startAdress = nullptr;
	}
	return *this;
}*/