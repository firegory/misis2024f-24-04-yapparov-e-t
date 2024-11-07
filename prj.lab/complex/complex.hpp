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

    bool operator==(const Complex& rhs) const noexcept;
    bool operator==(const double& rhs) const noexcept;
    bool operator!=(const Complex& rhs) const noexcept;
    bool operator!=(const double& rhs) const noexcept;

    Complex operator-() const noexcept;
    Complex& operator+=(const Complex& rhs) noexcept;
    Complex& operator+=(const double rhs) noexcept;
    Complex& operator-=(const Complex& rhs) noexcept;
    Complex& operator-=(const double rhs) noexcept;
    Complex& operator*=(const Complex& rhs) noexcept;
    Complex& operator*=(const double rhs) noexcept;
    Complex& operator/=(const Complex& rhs);
    Complex& operator/=(const double rhs);

    std::ostream& writeTo(std::ostream& ostrm) const noexcept;
    std::istream& readFrom(std::istream& istrm) noexcept;

    double r = 0.0;
    double i = 0.0;

    static const char start = '{';
    static const char sep = ';';
    static const char end = '}';
};

Complex operator+(const Complex& lhs, const Complex& rhs) noexcept;
Complex operator+(const Complex& lhs, const double& rhs) noexcept;
Complex operator+(const double& lhs, const Complex& rhs) noexcept;

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept;
Complex operator-(const Complex& lhs, const double& rhs) noexcept;
Complex operator-(const double& lhs, const Complex& rhs) noexcept;

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept;
Complex operator*(const Complex& lhs, const double& rhs) noexcept;
Complex operator*(const double& lhs, const Complex& rhs) noexcept;

Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const double& rhs);
Complex operator/(const double& lhs, const Complex& rhs);

bool operator==(const double& lhs, const Complex& rhs) noexcept;
bool operator!=(const double& lhs, const Complex& rhs) noexcept;

std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) noexcept;
std::istream& operator>>(std::istream& istrm, Complex& rhs) noexcept;

bool testOutput(const std::string& s) noexcept;

#endif // !COMPLEX_HPP