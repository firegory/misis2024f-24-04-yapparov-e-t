#include <chocker/chocker.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include<iostream>
#include<sstream>

TEST_CASE("[Chocker] - ctor") {
	Chocker ch1 = Chocker(100, 100);
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			CHECK(ch1.At(i, j) == 0);
		}
	}
	CHECK_THROWS_WITH(ch1.At(99, 100), "Index out of range");
	CHECK_THROWS_WITH(ch1.At(100, 99), "Index out of range");

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			ch1.At(i, j) = i + j / 128;
		}
	}
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			CHECK(ch1.At(i, j) == i + j / 128);
		}
	}




	Chocker ch2(std::move(ch1));
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			CHECK(ch2.At(i, j) == i + j / 128);
		}
	}
	CHECK_THROWS_WITH(ch2.At(99, 100), "Index out of range");
	CHECK_THROWS_WITH(ch2.At(100, 99), "Index out of range");
	CHECK_THROWS_WITH(ch1.At(0, 0), "Index out of range");

	ch1 = std::move(ch2);
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			CHECK(ch1.At(i, j) == i + j / 128);
		}
	}
	CHECK_THROWS_WITH(ch1.At(99, 100), "Index out of range");
	CHECK_THROWS_WITH(ch1.At(100, 99), "Index out of range");
	CHECK_THROWS_WITH(ch2.At(0, 0), "Index out of range");
	
	ch2 = ch1;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			CHECK(ch1.At(i, j) == i + j / 128);
		}
	}
	CHECK_THROWS_WITH(ch1.At(99, 100), "Index out of range");
	CHECK_THROWS_WITH(ch1.At(100, 99), "Index out of range");
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			CHECK(ch2.At(i, j) == i + j / 128);
		}
	}
	CHECK_THROWS_WITH(ch2.At(99, 100), "Index out of range");
	CHECK_THROWS_WITH(ch2.At(100, 99), "Index out of range");

	Chocker ch3(ch1);
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			CHECK(ch1.At(i, j) == i + j / 128);
		}
	}
	CHECK_THROWS_WITH(ch1.At(99, 100), "Index out of range");
	CHECK_THROWS_WITH(ch1.At(100, 99), "Index out of range");
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			CHECK(ch3.At(i, j) == i + j / 128);
		}
	}
	CHECK_THROWS_WITH(ch3.At(99, 100), "Index out of range");
	CHECK_THROWS_WITH(ch3.At(100, 99), "Index out of range");



	ch1.Resize(10);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			CHECK(ch1.At(i, j) == i + j / 128);
		}
	}
	CHECK_THROWS_WITH(ch1.At(9, 100), "Index out of range");
	CHECK_THROWS_WITH(ch1.At(10, 99), "Index out of range");

	ch1.Resize(100);
	for (int i = 10; i < 100; i++)
	{
		ch1.Resize(100, i);
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			CHECK(ch1.At(i, j) == i + j / 128);
		}
	}
	for (int i = 10; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			CHECK(ch1.At(i, j) == 0);
		}
	}
	CHECK_THROWS_WITH(ch1.At(99, 100), "Index out of range");
	CHECK_THROWS_WITH(ch1.At(100, 99), "Index out of range");

	for (int i = 0; i < 10; i++)
	{
		ch1.Resize(10, i);
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			CHECK(ch1.At(i, j) == i + j / 128);
		}
		CHECK_THROWS_WITH(ch1.At(i, 10), "Index out of range");
	}
	for (int i = 10; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			CHECK(ch1.At(i, j) == 0);
		}
	}
	CHECK_THROWS_WITH(ch1.At(99, 100), "Index out of range");
	CHECK_THROWS_WITH(ch1.At(100, 99), "Index out of range");

}

TEST_CASE("[ArrayD] - excepetions") {
	CHECK_THROWS_WITH(Chocker().At(0,0), "Index out of range");
	CHECK_THROWS_WITH(Chocker().Resize(-1), "Can not resize to negative length");
	CHECK_THROWS_WITH(Chocker().Resize(-1, 1), "Can not resize this row. Index out of range");
	CHECK_THROWS_WITH(Chocker().Resize(1, -1), "Can not resize this row. Index out of range");
}