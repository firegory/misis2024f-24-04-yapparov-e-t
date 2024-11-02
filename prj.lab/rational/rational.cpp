#include <iostream>
#include<sstream>
#include "rational.hpp"


int greatestCommonDivisor(int a, int b) {
    if (a < b) {
        std::swap(a, b);
    }

    while (b) {
        a %= b;
        std::swap(a, b);
    }

    return a;
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept
{
    return rhs.writeTo(ostrm);
}
std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept
{
    return rhs.readFrom(istrm);
}
std::ostream& Rational::writeTo(std::ostream& ostrm) const noexcept
{
    ostrm << start << numerator << sep << denominator << end;
    return ostrm;
}
std::istream& Rational::readFrom(std::istream& istrm) noexcept
{
    char start = ' ';
    char sep = ' ';
    char end = ' ';
    int num = 0;
    int den = 0;
    istrm >> start >> num >> sep >> den >> end;
    if (istrm.good())
    {
        if (Rational::start == start && Rational::sep == sep && Rational::end == end)
        {
            numerator = num;
            denominator = den;
        }
        else
        {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}


Rational::Rational(const int numerator) :
    Rational(numerator, 1)
{}
Rational::Rational(const int num, const int den)
{
    int gcd = greatestCommonDivisor(abs(num), abs(den));
    if (den < 0)
    {
        numerator = num / gcd * -1;
        denominator = den / gcd * -1;
    }
    else
    {
        numerator = num / gcd;
        denominator = den / gcd;
    }
}

Rational Rational::operator-() const noexcept
{
    return Rational(-1* numerator, denominator);
}

Rational& Rational::operator+=(const Rational& rhs) noexcept
{
    int gcd = greatestCommonDivisor(denominator, rhs.denominator);
    numerator *= rhs.denominator / gcd;
    numerator += rhs.numerator * denominator / gcd;
    denominator *= rhs.denominator / gcd;
    return *this;
}
Rational& Rational::operator+=(const int rhs)  noexcept
{
    *this += Rational(rhs);
    return *this;
}
Rational operator+(const Rational& lhs, const Rational& rhs) noexcept
{
    Rational t(lhs);
    t += rhs;
    return t;
}
Rational operator+(const Rational& lhs, const int& rhs) noexcept
{
    Rational t(lhs);
    t += rhs;
    return t;
}
Rational operator+(const int& lhs, const Rational& rhs) noexcept
{
    Rational t(lhs);
    t += rhs;
    return t;
}

Rational& Rational::operator-=(const Rational& rhs) noexcept
{
    *this += -rhs;
    return *this;
}
Rational& Rational::operator-=(const int rhs) noexcept
{
    *this -= Rational(rhs);
    return *this;
}
Rational operator-(const Rational& lhs, const Rational& rhs) noexcept
{
    Rational t(lhs);
    t -= rhs;
    return t;
}
Rational operator-(const Rational& lhs, const int& rhs) noexcept
{
    Rational t(lhs);
    t -= rhs;
    return t;
}
Rational operator-(const int& lhs, const Rational& rhs) noexcept
{
    Rational t(lhs);
    t -= rhs;
    return t;
}

Rational& Rational::operator*=(const Rational& rhs) noexcept
{
    numerator *= rhs.numerator;
    denominator *= rhs.denominator;
    int gcd = greatestCommonDivisor(abs(numerator), denominator);
    numerator /= gcd;
    denominator /= gcd;
    return *this;
}
Rational& Rational::operator*=(const int rhs) noexcept
{
    *this *= Rational(rhs);
    return *this;
}
Rational operator*(const Rational& lhs, const Rational& rhs) noexcept
{
    Rational t(lhs);
    t *= rhs;
    return t;
}
Rational operator*(const Rational& lhs, const int& rhs) noexcept
{
    Rational t(lhs);
    t *= rhs;
    return t;
}
Rational operator*(const int& lhs, const Rational& rhs) noexcept
{
    Rational t(lhs);
    t *= rhs;
    return t;
}

Rational& Rational::operator/=(const Rational& rhs)
{
    if (rhs.numerator == 0)
    {
        throw std::overflow_error("Divide by zero exception");
    }
    Rational t(0,1);
    if (rhs.numerator < 0)
    {
        t = Rational(-1 * rhs.denominator, -1 * rhs.numerator);
    }
    else
    {
        t = Rational(rhs.denominator, rhs.numerator);
    }
    *this *= t;
    return *this;
}
Rational& Rational::operator/=(const int rhs)
{
    *this /= Rational(rhs);
    return *this;
}
Rational operator/(const Rational& lhs, const Rational& rhs)
{
    Rational t(lhs);
    t /= rhs;
    return t;
}
Rational operator/(const Rational& lhs, const int& rhs)
{
    Rational t(lhs);
    t /= rhs;
    return t;
}
Rational operator/(const int& lhs, const Rational& rhs)
{
    Rational t(lhs);
    t /= rhs;
    return t;
}

bool Rational::operator==(const Rational& rhs) const noexcept
{
    if (numerator == rhs.numerator && denominator == rhs.denominator)
    {
        return true;
    }
    return false;
}
bool Rational::operator==(const int& rhs) const noexcept
{
    if (numerator == rhs && denominator == 1)
    {
        return true;
    }
    return false;
}
bool operator==(const int& lhs, const Rational& rhs) noexcept
{
    return rhs == lhs;
}
bool Rational::operator!=(const Rational& rhs) const noexcept
{
    return !(*this == rhs);
}
bool Rational::operator!=(const int& rhs) const noexcept
{
    return !(*this == rhs);
}
bool operator!=(const int& lhs, const Rational& rhs) noexcept
{
    return !(rhs == lhs);
}

bool testOutput(const std::string& s) noexcept
{
    std::istringstream istrm(s);
    Rational n;
    istrm >> n;
    if (istrm.good())
    {
        std::cout << "Reading success. " << s << " " << n << "\n";
    }
    else
    {
        std::cout << "Reading error. " << s << " " << n << "\n";
    }
    return istrm.good();
}
