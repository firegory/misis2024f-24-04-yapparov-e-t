#include <iosfwd>
#include<sstream>
#include<cstdint>

#ifndef Rational_HPP
#define Rational_HPP

class Rational
{
private:
    int32_t numerator = 0;
    int32_t denominator = 1;

    static const char sep = '/';
public:
    Rational() = default;
    explicit Rational(const int32_t real);
    Rational(const Rational& obj) = default;
    Rational(const int32_t real, const int32_t imaginary);

    ~Rational() = default;

    Rational& operator=(const Rational&) = default;

    [[nodiscard]] bool operator==(const Rational& rhs) const noexcept;
    [[nodiscard]] bool operator==(const int32_t& rhs) const noexcept;
    [[nodiscard]] bool operator!=(const Rational& rhs) const noexcept;
    [[nodiscard]] bool operator!=(const int32_t& rhs) const noexcept;

    [[nodiscard]] bool operator>(const Rational& rhs) const noexcept;
    [[nodiscard]] bool operator>(const int32_t& rhs) const noexcept;
    [[nodiscard]] bool operator>=(const Rational& rhs) const noexcept;
    [[nodiscard]] bool operator>=(const int32_t& rhs) const noexcept;
    [[nodiscard]] bool operator<(const Rational& rhs) const noexcept;
    [[nodiscard]] bool operator<(const int32_t& rhs) const noexcept;
    [[nodiscard]] bool operator<=(const Rational& rhs) const noexcept;
    [[nodiscard]] bool operator<=(const int32_t& rhs) const noexcept;

    [[nodiscard]] Rational operator-() const noexcept;
    Rational& operator+=(const Rational& rhs) noexcept;
    Rational& operator+=(const int32_t rhs) noexcept;
    Rational& operator-=(const Rational& rhs) noexcept;
    Rational& operator-=(const int32_t rhs) noexcept;
    Rational& operator*=(const Rational& rhs) noexcept;
    Rational& operator*=(const int32_t rhs) noexcept;
    Rational& operator/=(const Rational& rhs);
    Rational& operator/=(const int32_t rhs);

    std::ostream& writeTo(std::ostream& ostrm) const noexcept;
    std::istream& readFrom(std::istream& istrm) noexcept;

    int32_t num();
    int32_t den();
};

[[nodiscard]] Rational operator+(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator+(const Rational& lhs, const int32_t& rhs) noexcept;
[[nodiscard]] Rational operator+(const int32_t& lhs, const Rational& rhs) noexcept;

[[nodiscard]] Rational operator-(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& lhs, const int32_t& rhs) noexcept;
[[nodiscard]] Rational operator-(const int32_t& lhs, const Rational& rhs) noexcept;

[[nodiscard]] Rational operator*(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& lhs, const int32_t& rhs) noexcept;
[[nodiscard]] Rational operator*(const int32_t& lhs, const Rational& rhs) noexcept;

[[nodiscard]] Rational operator/(const Rational& lhs, const Rational& rhs);
[[nodiscard]] Rational operator/(const Rational& lhs, const int32_t& rhs);
[[nodiscard]] Rational operator/(const int32_t& lhs, const Rational& rhs);

[[nodiscard]] bool operator==(const int32_t& lhs, const Rational& rhs) noexcept;
[[nodiscard]] bool operator!=(const int32_t& lhs, const Rational& rhs) noexcept;

[[nodiscard]] bool operator>(const int32_t& lhs, const Rational& rhs) noexcept;
[[nodiscard]] bool operator>=(const int32_t& lhs, const Rational& rhs) noexcept;
[[nodiscard]] bool operator<(const int32_t& lhs, const Rational& rhs) noexcept;
[[nodiscard]] bool operator<=(const int32_t& lhs, const Rational& rhs) noexcept;

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept;
std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept;

bool testOutput(const std::string& s) noexcept;

#endif // !Rational_HPP