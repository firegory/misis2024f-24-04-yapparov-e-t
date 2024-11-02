#include <complex/complex.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("[complex] - ctor") {
	CHECK(Complex() == Complex(0.0, 0.0));
	CHECK(Complex(1.0) == Complex(1.0, 0.0));
}

TEST_CASE("[complex] - Complex Complex operations") {
	CHECK(Complex(1, 1) + Complex(2, 2) == Complex(3.0, 3.0));
	CHECK(Complex(1, 1) - Complex(2, 2) == Complex(-1.0, -1.0));
	CHECK(Complex(1, 1) * Complex(2, 2) == Complex(0.0, 4.0));
	CHECK(Complex(1, 1) / Complex(2, 2) == Complex(0.5, 0.0));
	CHECK(-Complex(1, 1) == Complex(-1.0, -1.0));
	CHECK(Complex(1.0, 2.0) != Complex(1.0, 1.0));
}

TEST_CASE("[complex] - Complex double operations") {
	CHECK(Complex(1, 1) + 1 == Complex(2.0, 1.0));
	CHECK(Complex(1, 1) - 1 == Complex(0.0, 1.0));
	CHECK(Complex(1, 1) * 2 == Complex(2.0, 2.0));
	CHECK(Complex(1, 1) / 2 == Complex(0.5, 0.5));
	CHECK(Complex(1.0, 0.0) == 1);
	CHECK(Complex(1.0, 1.0) != 1);
}

TEST_CASE("[complex] - double Complex operations") {
	CHECK(1 + Complex(1, 1) == Complex(2.0, 1.0));
	CHECK(1 - Complex(1, 1) == Complex(0.0, -1.0));
	CHECK(2 * Complex(1, 1) == Complex(2.0, 2.0));
	CHECK(2 / Complex(1, 1) == Complex(1.0, -1.0));
	CHECK(1 == Complex(1.0, 0.0));
	CHECK(1 != Complex(1.0, 2.0));
}

TEST_CASE("[complex] - excepetions") {
	CHECK_THROWS_WITH(Complex(1, 1) / Complex(0, 0), "Divide by zero exception");
	CHECK_THROWS_WITH(Complex(1, 1) / 0, "Divide by zero exception");
}