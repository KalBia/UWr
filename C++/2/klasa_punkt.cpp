#include "klasa_punkt.hpp"
#include "klasa_wektor.hpp"
#include "globalne.hpp"
#include <cmath>
class prosta;

//*******************************************

punkt::punkt(double a, double b)
{
    x = a;
    y = b;
}

punkt::punkt(const punkt &other)
{
    x = other.x;
    y = other.y;
}

punkt& punkt::operator=(const punkt &other)
{
    x = other.x;
    y = other.y;
    return *this;
}

void punkt::przesun(wektor w)
{
    x += w.getx();
    y += w.gety();
}

void punkt::obroc(punkt X, int alfa)
{
    x = (x - X.x)*cos(alfa) - (y - X.y)*sin(alfa) + X.x;
    y = (x - X.x)*sin(alfa) + (y - X.y)*cos(alfa) + X.y;
}

void punkt::sym_wzgl_punktu(punkt X)
{
    wektor w( 2*(X.x - x) , 2*(X.y - y) );
    this->przesun(w);
}

void punkt::sym_wzgl_osi(prosta k)
{
    prosta l = k.prosta_prostopadla_przez_punkt(punkt(x, y));
    punkt X = przeciecie_prostych(k, l);
    wektor w( 2*(X.getx() - x), 2*(X.gety() - y) );
    this->przesun(w);
}

double punkt::getx()
{
    return x;
}

double punkt::gety()
{
    return y;
}

void punkt::setx(double a)
{
    x = a;
}

void punkt::sety(double a)
{
    y = a;
}