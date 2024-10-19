#include <iostream>
#include<sstream>
#include "complex.hpp"



std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
    return rhs.writeTo(ostrm);
}
std::istream& operator>>(std::istream& istrm, Complex& rhs)
{
    return rhs.readFrom(istrm);
}
std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
    ostrm << start << r << sep << i << end;
    return ostrm;
}
std::istream& Complex::readFrom(std::istream& istrm)
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


Complex& Complex::operator+=(const Complex& rhs)
{
    r += rhs.r;
    i += rhs.i;
    return *this;
}
Complex& Complex::operator+=(const double rhs) 
{
    *this += Complex(rhs);
    return *this;
}
Complex operator+(const Complex& lhs, const Complex& rhs)
{
    Complex t(lhs);
    t += rhs;
    return t;
}
Complex operator+(const Complex& lhs, const double& rhs)
{
    Complex t(lhs);
    t += rhs;
    return t;
}
Complex operator+(const double& lhs, const Complex& rhs)
{
    Complex t(lhs);
    t += rhs;
    return t;
}

Complex& Complex::operator-=(const Complex& rhs)
{
    r -= rhs.r;
    i -= rhs.i;
    return *this;
}
Complex& Complex::operator-=(const double rhs)
{
    *this -= Complex(rhs);
    return *this;
}
Complex operator-(const Complex& lhs, const Complex& rhs)
{
    Complex t(lhs);
    t -= rhs;
    return t;
}
Complex operator-(const Complex& lhs, const double& rhs)
{
    Complex t(lhs);
    t -= rhs;
    return t;
}
Complex operator-(const double& lhs, const Complex& rhs)
{
    Complex t(lhs);
    t -= rhs;
    return t;
}

Complex& Complex::operator*=(const Complex& rhs)
{
    double r1 = rhs.r * r - rhs.i * i;
    i = rhs.i * r + rhs.r * i;
    r = r1;
    return *this;
}
Complex& Complex::operator*=(const double rhs)
{
    *this *= Complex(rhs);
    return *this;
}
Complex operator*(const Complex& lhs, const Complex& rhs)
{
    Complex t(lhs);
    t *= rhs;
    return t;
}
Complex operator*(const Complex& lhs, const double& rhs)
{
    Complex t(lhs);
    t *= rhs;
    return t;
}
Complex operator*(const double& lhs, const Complex& rhs)
{
    Complex t(lhs);
    t *= rhs;
    return t;
}

Complex& Complex::operator/=(const Complex& rhs)
{
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

bool Complex::operator==(const Complex& rhs) const
{
    if (r == rhs.r && i == rhs.i)
    {
        return true;
    }
    return false;
}
bool Complex::operator==(const double& rhs) const
{
    if (r == rhs && i == 0)
    {
        return true;
    }
    return false;
}
bool operator==(const double& lhs, const Complex& rhs)
{
    return rhs == lhs;
}
bool Complex::operator!=(const Complex& rhs) const
{
    return !(*this == rhs);
}
bool Complex::operator!=(const double& rhs) const
{
    return !(*this == rhs);
}
bool operator!=(const double& lhs, const Complex& rhs)
{
    return !(rhs == lhs);
}

bool testOutput(const std::string& s)
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
void testOperations(const Complex& n, const Complex& n1)
{
    std::cout << "\n";
    std::cout << n << " + " << n1 << " = " << (n + n1) << "\n";
    std::cout << n << " - " << n1 << " = " << (n - n1) << "\n";
    std::cout << n << " * " << n1 << " = " << (n * n1) << "\n";
    std::cout << n << " / " << n1 << " = " << (n / n1) << "\n";
    if (n == n1)
    {
        std::cout << n << " = " << n1 << "\n";
    }
    else
    {
        std::cout << n << " != " << n1 << "\n";
    }
}
void testOperationsWithNumber(const Complex& n, const double& n1)
{
    std::cout << "\n";
    std::cout << n << " + " << n1 << " = " << (n + n1) << "\n";
    std::cout << n1 << " + " << n << " = " << (n1 + n) << "\n";
    std::cout << n << " - " << n1 << " = " << (n - n1) << "\n";
    std::cout << n1 << " - " << n << " = " << (n1 - n) << "\n";
    std::cout << n << " * " << n1 << " = " << (n * n1) << "\n";
    std::cout << n1 << " * " << n << " = " << (n1 * n) << "\n";
    std::cout << n << " / " << n1 << " = " << (n / n1) << "\n";
    std::cout << n1 << " / " << n << " = " << (n1 / n) << "\n";
    if (n == n1)
    {
        std::cout << n << " = " << n1 << "\n";
    }
    else
    {
        std::cout << n << " != " << n1 << "\n";
    }
    if (n1 == n)
    {
        std::cout << n1 << " = " << n << "\n";
    }
    else
    {
        std::cout << n1 << " != " << n << "\n";
    }
}


int main()
{
    Complex n(0, 0);
    Complex n1(0, 0);
    std::string tempStr;
    std::cout << "The numbers should be inputed in format {R;I}, where R is a real part of the number and I is the imaginary part\n";

    std::cout << "\nInput the first number: ";
    std::cin >> tempStr;
    while(!testOutput(tempStr))
    {
        std::cout << "\nInput the first number again: ";
        std::cin >> tempStr;
    }
    std::istringstream istrm(tempStr);
    istrm >> n;

    std::cout << "\nInput the second number: ";
    std::cin >> tempStr;
    while (!testOutput(tempStr))
    {
        std::cout << "\nInput the second number again: ";
        std::cin >> tempStr;
    }
    istrm = std::istringstream(tempStr);
    istrm >> n1;

    testOperations(n, n1);

    double r = 0;
    std::cout << "\nInput a real number: ";
    std::cin >> r;
    testOperationsWithNumber(n, r);
}

