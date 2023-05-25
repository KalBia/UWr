#include "klasa_odcinek.hpp"
#include "klasa_punkt.hpp"
#include "klasa_trojkat.hpp"
#include "klasa_wektor.hpp"

//*******************************************

wektor::wektor(double a, double b)
{
    x = a;
    y = b;
}

double wektor::getx()
{
    return x;
}

double wektor::gety()
{
    return y;
}

void wektor::setx(double a)
{
    x = a;
}

void wektor::sety(double a)
{
    y = a;
}