#include <rational/rational.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include<iostream>
#include<sstream>

TEST_CASE("[Rational] - ctor") {
	CHECK(Rational() == Rational(0, 1));
	CHECK(Rational(1) == Rational(1, 1));
	CHECK(Rational(2, 4) == Rational(1, 2));
	CHECK(Rational(0, 4) == Rational(0, 1));
	CHECK(Rational(1, -1) == Rational(-1, 1));
}

TEST_CASE("[Rational] - input output") {
	CHECK(testOutput("11/22"));
	CHECK(testOutput("-11/22"));

	CHECK(!testOutput("11 /22"));
	CHECK(!testOutput("11/ 22"));
	CHECK(!testOutput("11/-22"));
	CHECK(!testOutput("1.1/22"));
	CHECK(!testOutput("- 11/22"));
}

TEST_CASE("[Rational] - Rational Rational operations") {
	CHECK(Rational(1, 2) + Rational(1, 3) == Rational(5, 6));
	CHECK(Rational(1, 2) - Rational(2, 3) == Rational(-1, 6));
	CHECK(Rational(1, 2) * Rational(2, 1) == Rational(1, 1));
	CHECK(Rational(1, 1) / Rational(2, 1) == Rational(1, 2));
	CHECK(-Rational(1, 1) == Rational(-1, 1));
	CHECK(Rational(1, 2) != Rational(1, 1));
	CHECK(Rational(3, 2) > Rational(1, 1));
	CHECK(Rational(3, 2) >= Rational(1, 2));
	CHECK(Rational(3, 2) >= Rational(3, 2));
	CHECK(Rational(1, 2) < Rational(1, 1));
	CHECK(Rational(1, 2) <= Rational(3, 2));
	CHECK(Rational(1, 2) <= Rational(1, 2));
}

TEST_CASE("[Rational] - Rational int operations") {
	CHECK(Rational(1, 2) + 1 == Rational(3, 2));
	CHECK(Rational(1, 2) - 1 == Rational(-1, 2));
	CHECK(Rational(1, 2) * 2 == Rational(1, 1));
	CHECK(Rational(1, 1) / 2 == Rational(1, 2));
	CHECK(Rational(1, 1) == 1);
	CHECK(Rational(1, 2) != 1);
	CHECK(Rational(3, 2) > 1);
	CHECK(Rational(3, 2) >= 1);
	CHECK(Rational(3, 1) >= 3);
	CHECK(Rational(1, 2) < 1);
	CHECK(Rational(1, 2) <= 1);
	CHECK(Rational(2, 1) <= 2);
}

TEST_CASE("[Rational] - int Rational operations") {
	CHECK(1 + Rational(1, 2) == Rational(3, 2));
	CHECK(1 - Rational(3, 2) == Rational(-1, 2));
	CHECK(2 * Rational(1, 6) == Rational(1, 3));
	CHECK(2 / Rational(2, 3) == Rational(3, 1));
	CHECK(1 == Rational(1, 1));
	CHECK(1 != Rational(1, 2));
	CHECK(1 > Rational(1, 2));
	CHECK(2 >= Rational(3, 2));
	CHECK(2 >= Rational(2, 1));
	CHECK(1 < Rational(3, 2));
	CHECK(1 <= Rational(3, 2));
	CHECK(1 <= Rational(1, 1));
}

TEST_CASE("[Rational] - excepetions") {
	CHECK_THROWS_WITH(Rational(1, 1) / Rational(0, 1), "Divide by zero exception");
	CHECK_THROWS_WITH(Rational(1, 1) / 0, "Divide by zero exception");
	CHECK_THROWS_WITH(0 / Rational(0, 1), "Divide by zero exception");
	CHECK_THROWS_WITH(Rational(1, 0), "Divide by zero exception");
}