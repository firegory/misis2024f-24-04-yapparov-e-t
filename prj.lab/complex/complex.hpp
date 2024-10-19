#include <iosfwd>
#include<sstream>
#ifndef COMPLEX_HPP
#define COMPLEX_HPP

struct Complex
{
    Complex() = default;
    explicit Complex(const double real);
    Complex(const Complex& obj) = default;
    Complex(const double real, const double imaginary);

    ~Complex() = default;

    bool operator==(const Complex& rhs) const;
    bool operator==(const double& rhs) const;
    bool operator!=(const Complex& rhs) const;
    bool operator!=(const double& rhs) const;

    Complex& operator+=(const Complex& rhs);
    Complex& operator+=(const double rhs);
    Complex& operator-=(const Complex& rhs);
    Complex& operator-=(const double rhs);
    Complex& operator*=(const Complex& rhs);
    Complex& operator*=(const double rhs);
    Complex& operator/=(const Complex& rhs);
    Complex& operator/=(const double rhs);

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

    double r = 0.0;
    double i = 0.0;

    static const char start = '{';
    static const char sep = ';';
    static const char end = '}';
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, const double& rhs);
Complex operator+(const double& lhs, const Complex& rhs);

Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const double& rhs);
Complex operator-(const double& lhs, const Complex& rhs);

Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const double& rhs);
Complex operator*(const double& lhs, const Complex& rhs);

Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const double& rhs);
Complex operator/(const double& lhs, const Complex& rhs);

bool operator==(const double& lhs, const Complex& rhs);
bool operator!=(const double& lhs, const Complex& rhs);







#endif // !COMPLEX_HPP