#pragma once
#include <iostream>
#include <stack>

namespace kalkulator
{
    class symbol
    {
    public:
        virtual void eval(std::stack<double> &stos) = 0;
    };
}
