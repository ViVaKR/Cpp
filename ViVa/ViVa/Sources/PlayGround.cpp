#include <iostream>
#include "PlayGround.hpp"


template<typename F>
void TemplateEx<F>::Print()
{
    std::cout << this->a << std::endl;
}
