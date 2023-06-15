#include "funun.hpp"

void kalkulator::unfun::eval(std::stack<double> &stos)
{
    double x;

    try
    {
        if (stos.size() < 1)
            throw std::invalid_argument("+");

        x = stos.top();
        stos.pop();

        x = op(x);
    }
    catch (std::invalid_argument e)
    {
        std::clog<< "ERROR: blad w unfun\n";
        throw std::invalid_argument("+");
    }

    stos.push(x);
}
