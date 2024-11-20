#include <darray/darray.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include<iostream>
#include<sstream>

TEST_CASE("[Darray] - ctor") {
	CHECK(Darray().length() == 0);
	CHECK(Darray(1).length() == 1);
	CHECK(Darray(1)[0] == 0);
	CHECK(Darray(1000).length() == 1000);
	CHECK(Darray(1000)[800] == 0);
	CHECK(Darray({ 1,2,3 })[0] == 1);
	CHECK(Darray({ 1,2,3 })[1] == 2);
	CHECK(Darray({ 1,2,3 })[2] == 3);
}

TEST_CASE("[Darray] - input output") {
	
}

TEST_CASE("[Darray] - excepetions") {
	CHECK_THROWS_WITH(Darray(1)[1], "index out of range");
	CHECK_THROWS_WITH(Darray(1)[-1], "index out of range");
}