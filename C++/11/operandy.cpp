#include "operandy.hpp"

//*******************************************

std::map<std::string, double> kalkulator::zmienna::spis_zmiennych;

//*******************************************

void kalkulator::liczba::eval(std::stack<double> &stos)
{
    stos.push(wartosc);
}

//*******************************************

void kalkulator::zmienna::eval(std::stack<double> &stos)
{
    stos.push(wartosc);
}

//*******************************************

void kalkulator::stala::eval(std::stack<double> &stos)
{
    stos.push(wartosc);
}
