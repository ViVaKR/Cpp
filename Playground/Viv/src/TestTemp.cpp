
#ifdef TESTTEMP_HPP

template <class T>
TestTemp<T>::TestTemp()
{
}

template <class T>
void TestTemp<T>::SetValue(T value)
{
    data = value;
}

template <class T>
T TestTemp<T>::GetValue()
{
    return data;
}
#endif
/// @brief No need to include the implementation in the header file
///        it's just to avoid link errors.
// void TemporaryFunction()
// {
//     TestTemp<int> test;
// }

// #include "../include/TestTemp.hpp"
// template <class T>
// TestTemp<T>::TestTemp()
// {
// }

// template <class T>
// void TestTemp<T>::SetValue(T value)
// {
//     data = value;
// }

// template <class T>
// T TestTemp<T>::GetValue()
// {
//     return data;
// }
