#ifndef CALCULATOR_H
#define CALCULATOR_H

template <class T>
class Calculator
{
  private:
    T data_a;
    T data_b;

  public:
    Calculator(T a, T b) : data_a(a), data_b(b) {}

    T Add()
    {
        return data_a + data_b;
    }
    T Sub()
    {
        return data_a - data_b;
    }

    T Mul()
    {
        return data_a * data_b;
    }
    T Div()
    {
        return data_a / data_b;
    }
    ~Calculator() {}
};

#endif
