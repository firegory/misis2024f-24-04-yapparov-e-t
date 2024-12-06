#include "queuea.hpp"

#include <iostream>
#include<sstream>
#include<string>
#include<initializer_list>


QueueA::QueueA(const QueueA& obj)
{
	if (!obj.empty)
	{
		allocatedMemory = obj.allocatedMemory;
		head = obj.head;
		tail = obj.tail;
		if (startAdress != nullptr)
		{
			delete(startAdress);
		}
		startAdress = new uint8_t[allocatedMemory];
		std::copy(obj.startAdress, obj.startAdress + allocatedMemory, startAdress);
		empty = false;
	}
}
QueueA::QueueA(QueueA&& obj) noexcept
{
	if (!obj.empty)
	{
		std::swap(allocatedMemory, obj.allocatedMemory);
		std::swap(head, obj.head);
		std::swap(tail, obj.tail);
		std::swap(startAdress, obj.startAdress);
		std::swap(empty, obj.empty);
	}
}
QueueA& QueueA::operator=(const QueueA& rhs)
{
	if (!rhs.empty)
	{
		allocatedMemory = rhs.allocatedMemory;
		head = rhs.head;
		tail = rhs.tail;
		if (startAdress != nullptr)
		{
			delete(startAdress);
		}
		startAdress = new uint8_t[allocatedMemory];
		std::copy(rhs.startAdress, rhs.startAdress + allocatedMemory, startAdress);
		empty = false;
	}
	return *this;
}
QueueA& QueueA::operator=(QueueA&& rhs) noexcept
{
	if (!rhs.empty)
	{
		std::swap(allocatedMemory, rhs.allocatedMemory);
		std::swap(head, rhs.head);
		std::swap(tail, rhs.tail);
		std::swap(startAdress, rhs.startAdress);
		std::swap(empty, rhs.empty);
	}
	return *this;
}

void QueueA::Push(const uint8_t value)
{
	if (allocatedMemory == 0)
	{
		if (startAdress != nullptr)
		{
			delete(startAdress);
			startAdress = nullptr;
		}
		startAdress = new uint8_t[8];
		startAdress[0] = value;
		tail = 0;
		head = 0;
		allocatedMemory = 8;
	}
	else if (tail + 1 == head)
	{
		uint8_t* temp = new uint8_t[allocatedMemory*2];
		std::copy(startAdress, &startAdress[tail + 1], &temp[allocatedMemory - head]);
		std::copy(&startAdress[head], startAdress + allocatedMemory, temp);
		std::memset(&temp[allocatedMemory + 1], 0.0, (allocatedMemory));
		head = 0;
		tail = allocatedMemory;
		temp[tail] = value;
		startAdress = temp;
		allocatedMemory *= 2;
	}
	else if (tail == allocatedMemory - 1 && head == 0)
	{
		uint8_t* temp = new uint8_t[allocatedMemory * 2];
		std::copy(startAdress, startAdress + allocatedMemory, temp);
		std::memset(&temp[allocatedMemory], 0, allocatedMemory);
		head = 0;
		tail = allocatedMemory;
		temp[tail] = value;
		startAdress = temp;
		allocatedMemory *= 2;
	}
	else
	{
		tail++;
		tail = tail % allocatedMemory;
		startAdress[tail] = value;
	}
	empty = false;
}
void QueueA::Pop() noexcept
{
	if (!empty)
	{
		startAdress[head] = 0;
		head++;
		head = head % allocatedMemory;
		if (head - 1 == tail)
		{
			Clear();
		}
	}
}
bool QueueA::IsEmpty() const noexcept
{
	return empty;
}
void QueueA::Clear() noexcept
{
	if (startAdress != nullptr)
	{
		delete(startAdress);
		startAdress = nullptr;
	}
	allocatedMemory = 0;
	head = 0;
	tail = 0;
	empty = true;
}
uint8_t& QueueA::Top()
{
	if (empty)
	{
		throw std::out_of_range("Can not find a head. Queue is empty");
	}
	return startAdress[head];
}

QueueA::~QueueA()
{

}

void QueueA::print()
{
	for (int i = 0; i < allocatedMemory; i++)
	{
		std::cout << std::to_string(startAdress[i]) << "\n";
	}
}