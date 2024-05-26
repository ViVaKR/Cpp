#include "../include/RationalNumber.hpp"
#include <iostream>

void RationalNumber::reduction()
{
    int largest;
    largest = (numberator > denominator) ? numberator : denominator;

    int gcd = 0;
    for (int i = 2; i <= largest; i++) {
        if (numberator % i == 0 && denominator % i == 0) {
            gcd = i;
        }
    }

    if (gcd != 0) {
        numberator /= gcd;
        denominator /= gcd;
    }
}

const RationalNumber RationalNumber::operator+(const RationalNumber &r)
{
    return RationalNumber(numberator * r.denominator + r.numberator * denominator, denominator * r.denominator);
}

const RationalNumber RationalNumber::operator-(const RationalNumber &r)
{
    return RationalNumber(numberator * r.denominator - r.numberator * denominator, denominator * r.denominator);
}

const RationalNumber RationalNumber::operator*(const RationalNumber &r)
{
    return RationalNumber(numberator * r.numberator, denominator * r.denominator);
}

const RationalNumber RationalNumber::operator/(const RationalNumber &r)
{
    return RationalNumber(numberator * r.denominator, denominator * r.numberator);
}

const RationalNumber RationalNumber::operator%(const RationalNumber &r)
{
    return RationalNumber(numberator % r.numberator, denominator % r.denominator);
}

const RationalNumber RationalNumber::operator++()
{
    return RationalNumber(numberator + denominator, denominator);
}

int RationalNumber::GetNumberator()
{
    return numberator;
}

int RationalNumber::GetDemoninator()
{
    return denominator;
}

bool RationalNumber::operator==(const RationalNumber &r)
{
    return (numberator == r.numberator && denominator == r.denominator);
}

bool RationalNumber::operator!=(const RationalNumber &r)
{
    return (numberator != r.numberator || denominator != r.denominator);
}

bool RationalNumber::operator<(const RationalNumber &r)
{
    return (numberator * r.denominator < r.numberator * denominator);
}

bool RationalNumber::operator>(const RationalNumber &r)
{
    return (numberator * r.denominator > r.numberator * denominator);
}

bool RationalNumber::operator<=(const RationalNumber &r)
{
    return (numberator * r.denominator <= r.numberator * denominator);
}

bool RationalNumber::operator>=(const RationalNumber &r)
{
    return (numberator * r.denominator >= r.numberator * denominator);
}

void RationalNumber::Print(std::string op)
{
    std::string result =
        GetDemoninator() == 1
            ? std::format("{}", GetNumberator())
            : std::format("{}/{}", GetNumberator(), GetDemoninator());

    std::cout << op << " = " << result << std::endl;
}

RationalNumber::~RationalNumber() {}
