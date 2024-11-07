#include <iosfwd>
#include<sstream>

#ifndef Rational_HPP
#define Rational_HPP

class Rational
{
private:
    int numerator = 0;
    int denominator = 1;

    static const char sep = '/';
public:
    Rational() = default;
    explicit Rational(const int real);
    Rational(const Rational& obj) = default;
    Rational(const int real, const int imaginary);

    ~Rational() = default;

    Rational& operator=(const Rational&) = default;

    bool operator==(const Rational& rhs) const noexcept;
    bool operator==(const int& rhs) const noexcept;
    bool operator!=(const Rational& rhs) const noexcept;
    bool operator!=(const int& rhs) const noexcept;

    bool operator>(const Rational& rhs) const noexcept;
    bool operator>(const int& rhs) const noexcept;
    bool operator>=(const Rational& rhs) const noexcept;
    bool operator>=(const int& rhs) const noexcept;
    bool operator<(const Rational& rhs) const noexcept;
    bool operator<(const int& rhs) const noexcept;
    bool operator<=(const Rational& rhs) const noexcept;
    bool operator<=(const int& rhs) const noexcept;

    Rational operator-() const noexcept;
    Rational& operator+=(const Rational& rhs) noexcept;
    Rational& operator+=(const int rhs) noexcept;
    Rational& operator-=(const Rational& rhs) noexcept;
    Rational& operator-=(const int rhs) noexcept;
    Rational& operator*=(const Rational& rhs) noexcept;
    Rational& operator*=(const int rhs) noexcept;
    Rational& operator/=(const Rational& rhs);
    Rational& operator/=(const int rhs);

    std::ostream& writeTo(std::ostream& ostrm) const noexcept;
    std::istream& readFrom(std::istream& istrm) noexcept;

    int num();
    int den();
};

Rational operator+(const Rational& lhs, const Rational& rhs) noexcept;
Rational operator+(const Rational& lhs, const int& rhs) noexcept;
Rational operator+(const int& lhs, const Rational& rhs) noexcept;

Rational operator-(const Rational& lhs, const Rational& rhs) noexcept;
Rational operator-(const Rational& lhs, const int& rhs) noexcept;
Rational operator-(const int& lhs, const Rational& rhs) noexcept;

Rational operator*(const Rational& lhs, const Rational& rhs) noexcept;
Rational operator*(const Rational& lhs, const int& rhs) noexcept;
Rational operator*(const int& lhs, const Rational& rhs) noexcept;

Rational operator/(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const int& rhs);
Rational operator/(const int& lhs, const Rational& rhs);

bool operator==(const int& lhs, const Rational& rhs) noexcept;
bool operator!=(const int& lhs, const Rational& rhs) noexcept;

bool operator>(const int& lhs, const Rational& rhs) noexcept;
bool operator>=(const int& lhs, const Rational& rhs) noexcept;
bool operator<(const int& lhs, const Rational& rhs) noexcept;
bool operator<=(const int& lhs, const Rational& rhs) noexcept;

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept;
std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept;

bool testOutput(const std::string& s) noexcept;

#endif // !Rational_HPP