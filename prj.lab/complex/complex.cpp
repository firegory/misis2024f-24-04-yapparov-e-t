#include "complex.hpp"

#include <iostream>
#include<sstream>




std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) noexcept
{
    return rhs.writeTo(ostrm);
}
std::istream& operator>>(std::istream& istrm, Complex& rhs) noexcept
{
    return rhs.readFrom(istrm);
}
std::ostream& Complex::writeTo(std::ostream& ostrm) const noexcept
{
    ostrm << start << r << sep << i << end;
    return ostrm;
}
std::istream& Complex::readFrom(std::istream& istrm) noexcept
{
    char start = ' ';
    char sep = ' ';
    char end = ' ';
    double real = 0;
    double imaginary = 0;
    istrm >> start >> real >> sep >> imaginary >> end;
    if (istrm.good())
    {
        if (Complex::start == start && Complex::sep == sep && Complex::end == end)
        {
            r = real;
            i = imaginary;
        }
        else
        {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}


Complex::Complex(const double real) :
    Complex(real, 0.0)
{}
Complex::Complex(const double real, const double imaginary) :
    r(real),
    i(imaginary)
{}

Complex Complex::operator-() const noexcept
{
    return Complex(-1*r,-1*i);
}

Complex& Complex::operator+=(const Complex& rhs) noexcept
{
    r += rhs.r;
    i += rhs.i;
    return *this;
}
Complex& Complex::operator+=(const double rhs)  noexcept
{
    *this += Complex(rhs);
    return *this;
}
Complex operator+(const Complex& lhs, const Complex& rhs) noexcept
{
    Complex t(lhs);
    t += rhs;
    return t;
}
Complex operator+(const Complex& lhs, const double& rhs) noexcept
{
    Complex t(lhs);
    t += rhs;
    return t;
}
Complex operator+(const double& lhs, const Complex& rhs) noexcept
{
    Complex t(lhs);
    t += rhs;
    return t;
}

Complex& Complex::operator-=(const Complex& rhs) noexcept
{
    r -= rhs.r;
    i -= rhs.i;
    return *this;
}
Complex& Complex::operator-=(const double rhs) noexcept
{
    *this -= Complex(rhs);
    return *this;
}
Complex operator-(const Complex& lhs, const Complex& rhs) noexcept
{
    Complex t(lhs);
    t -= rhs;
    return t;
}
Complex operator-(const Complex& lhs, const double& rhs) noexcept
{
    Complex t(lhs);
    t -= rhs;
    return t;
}
Complex operator-(const double& lhs, const Complex& rhs) noexcept
{
    Complex t(lhs);
    t -= rhs;
    return t;
}

Complex& Complex::operator*=(const Complex& rhs) noexcept
{
    double r1 = rhs.r * r - rhs.i * i;
    i = rhs.i * r + rhs.r * i;
    r = r1;
    return *this;
}
Complex& Complex::operator*=(const double rhs) noexcept
{
    *this *= Complex(rhs);
    return *this;
}
Complex operator*(const Complex& lhs, const Complex& rhs) noexcept
{
    Complex t(lhs);
    t *= rhs;
    return t;
}
Complex operator*(const Complex& lhs, const double& rhs) noexcept
{
    Complex t(lhs);
    t *= rhs;
    return t;
}
Complex operator*(const double& lhs, const Complex& rhs) noexcept
{
    Complex t(lhs);
    t *= rhs;
    return t;
}

Complex& Complex::operator/=(const Complex& rhs)
{
    if ((rhs.r * rhs.r) + (rhs.i * rhs.i) == 0)
    {
        throw std::overflow_error("Divide by zero exception");
    }
    double t = rhs.r * r + rhs.i * i;
    i = rhs.r * i - rhs.i * r;
    r = t;
    t = (rhs.r * rhs.r) + (rhs.i * rhs.i);
    r /= t;
    i /= t;
    return *this;
}
Complex& Complex::operator/=(const double rhs)
{
    *this /= Complex(rhs);
    return *this;
}
Complex operator/(const Complex& lhs, const Complex& rhs)
{
    Complex t(lhs);
    t /= rhs;
    return t;
}
Complex operator/(const Complex& lhs, const double& rhs)
{
    Complex t(lhs);
    t /= rhs;
    return t;
}
Complex operator/(const double& lhs, const Complex& rhs)
{
    Complex t(lhs);
    t /= rhs;
    return t;
}

bool Complex::operator==(const Complex& rhs) const noexcept
{
    if (r == rhs.r && i == rhs.i)
    {
        return true;
    }
    return false;
}
bool Complex::operator==(const double& rhs) const noexcept
{
    if (r == rhs && i == 0)
    {
        return true;
    }
    return false;
}
bool operator==(const double& lhs, const Complex& rhs) noexcept
{
    return rhs == lhs;
}
bool Complex::operator!=(const Complex& rhs) const noexcept
{
    return !(*this == rhs);
}
bool Complex::operator!=(const double& rhs) const noexcept
{
    return !(*this == rhs);
}
bool operator!=(const double& lhs, const Complex& rhs) noexcept
{
    return !(rhs == lhs);
}

bool testOutput(const std::string& s) noexcept
{
    std::istringstream istrm(s);
    Complex n;
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