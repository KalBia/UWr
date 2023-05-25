#include "klasa_odcinek.hpp"
#include "klasa_prosta.hpp"
#include "klasa_punkt.hpp"
#include "klasa_trojkat.hpp"
#include "klasa_wektor.hpp"
#include <stdexcept>
using namespace std;

//*******************************************

prosta::prosta(double x, double y)
{
    a = x;
    b = y;
}

prosta& prosta::operator=(const prosta &other)
{
    a = other.a;
    b = other.b;
    return *this;
}

double prosta::geta()
{
    return a;
}

double prosta::getb()
{
    return b;
}

void prosta::seta(double x)
{
    a = x;
}

void prosta::setb(double x)
{
    b = x;
}

prosta prosta::prosta_prostopadla_przez_punkt(punkt X)
{
    if (a == 0)
        throw invalid_argument("Nie da się zapisać prostej w postaci kierunkowej");

    double new_a = (-1)/a;
    double new_b = X.gety() - new_a*X.getx();
    return prosta(new_a, new_b);
}

bool prosta::czy_po_tej_samej_stronie(punkt X, punkt Y)
{
    double resX = a * X.getx() - X.gety() + b;
    double resY = a * Y.getx() - Y.gety() + b;

    if (resX * resY > 0)
        return true;
    return false;
}