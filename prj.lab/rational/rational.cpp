#include "rational.hpp"

#include <iostream>
#include<sstream>
#include<string>
#include<cstdint>


void Rational::normalize() {
    int32_t a = std::abs(numerator);
    int32_t b = std::abs(denominator);
    if (a < b) {
        std::swap(a, b);
    }

    while (b) {
        a %= b;
        std::swap(a, b);
    }

    numerator /= a;
    denominator /= a;
    if (denominator < 0)
    {
        denominator *= -1;
        numerator *= -1;
    }
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
    ostrm << numerator << sep << denominator;
    return ostrm;
}
std::istream& Rational::readFrom(std::istream& istrm) noexcept
{
    char sepT = ' ';
    int32_t num = 0;
    int32_t den = 0;
    bool minus = false;
    if (istrm.peek() == '-')
    {
        minus = true;
        istrm.get();
    }
    if (!isdigit(istrm.peek()))
    {
        istrm.setstate(std::ios_base::failbit);
        return istrm;
    }
    istrm >> num;
    if (minus)
    {
        num *= -1; minus = false;
    }
    if (istrm.peek() == ' ')
    {
        istrm.get();
    }
    sepT = istrm.get();
    if (istrm.peek() == ' ')
    {
        istrm.get();
    }
    if (istrm.peek() == '-')
    {
        minus = true;
        istrm.get();
    }
    if (!isdigit(istrm.peek()))
    {
        istrm.setstate(std::ios_base::failbit);
        return istrm;
    }
    istrm >> den;
    if (minus)
    {
        den *= -1; minus = false;
    }
    if (Rational::sep == sepT && den > 0)
    {
        *this = Rational(num, den);
        if (!istrm.good())
        {
            istrm.clear();
        }
    }
    else
    {
        istrm.setstate(std::ios_base::failbit);
    }
    return istrm;
}


Rational::Rational(const int32_t numerator) :
    Rational(numerator, 1)
{}
Rational::Rational(const int32_t num, const int32_t den)
{
    if (den == 0)
    {
        throw std::overflow_error("Divide by zero exception");
    }
    numerator = num;
    denominator = den;
    normalize();
}
int32_t Rational::num()
{
    return numerator;
}
int32_t Rational::den()
{
    return denominator;
}

Rational Rational::operator-() const noexcept
{
    return Rational(-1* numerator, denominator);
}

Rational& Rational::operator+=(const Rational& rhs) noexcept
{
    numerator *= rhs.denominator;
    numerator += rhs.numerator * denominator;
    denominator *= rhs.denominator;
    normalize();
    return *this;
}
Rational& Rational::operator+=(const int32_t rhs)  noexcept
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
Rational operator+(const Rational& lhs, const int32_t& rhs) noexcept
{
    Rational t(lhs);
    t += rhs;
    return t;
}
Rational operator+(const int32_t& lhs, const Rational& rhs) noexcept
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
Rational& Rational::operator-=(const int32_t rhs) noexcept
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
Rational operator-(const Rational& lhs, const int32_t& rhs) noexcept
{
    Rational t(lhs);
    t -= rhs;
    return t;
}
Rational operator-(const int32_t& lhs, const Rational& rhs) noexcept
{
    Rational t(lhs);
    t -= rhs;
    return t;
}

Rational& Rational::operator*=(const Rational& rhs) noexcept
{
    numerator *= rhs.numerator;
    denominator *= rhs.denominator;
    normalize();
    return *this;
}
Rational& Rational::operator*=(const int32_t rhs) noexcept
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
Rational operator*(const Rational& lhs, const int32_t& rhs) noexcept
{
    Rational t(lhs);
    t *= rhs;
    return t;
}
Rational operator*(const int32_t& lhs, const Rational& rhs) noexcept
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
    numerator *= rhs.denominator;
    denominator *= rhs.numerator;
    normalize();
    return *this;
}
Rational& Rational::operator/=(const int32_t rhs)
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
Rational operator/(const Rational& lhs, const int32_t& rhs)
{
    Rational t(lhs);
    t /= rhs;
    return t;
}
Rational operator/(const int32_t& lhs, const Rational& rhs)
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
bool Rational::operator==(const int32_t& rhs) const noexcept
{
    if (numerator == rhs && denominator == 1)
    {
        return true;
    }
    return false;
}
bool operator==(const int32_t& lhs, const Rational& rhs) noexcept
{
    return rhs == lhs;
}
bool Rational::operator!=(const Rational& rhs) const noexcept
{
    return !(*this == rhs);
}
bool Rational::operator!=(const int32_t& rhs) const noexcept
{
    return !(*this == rhs);
}
bool operator!=(const int32_t& lhs, const Rational& rhs) noexcept
{
    return !(rhs == lhs);
}

bool Rational::operator>(const Rational& rhs) const noexcept
{
    if (numerator * rhs.denominator > rhs.numerator * denominator)
    {
        return true;
    }
    return false;
}
bool Rational::operator>=(const Rational& rhs) const noexcept
{
    return (*this > rhs || *this == rhs);
}
bool Rational::operator<(const Rational& rhs) const noexcept
{
    return rhs > *this;
}
bool Rational::operator<=(const Rational& rhs) const noexcept
{
    return (*this < rhs || *this == rhs);
}

bool Rational::operator>(const int32_t& rhs) const noexcept
{
    return *this > Rational(rhs);
}
bool Rational::operator>=(const int32_t& rhs) const noexcept
{
    return *this >= Rational(rhs);
}
bool Rational::operator<(const int32_t& rhs) const noexcept
{
    return *this < Rational(rhs);
}
bool Rational::operator<=(const int32_t& rhs) const noexcept
{
    return *this <= Rational(rhs);
}

bool operator>(const int32_t& lhs, const Rational& rhs) noexcept
{
    return rhs < lhs;
}
bool operator>=(const int32_t& lhs, const Rational& rhs) noexcept
{
    return rhs <= lhs;
}
bool operator<(const int32_t& lhs, const Rational& rhs) noexcept
{
    return rhs > lhs;
}
bool operator<=(const int32_t& lhs, const Rational& rhs) noexcept
{
    return rhs >= lhs;
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
