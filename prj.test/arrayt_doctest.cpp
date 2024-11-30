#include <arrayt/arrayt.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include<iostream>
#include<sstream>


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
		CHECK(arr1[i] == 0);
	}
	CHECK_THROWS_WITH(arr[1000], "index out of range");

	ArrayT<T> arr2(3);
	arr2[0] = 1;
	arr2[1] = 2;
	arr2[2] = 3;


	arr2.Insert(0, 10);
	CHECK(arr2[0] == 10);
	CHECK(arr2[1] == 1);
	CHECK(arr2[2] == 2);
	CHECK(arr2[3] == 3);
	arr2.Insert(2, 11);
	CHECK(arr2[0] == 10);
	CHECK(arr2[1] == 1);
	CHECK(arr2[2] == 11);
	CHECK(arr2[3] == 2);
	CHECK(arr2[4] == 3);
	arr2.Insert(5, 12);
	CHECK(arr2[0] == 10);
	CHECK(arr2[1] == 1);
	CHECK(arr2[2] == 11);
	CHECK(arr2[3] == 2);
	CHECK(arr2[4] == 3);
	CHECK(arr2[5] == 12);

	arr2.Remove(5);
	CHECK(arr2[0] == 10);
	CHECK(arr2[1] == 1);
	CHECK(arr2[2] == 11);
	CHECK(arr2[3] == 2);
	CHECK(arr2[4] == 3);
	CHECK_THROWS_WITH(arr2[5], "index out of range");
	arr2.Remove(2);
	CHECK(arr2[0] == 10);
	CHECK(arr2[1] == 1);
	CHECK(arr2[2] == 2);
	CHECK(arr2[3] == 3);
	CHECK_THROWS_WITH(arr2[4], "index out of range");
	arr2.Remove(0);
	CHECK(arr2[0] == 1);
	CHECK(arr2[1] == 2);
	CHECK(arr2[2] == 3);
	CHECK_THROWS_WITH(arr2[3], "index out of range");

	ArrayT<T> arr3 = arr2;
	CHECK(arr3[0] == 1);
	CHECK(arr3[1] == 2);
	CHECK(arr3[2] == 3);
	CHECK_THROWS_WITH(arr3[3], "index out of range");

	ArrayT<T> arr4(arr2);
	CHECK(arr4[0] == 1);
	CHECK(arr4[1] == 2);
	CHECK(arr4[2] == 3);
	CHECK_THROWS_WITH(arr4[3], "index out of range");

	ArrayT<T> arr5(std::move(arr2));
	CHECK(arr5[0] == 1);
	CHECK(arr5[1] == 2);
	CHECK(arr5[2] == 3);
	CHECK_THROWS_WITH(arr5[3], "index out of range");
	CHECK(arr2.Size() == 0);

	arr2 = std::move(arr5);
	CHECK(arr2[0] == 1);
	CHECK(arr2[1] == 2);
	CHECK(arr2[2] == 3);
	CHECK_THROWS_WITH(arr2[3], "index out of range");
	CHECK(arr5.Size() == 0);

	for (int i = 0; i < 100; i++)
	{
		arr5.Insert(i, i + 1);
		for (int j = 0; j <= i; j++)
		{
			CHECK(arr5[j] == j + 1);
		}
		CHECK_THROWS_WITH(arr5[i+1], "index out of range");
	}

	for (int i = 99; i >= 0; i--)
	{
		arr5.Remove(i);
		for (int j = 0; j < i; j++)
		{
			CHECK(arr5[j] == j + 1);
		}
		CHECK_THROWS_WITH(arr5[i + 1], "index out of range");
	}

	CHECK_THROWS_WITH(ArrayT<T>(1)[-1], "index out of range");
	CHECK_THROWS_WITH(ArrayT<T>(0), "Can not make an arry with tis length");
	CHECK_THROWS_WITH(ArrayT<T>(-1), "Can not make an arry with tis length");
	CHECK_THROWS_WITH(ArrayT<T>().Resize(-1), "Can not make an arry with tis length");
}


TEST_CASE("[ArrayD] - ctor") {
	int temp = 1;
	double temp1 = 1;
	float temp2 = 1;
	checkType(temp);
	checkType(temp1);
	checkType(temp2);
}

