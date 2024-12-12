#include <queuea/queuea.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include<iostream>
#include<sstream>

TEST_CASE("[QueueA]") {
	CHECK(QueueA().IsEmpty());
	QueueA queue1 = QueueA();

	for (size_t i = 1; i < 1000; i++)
	{
		queue1.Push(i % 256);
		CHECK(queue1.Top() == 1);
	}
	for (size_t i = 1; i < 1000; i++)
	{
		CHECK(queue1.Top() == i % 256);
		queue1.Pop();
	}
	CHECK(queue1.IsEmpty());
	for (size_t i = 1; i < 10; i++)
	{
		queue1.Push(i % 256);
	}
	queue1.Clear();
	CHECK(queue1.IsEmpty());
	for (size_t i = 1; i < 100; i++)
	{
		queue1.Push(i % 256);
	}
	for (size_t i = 100; i < 1000; i++)
	{
		queue1.Push(i % 256);
		CHECK(queue1.Top() == (i - 99)%256);
		queue1.Pop();
	}
	for (size_t i = 1000; i < 2000; i++)
	{
		queue1.Push(i % 256);
	}
	for (size_t i = 2000; i < 3000; i++)
	{
		queue1.Push(i % 256);
		CHECK(queue1.Top() == (i - 1099) % 256);
		queue1.Pop();
	}
	for (size_t i = 1901; i < 3000; i++)
	{
		CHECK(queue1.Top() == i % 256);
		queue1.Pop();
	}
	queue1.Clear();

	for (size_t i = 1; i < 1000; i++)
	{
		queue1.Push(i % 256);
	}
	QueueA queue2 = QueueA(queue1);
	for (size_t i = 1; i < 1000; i++)
	{
		CHECK(queue1.Top() == i % 256);
		queue1.Pop();
		CHECK(queue2.Top() == i % 256);
		queue2.Pop();
	}
	CHECK(queue1.IsEmpty());
	CHECK(queue2.IsEmpty());

	for (size_t i = 1; i < 1000; i++)
	{
		queue1.Push(i % 256);
	}
	queue2 = queue1;
	for (size_t i = 1; i < 1000; i++)
	{
		CHECK(queue1.Top() == i % 256);
		queue1.Pop();
		CHECK(queue2.Top() == i % 256);
		queue2.Pop();
	}
	CHECK(queue1.IsEmpty());
	CHECK(queue2.IsEmpty());

	for (size_t i = 1; i < 1000; i++)
	{
		queue1.Push(i % 256);
	}
	queue2 = QueueA(std::move(queue1));
	for (size_t i = 1; i < 1000; i++)
	{
		CHECK(queue2.Top() == i % 256);
		queue2.Pop();
	}
	CHECK(queue1.IsEmpty());
	CHECK(queue2.IsEmpty());

	for (size_t i = 1; i < 1000; i++)
	{
		queue1.Push(i % 256);
	}
	queue2 = std::move(queue1);
	for (size_t i = 1; i < 1000; i++)
	{
		CHECK(queue2.Top() == i % 256);
		queue2.Pop();
	}
	CHECK(queue1.IsEmpty());
	CHECK(queue2.IsEmpty());
}

TEST_CASE("[QueueA] - excepetions") {
	CHECK_THROWS_WITH(QueueA().Top(), "Can not find a head. Queue is empty");
}