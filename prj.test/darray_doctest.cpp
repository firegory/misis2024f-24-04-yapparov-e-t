#include <darray/darray.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include<iostream>
#include<sstream>

TEST_CASE("[Darray] - ctor") {
	CHECK(Darray().Size() == 0);
	CHECK(Darray(1).Size() == 1);
	CHECK(Darray(1000).Size() == 1000);

	CHECK(Darray(1)[0] == 0);
	CHECK(Darray(1000)[800] == 0);


	Darray arr = Darray({ 1,2,3 });
	CHECK(arr[2] == 3);
	Darray arr1(arr);
	CHECK(arr1[2] == 3);

	arr.Resize(4);
	CHECK(arr[2] == 3);
	CHECK(arr[3] == 0);

	arr.Resize(2);
	CHECK(arr[0] == 1);
	CHECK(arr[1] == 2);

	arr = Darray({ 1,2,3, 4, 5});
	arr.Insert(2, 6);
	CHECK(arr[0] == 1);
	CHECK(arr[2] == 6);
	CHECK(arr[5] == 5);

	arr = Darray({ 1,2,3, 4, 5});
	arr.Insert(5, 6);
	CHECK(arr[0] == 1);
	CHECK(arr[4] == 5);
	CHECK(arr[5] == 6);

	arr = Darray({ 1,2,3, 4, 5 });
	arr.Remove(2);
	CHECK(arr[0] == 1);
	CHECK(arr[2] == 4);
	CHECK(arr[3] == 5);
	CHECK_THROWS_WITH(arr[4], "index out of range");

	arr = Darray({ 1,2,3, 4, 5 });
	arr.Remove(4);
	CHECK(arr[0] == 1);
	CHECK(arr[2] == 3);
	CHECK(arr[3] == 4);
	CHECK_THROWS_WITH(arr[4], "index out of range");


	CHECK(Darray({ 1,2,3 })[0] == 1);
	CHECK(Darray({ 1,2,3 })[1] == 2);
	CHECK(Darray({ 1,2,3 })[2] == 3);
}

TEST_CASE("[Darray] - input output") {
	
}

TEST_CASE("[Darray] - excepetions") {
	CHECK_THROWS_WITH(Darray(1)[1], "index out of range");
	CHECK_THROWS_WITH(Darray(1)[-1], "index out of range");
	CHECK_THROWS_WITH(Darray(1)[1], "index out of range");
	CHECK_THROWS_WITH(Darray(0), "Can not make an arry with tis length");
	CHECK_THROWS_WITH(Darray(-1), "Can not make an arry with tis length");
	CHECK_THROWS_WITH(Darray().Resize(-1), "Can not make an arry with tis length");
}