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

    int GetNumerator() const
    {
        return numerator_;
    }
    int GetDenominator() const
    {
        return denominator_;
    }

    explicit operator double()
    {
        return this->to_double();
    }

private:
    int numerator_;
    int denominator_;
};

std::ostream& operator<<(std::ostream& os, Rational const& ratio)
{
    os << ratio.GetNumerator() << "/" << ratio.GetDenominator();
    return os;
}

int main()
{
    Rational r(5, 7);

    std::cout << (double)r << std::endl;
    return 0;
}