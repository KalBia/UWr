#include "funbin.hpp"

void kalkulator::binfun::eval(std::stack<double> &stos)
{
    double a, b;

    try
    {
        if (stos.size() < 2)
            throw std::invalid_argument("+");

        a = stos.top();
        stos.pop();
        b = stos.top();
        stos.pop();

        a = op(a, b);
    }
    catch (std::invalid_argument e)
    {
        std::clog<< "ERROR: blad w binfun\n";
        throw std::invalid_argument("+");
    }

    stos.push(a);
}
