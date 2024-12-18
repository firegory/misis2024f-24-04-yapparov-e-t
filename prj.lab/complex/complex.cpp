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
    ostrm << start << re << sep << im << end;
    return ostrm;
}
std::istream& Complex::readFrom(std::istream& istrm) noexcept
{
    char startT = ' ';
    char sepT = ' ';
    char endT = ' ';
    bool minus = false;
    double real = 0;
    double imaginary = 0;
    startT = istrm.get();
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
    istrm >> real;
    if (minus)
    {
        real *= -1; minus = false;
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
    istrm >> imaginary;
    if (minus)
    {
        real *= -1; minus = false;
    }
    if (istrm.peek() == ' ')
    {
        istrm.get();
    }
    endT = istrm.get();
    if (istrm.good())
    {
        if (Complex::start == startT && Complex::sep == sepT && Complex::end == endT)
        {
            re = real;
            im = imaginary;
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
    re(real),
    im(imaginary)
{}

Complex Complex::operator-() const noexcept
{
    return Complex(-1*re,-1*im);
}

Complex& Complex::operator+=(const Complex& rhs) noexcept
{
    re += rhs.re;
    im += rhs.im;
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
    re -= rhs.re;
    im -= rhs.im;
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
    double r1 = rhs.re * re - rhs.im * im;
    im = rhs.im * re + rhs.re * im;
    re = r1;
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
    if ((rhs.re * rhs.re) + (rhs.im * rhs.im) == 0)
    {
        throw std::overflow_error("Divide by zero exception");
    }
    double t = rhs.re * re + rhs.im * im;
    im = rhs.re * im - rhs.im * re;
    re = t;
    t = (rhs.re * rhs.re) + (rhs.im * rhs.im);
    re /= t;
    im /= t;
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
    if(std::abs(re - rhs.re) <= std::numeric_limits<double>().epsilon()*2 && std::abs(im - rhs.im) <= std::numeric_limits<double>().epsilon() * 2)
    {
        return true;
    }
    return false;
}
bool Complex::operator==(const double& rhs) const noexcept
{
    return *this == Complex(rhs, 0);
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
    //if (istrm.good())
    //{
    //    std::cout << "Reading success. " << s << " " << n << "\n";
    //}
    //else
    //{
    //    std::cout << "Reading error. " << s << " " << n << "\n";
    //}
    return istrm.good();
}