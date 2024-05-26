#ifndef RATIONALNUMBER_HPP
#define RATIONALNUMBER_HPP
#include <iostream>
class RationalNumber
{
  private:
    int numberator;
    int denominator;
    void reduction();

  public:
    RationalNumber(int n, int d = 1) : numberator(n), denominator(d)
    {
        reduction();
    }

    const RationalNumber operator+(const RationalNumber &r);
    const RationalNumber operator-(const RationalNumber &r);
    const RationalNumber operator*(const RationalNumber &r);
    const RationalNumber operator/(const RationalNumber &r);
    const RationalNumber operator%(const RationalNumber &r);
    const RationalNumber operator++();

    int GetNumberator();
    int GetDemoninator();

    bool operator==(const RationalNumber &r);
    bool operator!=(const RationalNumber &r);
    bool operator<(const RationalNumber &r);
    bool operator>(const RationalNumber &r);
    bool operator<=(const RationalNumber &r);
    bool operator>=(const RationalNumber &r);

    void Print(std::string op);

    ~RationalNumber();
};

#endif // RATIONALNUMBER_HPP
