#include "darray.hpp"

#include <iostream>
#include<sstream>
#include<string>
#include<initializer_list>


Darray::Darray() {
	len = 0;
	allocatedMemory = 8;
	startAdress = new double[8];
}
Darray::Darray(const int length) {
	if (length <= 0)
	{
		throw std::out_of_range("Can not make an arry with tis length");
	}
	len = length;
	allocatedMemory = length - (length % 8) + 8;
	startAdress = new double[allocatedMemory];
	for (int i = 0; i < len; i++)
	{
		startAdress[i] = 0;
	}
}
Darray::Darray(const std::initializer_list<double> array)
{
	len = array.size();
	allocatedMemory = len - (len % 8) + 8;
	startAdress = new double[allocatedMemory];
	for (int i = 0; i < len; i++)
	{
		startAdress[i] = array.begin()[i];
	}
}
Darray::Darray(const Darray& obj)
{
	*this = Darray(obj.len);
	for (int i = 0; i < len; i++)
	{
		this->startAdress[i] = obj.startAdress[i];
	}
}

void Darray::append(const double value) {
	if (allocatedMemory<=len)
	{
		allocatedMemory += 8;
		double* temp = new double[allocatedMemory];
		for (int i = 0; i < len; i++)
		{
			temp[i] = startAdress[i];
		}
		startAdress = temp;
	}
	startAdress[len] = value;
	len++;
}
int Darray::length() {
	return len;
}
double& Darray::operator[](int ind) {
	if (ind>=len || ind < 0)
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
	*this = Darray(rhs);
	return *this;
}