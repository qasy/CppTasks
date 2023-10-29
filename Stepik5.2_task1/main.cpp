#include <iostream>

struct Rational
{
    Rational(int numerator = 0, int denominator = 1)
        : numerator_(numerator)
        , denominator_(denominator){};

    void add(Rational rational)
    {
        numerator_ = numerator_ * rational.denominator_ + rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void sub(Rational rational)
    {
        numerator_ = numerator_ * rational.denominator_ - rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void mul(Rational rational)
    {
        numerator_ *= rational.numerator_;
        denominator_ *= rational.denominator_;
    }

    void div(Rational rational)
    {
        numerator_ *= rational.denominator_;
        denominator_ *= rational.numerator_;
    }

    void neg()
    {
        numerator_ = -numerator_;
    }

    void inv()
    {
    }

    double to_double() const
    {
        return numerator_ / (double)denominator_;
    }

    Rational& operator+=(const Rational& rational)
    {
        this->add(rational);
        return *this;
    }

    Rational& operator-=(const Rational& rational)
    {
        this->sub(rational);
        return *this;
    }

    Rational& operator*=(const Rational& rational)
    {
        this->mul(rational);
        return *this;
    }

    Rational& operator/=(const Rational& rational)
    {
        this->div(rational);
        return *this;
    }

    Rational operator-() const
    {
        Rational r(this->numerator_, this->denominator_);
        r.neg();
        return r;
    }
    Rational operator+() const
    {
        return *this;
    }

    int GetNumerator() const
    {
        return numerator_;
    }
    int GetDenominator() const
    {
        return denominator_;
    }

private:
    int numerator_;
    int denominator_;
};

Rational operator+(Rational left, const Rational& right)
{
    left += right;
    return left;
}

Rational operator-(Rational left, const Rational& right)
{
    left -= right;
    return left;
}

Rational operator*(Rational left, const Rational& right)
{
    left *= right;
    return left;
}

Rational operator/(Rational left, const Rational& right)
{
    left /= right;
    return left;
}

bool operator==(Rational const& lhs, Rational const& rhs)
{
    return (lhs.GetNumerator() * rhs.GetDenominator() == lhs.GetDenominator() * rhs.GetNumerator());
}
bool operator!=(Rational const& lhs, Rational const& rhs)
{
    return !(lhs == rhs);
}
bool operator<(Rational const& lhs, Rational const& rhs)
{
    return (lhs.GetNumerator() * rhs.GetDenominator() < lhs.GetDenominator() * rhs.GetNumerator());
}
bool operator>(Rational const& lhs, Rational const& rhs)
{
    return rhs < lhs;
}
bool operator<=(Rational const& lhs, Rational const& rhs)
{
    return !(rhs < lhs);
}
bool operator>=(Rational const& lhs, Rational const& rhs)
{
    return !(lhs < rhs);
}

std::ostream& operator<<(std::ostream& os, Rational const& ratio)
{
    os << ratio.GetNumerator() << "/" << ratio.GetDenominator();
    return os;
}

int main()
{
    Rational r(5, 7);
    r = 5 + r;
    std::cout << r << std::endl;
    return 0;
}