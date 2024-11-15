#include "darray.hpp"

#include <iostream>
#include<sstream>
#include<string>


Darray::Darray() {
	len = 0;
	allocatedMemory = 8;
	startAdress = new double[8];
}
Darray::Darray(const int length) {
	len = length;
	allocatedMemory = length - (length % 8) + 8;
	startAdress = new double[allocatedMemory];
	for (int i = 0; i < len; i++)
	{
		startAdress[i] = 0;
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
	if (ind>=len)
	{
		std::out_of_range("index out of range");
	}
	return startAdress[ind];
}