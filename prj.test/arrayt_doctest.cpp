#include <arrayt/arrayt.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include<iostream>
#include<sstream>

template <class T>
T getType(int n);

template <class T>
bool isEqual(T n, T n1);

template <>
int getType(int n)
{
	return n;
}
template <>
float getType(int n)
{
	return n;
}
template <>
std::string getType(int n)
{
	return std::string(n, n+48);
}

template <>
bool isEqual(int n, int n1)
{
	return n == n1;
}
template <>
bool isEqual(float n, float n1)
{
	return n == n1;
}
template <>
bool isEqual(std::string n, std::string n1)
{
	return n == n1;
}


template <class T>
void checkType(T variable)
{
	ArrayT<T> arr = ArrayT<T>();
	CHECK(arr.Size() == 0);
	CHECK_THROWS_WITH(arr[0], "index out of range");

	ArrayT<T> arr1(1000);
	CHECK(arr1.Size() == 1000);
	for (int i = 0; i < 1000; i++)
	{
		CHECK(isEqual<T>(arr1[i], getType<T>(0)));
	}
	CHECK_THROWS_WITH(arr[1000], "index out of range");

	ArrayT<T> arr2(3);
	arr2[0] = getType<T>(1);
	arr2[1] = getType<T>(2);
	arr2[2] = getType<T>(3);
	CHECK(isEqual<T>(arr2[0], getType<T>(1)));
	CHECK(isEqual<T>(arr2[1], getType<T>(2)));
	CHECK(isEqual<T>(arr2[2], getType<T>(3)));
	std::cout << "!!!\n\n" << sizeof(arr2[0]) << "!  !" << sizeof(arr2[3]) << "\n\n!!!";
	arr2.Insert(0, getType<T>(10));
	CHECK(isEqual<T>(arr2[0], getType<T>(10)));
	CHECK(isEqual<T>(arr2[1], getType<T>(1)));
	std::cout << "!!!\n\n" << arr2[3] << "!  !" << getType<T>(2) << "\n\n!!!";
	CHECK(isEqual<T>(arr2[2], getType<T>(2)));
	CHECK(isEqual<T>(arr2[3], getType<T>(3)));
	arr2.Insert(2, getType<T>(11));
	CHECK(isEqual<T>(arr2[0], getType<T>(10)));
	CHECK(isEqual<T>(arr2[1], getType<T>(1)));
	CHECK(isEqual<T>(arr2[2], getType<T>(11)));
	CHECK(isEqual<T>(arr2[3], getType<T>(2)));
	CHECK(isEqual<T>(arr2[4], getType<T>(3)));
	arr2.Insert(5, getType<T>(12));
	CHECK(arr2[0] == getType<T>(10));
	CHECK(arr2[1] == getType<T>(1));
	CHECK(arr2[2] == getType<T>(11));
	CHECK(arr2[3] == getType<T>(2));
	CHECK(arr2[4] == getType<T>(3));
	CHECK(arr2[5] == getType<T>(12));

	arr2.Remove(5);
	CHECK(arr2[0] == getType<T>(10));
	CHECK(arr2[1] == getType<T>(1));
	CHECK(arr2[2] == getType<T>(11));
	CHECK(arr2[3] == getType<T>(2));
	CHECK(arr2[4] == getType<T>(3));
	CHECK_THROWS_WITH(arr2[5], "index out of range");
	arr2.Remove(2);
	CHECK(arr2[0] == getType<T>(10));
	CHECK(arr2[1] == getType<T>(1));
	CHECK(arr2[2] == getType<T>(2));
	CHECK(arr2[3] == getType<T>(3));
	CHECK_THROWS_WITH(arr2[4], "index out of range");
	arr2.Remove(0);
	CHECK(arr2[0] == getType<T>(1));
	CHECK(arr2[1] == getType<T>(2));
	CHECK(arr2[2] == getType<T>(3));
	CHECK_THROWS_WITH(arr2[3], "index out of range");

	ArrayT<T> arr3 = arr2;
	CHECK(arr3[0] == getType<T>(1));
	CHECK(arr3[1] == getType<T>(2));
	CHECK(arr3[2] == getType<T>(3));
	CHECK_THROWS_WITH(arr3[3], "index out of range");

	ArrayT<T> arr4(arr2);
	CHECK(arr4[0] == getType<T>(1));
	CHECK(arr4[1] == getType<T>(2));
	CHECK(arr4[2] == getType<T>(3));
	CHECK_THROWS_WITH(arr4[3], "index out of range");

	ArrayT<T> arr5(std::move(arr2));
	CHECK(arr5[0] == getType<T>(1));
	CHECK(arr5[1] == getType<T>(2));
	CHECK(arr5[2] == getType<T>(3));
	CHECK_THROWS_WITH(arr5[3], "index out of range");
	CHECK(arr2.Size() == 0);

	arr2 = std::move(arr5);
	CHECK(arr2[0] == getType<T>(1));
	CHECK(arr2[1] == getType<T>(2));
	CHECK(arr2[2] == getType<T>(3));
	CHECK_THROWS_WITH(arr2[3], "index out of range");
	CHECK(arr5.Size() == 0);

	for (int i = 0; i < 100; i++)
	{
		arr5.Insert(i, getType<T>(i + 1));
		for (int j = 0; j <= i; j++)
		{
			CHECK(arr5[j] == getType<T>(j + 1));
		}
		CHECK_THROWS_WITH(arr5[i+1], "index out of range");
	}

	for (int i = 99; i >= 0; i--)
	{
		arr5.Remove(i);
		for (int j = 0; j < i; j++)
		{
			CHECK(arr5[j] == getType<T>(j + 1));
		}
		CHECK_THROWS_WITH(arr5[i], "index out of range");
	}

	CHECK_THROWS_WITH(ArrayT<T>(1)[-1], "index out of range");
	CHECK_THROWS_WITH(ArrayT<T>(0), "Can not make an arry with tis length");
	CHECK_THROWS_WITH(ArrayT<T>(-1), "Can not make an arry with tis length");
	CHECK_THROWS_WITH(ArrayT<T>().Resize(-1), "Can not make an arry with tis length");
}


TEST_CASE("[ArrayD] - ctor") {
	int temp = 1;
	float temp2 = 1;
	std::string temp3 = "1";
	//checkType(temp);
	//checkType(temp2);
	checkType(temp3);
}

