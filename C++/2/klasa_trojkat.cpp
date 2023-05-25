#include "klasa_odcinek.hpp"
#include "klasa_punkt.hpp"
#include "klasa_trojkat.hpp"
#include "globalne.hpp"
#include "klasa_prosta.hpp"
#include <cmath>
#include <stdexcept>
using namespace std;

//*******************************************

trojkat::trojkat(punkt X, punkt Y,punkt Z)
{
    prosta xy = prosta_zawierajaca_odcinek(odcinek(X, Y));
    prosta yz = prosta_zawierajaca_odcinek(odcinek(Y, Z));
    if (xy.geta() == yz.geta() && xy.getb() == yz.getb())
        throw invalid_argument("Wszystkie punkty sa wspolliniowe. Nie mozna utworzyc trojkata");

    A = X;
    B = Y;
    C = Z;
}

trojkat::trojkat(const trojkat &other)
{
    A = other.A;
    B = other.B;
    C = other.C;
}

trojkat& trojkat::operator=(const trojkat &other)
{
    A = other.A;
    B = other.B;
    C = other.C;
    return *this;
}

void trojkat::przesun(wektor w)
{
    A.przesun(w);
    B.przesun(w);
    C.przesun(w);
}

void trojkat::obroc(punkt X, int alfa)
{
    A.obroc(X, alfa);
    B.obroc(X, alfa);
    C.obroc(X, alfa);
}

void trojkat::sym_wzgl_punktu(punkt X)
{
    A.sym_wzgl_punktu(X);
    B.sym_wzgl_punktu(X);
    C.sym_wzgl_punktu(X);
}

void trojkat::sym_wzgl_osi(prosta k)
{
    A.sym_wzgl_osi(k);
    B.sym_wzgl_osi(k);
    C.sym_wzgl_osi(k);
}

double trojkat::obwod_trojkata()
{
    return odleglosc_miedzy_punktami(A, B) + odleglosc_miedzy_punktami(B, C) + odleglosc_miedzy_punktami(C, A);
}

double trojkat::pole_trojkata()
{
    double p = this->obwod_trojkata()/2;
    return sqrt(p * (p - odleglosc_miedzy_punktami(A, B)) * (p - odleglosc_miedzy_punktami(B, C)) * (p - odleglosc_miedzy_punktami(C, A)) );
}

bool trojkat::czy_punkt_nalezy(punkt X)
{
    // czy nalezy do ktoregos boku?
    odcinek a(A, B);
    odcinek b(B, C);
    odcinek c(C, A);

    if (a.czy_punkt_nalezy(X))
        return true;
    if (b.czy_punkt_nalezy(X))
        return true;
    if (c.czy_punkt_nalezy(X))
        return true;

    // czy nalezy do srodka?
    prosta Pa = prosta_zawierajaca_odcinek(a);
    prosta Pb = prosta_zawierajaca_odcinek(b);
    prosta Pc = prosta_zawierajaca_odcinek(c);

    if (Pa.czy_po_tej_samej_stronie(X, C) && Pb.czy_po_tej_samej_stronie(X, A) && Pc.czy_po_tej_samej_stronie(X, B))
        return true;

    return false;
}

punkt trojkat::getA()
{
    return A;
}

punkt trojkat::getB()
{
    return B;
}

punkt trojkat::getC()
{
    return C;
}

void trojkat::setA(punkt X)
{
    A = X;
}

void trojkat::setB(punkt X)
{
    B = X;
}

void trojkat::setC(punkt X)
{
    C = X;
}