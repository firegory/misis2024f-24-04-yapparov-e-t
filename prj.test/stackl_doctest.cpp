#include <stackl/stackl.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include<iostream>
#include<sstream>

TEST_CASE("[StackL]") {
	CHECK(StackL().IsEmpty());
	StackL stack1 = StackL();

	for (size_t i = 0; i < 1000; i++)
	{
		stack1.Push(i % 256);
		CHECK(stack1.Top() == i%256);
	}
	for (size_t i = 999; i > 0; i--)
	{
		stack1.Pop();
		CHECK(stack1.Top() == (i-1)%256);
	}
	stack1.Pop();
	CHECK(stack1.IsEmpty());

	for (size_t i = 0; i < 10; i++)
	{
		stack1.Push(i % 256);
	}
	stack1.Clear();
	CHECK(stack1.IsEmpty());

	for (size_t i = 0; i < 1000; i++)
	{
		stack1.Push(i % 256);
	}
	StackL stack2 = StackL(stack1);
	for (size_t i = 999; i > 0; i--)
	{
		stack1.Pop();
		CHECK(stack1.Top() == (i - 1) % 256);
		stack2.Pop();
		CHECK(stack2.Top() == (i - 1) % 256);
	}
	stack1.Pop();
	CHECK(stack1.IsEmpty());
	stack2.Pop();
	CHECK(stack2.IsEmpty());

	for (size_t i = 0; i < 1000; i++)
	{
		stack1.Push(i % 256);
	}
	stack2 = stack1;
	for (size_t i = 999; i > 0; i--)
	{
		stack1.Pop();
		CHECK(stack1.Top() == (i - 1) % 256);
		stack2.Pop();
		CHECK(stack2.Top() == (i - 1) % 256);
	}
	stack1.Pop();
	CHECK(stack1.IsEmpty());
	stack2.Pop();
	CHECK(stack2.IsEmpty());

	for (size_t i = 0; i < 1000; i++)
	{
		stack1.Push(i % 256);
	}
	stack2 = StackL(std::move(stack1));
	for (size_t i = 999; i > 0; i--)
	{
		stack2.Pop();
		CHECK(stack2.Top() == (i - 1) % 256);
	}
	CHECK(stack1.IsEmpty());
	stack2.Pop();
	CHECK(stack2.IsEmpty());

	for (size_t i = 0; i < 1000; i++)
	{
		stack1.Push(i % 256);
	}
	stack2 = std::move(stack1);
	for (size_t i = 999; i > 0; i--)
	{
		stack2.Pop();
		CHECK(stack2.Top() == (i - 1) % 256);
	}
	CHECK(stack1.IsEmpty());
	stack2.Pop();
	CHECK(stack2.IsEmpty());
}

TEST_CASE("[StackL] - excepetions") {
	CHECK_THROWS_WITH(StackL().Top(), "Can not find a head. Satck is empty");
}