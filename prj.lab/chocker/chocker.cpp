#include <iostream>
#include<sstream>
#include <stdarg.h>
#include "chocker.hpp"


Node::Node(const ptrdiff_t length)
{
	size = length;
	allocatedMemory = length;
	startAdress = new float[allocatedMemory];
	std::memset(startAdress, 0.0f, sizeof(float) * allocatedMemory);
}
Node::Node(const Node& obj)
{
	size = obj.size;
	allocatedMemory = obj.allocatedMemory;
	startAdress = new float[allocatedMemory];
	std::copy(obj.startAdress, obj.startAdress + allocatedMemory, startAdress);
}
Node::Node(Node&& obj) noexcept
{
	std::swap(size, obj.size);
	std::swap(allocatedMemory, obj.allocatedMemory);
	std::swap(startAdress, obj.startAdress);
}

Node::~Node()
{
	delete(startAdress);
}

Node& Node::operator=(const Node& obj)
{		
	size = obj.size;
	allocatedMemory = obj.allocatedMemory; 
	if (startAdress != nullptr)
	{
		delete(startAdress);
	}
	startAdress = new float[allocatedMemory];
	std::copy(obj.startAdress, obj.startAdress + allocatedMemory, startAdress);
	return *this;
}
Node& Node::operator=(Node&& obj) noexcept
{
	std::swap(size, obj.size);
	std::swap(allocatedMemory, obj.allocatedMemory);
	std::swap(startAdress, obj.startAdress);
	return *this;

}
float& Node::operator[](const ptrdiff_t ind)
{
	if (ind >= size || ind < 0)
	{
		throw std::out_of_range("Index out of range");
	}
	return startAdress[ind];
}
const float& Node::operator[](const ptrdiff_t ind) const
{
	if (ind >= size || ind < 0)
	{
		throw std::out_of_range("Index out of range");
	}
	return startAdress[ind];
}

void Node::Resize(const int newSize)
{
	if (size < 0)
	{
		throw std::out_of_range("Can not resize to negative length");
	}
	if (size != newSize)
	{
		if (newSize <= allocatedMemory && newSize > size)
		{
			size = newSize;
			return;
		}
		else if (newSize < size || newSize > allocatedMemory * 2)
		{
			allocatedMemory = newSize;
		}
		else
		{
			allocatedMemory *= 2;
		}
		float* newStartAdress = new float[allocatedMemory];
		std::copy(startAdress, std::min(startAdress + size, startAdress + newSize), newStartAdress);
		if (newSize > size)
		{
			std::memset(newStartAdress + size, 0.0f, 4 * (allocatedMemory - size));
		}
		size = newSize;
		if (startAdress != nullptr)
		{
			delete(startAdress);
		}
		startAdress = newStartAdress;
	}
}




Chocker::Chocker(const ptrdiff_t ncol, const ptrdiff_t nrow)
{
	size = nrow;
	startAdress = new Node[size];
	for (int i = 0; i < size; i++)
	{
		startAdress[i] = std::move(Node(ncol));
	}
}

Chocker::Chocker(const Chocker& obj)
{
	size = obj.size;
	startAdress = new Node[size];
	for (int i = 0; i < size; i++)
	{
		startAdress[i] = obj.startAdress[i];
	}
}
Chocker::Chocker(Chocker&& obj) noexcept
{
	std::swap(size, obj.size);
	std::swap(startAdress, obj.startAdress);
}

Chocker::~Chocker()
{
	delete(startAdress);
}

Chocker& Chocker::operator=(const Chocker& obj)
{
	if (startAdress != nullptr)
	{
		delete(startAdress);
	}
	size = obj.size;
	startAdress = new Node[size];
	for (int i = 0; i < size; i++)
	{
		startAdress[i] = obj.startAdress[i];
	}
	return *this;
}
Chocker& Chocker::operator=(Chocker&& obj) noexcept
{
	std::swap(size, obj.size);
	std::swap(startAdress, obj.startAdress);
	return *this;
}

float& Chocker::At(const ptrdiff_t  row, const ptrdiff_t  col)
{
	if (row >= size || row < 0)
	{
		throw std::out_of_range("Index out of range");
	}
	return startAdress[row][col];
}
const float& Chocker::At(const ptrdiff_t  row, const ptrdiff_t  col) const
{
	if (row >= size || row < 0)
	{
		throw std::out_of_range("Index out of range");
	}
	return startAdress[row][col];
}

void Chocker::Resize(const ptrdiff_t ncol, const ptrdiff_t nrow)
{
	if (nrow < 0 || nrow >= size)
	{
		throw std::out_of_range("Can not resize this row. Index out of range");
	}
	startAdress[nrow].Resize(ncol);
}
void Chocker::Resize(const ptrdiff_t nrow)
{
	if (nrow < 0)
	{
		throw std::out_of_range("Can not resize to negative length");
	}
	if (size != nrow)
	{
		Node* newStartAdress = new Node[nrow];
		std::copy(startAdress, std::min(startAdress + size, startAdress + nrow), newStartAdress);
		
		size = nrow;
		if (startAdress != nullptr)
		{
			delete(startAdress);
		}
		startAdress = newStartAdress;
	}
	
}

	