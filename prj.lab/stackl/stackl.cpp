#include "stackl.hpp"

#include <iostream>
#include<sstream>
#include<string>
#include<initializer_list>


Node::Node(const uint8_t val) :
	value(val)
{}
Node::Node(const uint8_t val, Node* nextElem) :
	value(val),
	next(nextElem)
{}

StackL::StackL(const StackL& obj)
{
	Node* theirCurrentElem = obj.head;
	if (theirCurrentElem != nullptr)
	{
		head = new Node(theirCurrentElem->value);
		Node* ourCurrentElem = head;
		while (theirCurrentElem->next != nullptr)
		{
			ourCurrentElem->next = new Node(theirCurrentElem->next->value);
			ourCurrentElem = ourCurrentElem->next;
			theirCurrentElem = theirCurrentElem->next;
		}
	}
}
StackL::StackL(StackL&& obj) noexcept
{
	std::swap(head, obj.head);
}

StackL& StackL::operator=(const StackL& rhs)
{
	*this = StackL(rhs);
	return *this;
}
StackL& StackL::operator=(StackL&& rhs) noexcept
{
	std::swap(head, rhs.head);
	return *this;
}

void StackL::Push(const uint8_t value)
{
	Node* temp = new Node(value, head);
	head = temp;
}
void StackL::Pop() noexcept
{
	if (head != nullptr)
	{
		Node* temp = head->next;
		delete(head);
		head = temp;
	}
}
bool StackL::IsEmpty() const noexcept
{
	return head == nullptr;
}
void StackL::Clear() noexcept
{
	Node* temp = head;
	while (temp != nullptr)
	{
		temp = head->next;
		delete(head);
		head = temp;
	}
}
uint8_t& StackL::Top()
{
	if (head == nullptr)
	{
		throw std::out_of_range("Can not find a head. Satck is empty");
	}
	return head->value;
}
const uint8_t& StackL::Top() const
{
	if (head == nullptr)
	{
		throw std::out_of_range("Can not find a head. Satck is empty");
	}
	return head->value;
}

StackL::~StackL()
{
	this->Clear();
}