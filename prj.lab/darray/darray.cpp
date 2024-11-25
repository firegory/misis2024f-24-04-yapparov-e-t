#include "darray.hpp"

#include <iostream>
#include<sstream>
#include<string>
#include<initializer_list>


Darray::Darray() {
	len = 0;
	allocatedMemory = 0;
	startAdress = new double[0];
}
Darray::Darray(const ptrdiff_t length) {
	if (length <= 0)
	{
		throw std::out_of_range("Can not make an arry with tis length");
	}
	len = length;
	allocatedMemory = length;
	startAdress = new double[allocatedMemory];
	std::memset(startAdress, 0.0, 8*len);
}
Darray::Darray(const std::initializer_list<double> array)
{
	len = array.size();
	allocatedMemory = len;
	startAdress = new double[allocatedMemory];
	for (int i = 0; i < len; i++)
	{
		startAdress[i] = array.begin()[i];
	}
}
Darray::Darray(const Darray& obj)
{
	len = obj.len;
	allocatedMemory = len;
	startAdress = new double[allocatedMemory];
	std::copy(obj.startAdress, &obj.startAdress[len], startAdress);
}


void Darray::Resize(const ptrdiff_t size) 
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
		double* temp = new double[size];
		std::copy(startAdress, &startAdress[size], temp);
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
			double* temp = new double[allocatedMemory];
			std::copy(startAdress, &startAdress[len], temp);
			std::memset(&temp[len], 0.0, 8 * (allocatedMemory - len));
			startAdress = temp;
		}
		len = size;
	}
}
void Darray::Insert(const ptrdiff_t ind, const double value)
{
	if (ind > len || ind < 0)
	{
		throw std::out_of_range("index out of range");
	}
	this->Resize(len + 1);
	std::copy(&startAdress[ind], &startAdress[len], &startAdress[ind+1]);
	startAdress[ind] = value;

}
void Darray::Remove(const ptrdiff_t ind)
{
	if (ind >= len || ind < 0)
	{
		throw std::out_of_range("index out of range");
	}
	std::copy(&startAdress[ind+1], &startAdress[len], &startAdress[ind]);
	this->Resize(len - 1);
}

ptrdiff_t Darray::Size() const{
	return len;
}
double& Darray::operator[](const ptrdiff_t ind) {
	if (ind>=len || ind < 0)
	{
		throw std::out_of_range("index out of range");
	}
	return startAdress[ind];
}
const double& Darray::operator[](const ptrdiff_t ind) const {
	if (ind >= len || ind < 0)
	{
		throw std::out_of_range("index out of range");
	}
	return startAdress[ind];
}

Darray::~Darray()
{
	delete(startAdress);
}
Darray& Darray::operator=(const Darray& rhs)
{
	len = rhs.len;
	allocatedMemory = len;
	startAdress = new double[allocatedMemory];
	std::copy(rhs.startAdress, &rhs.startAdress[len], startAdress);
	return *this;
}