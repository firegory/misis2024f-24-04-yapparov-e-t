#include <complex/complex.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("[complex] - ctor") {
	CHECK(Complex() == Complex(0.0, 0.0));
	CHECK(Complex(1.0) == Complex(1.0, 0.0));
	CHECK(Complex(1,1) + Complex(2,2) == Complex(3.0, 3.0));
	CHECK(Complex(1, 1) - Complex(2, 2) == Complex(-1.0, -1.0));
	CHECK(Complex(1, 1) * Complex(2, 2) == Complex(3.0, 3.0));
}