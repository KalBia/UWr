#include <stdexcept>
#include "klasa_odcinek.hpp"
#include "klasa_punkt.hpp"
#include "klasa_wektor.hpp"
#include "klasa_prosta.hpp"
#include "globalne.hpp"
#include <stdio.h>
#include <algorithm>
using namespace std;

//*******************************************

odcinek::odcinek(punkt X, punkt Y)
{
    if (X.getx() == Y.getx() && X.gety() == Y.gety())
        throw invalid_argument("Nie mozna utworzyc odcinka o dlugosci 0");
    
    A = X;
    B = Y;
}

odcinek::odcinek(const odcinek &other)
{
    A = other.A;
    B = other.B;
}

odcinek& odcinek::operator=(const odcinek &other)
{
    A = other.A;
    B = other.B;
    return *this;
}

void odcinek::przesun(wektor w)
{
    A.przesun(w);
    B.przesun(w);
}

void odcinek::obroc(punkt X, int alfa)
{
    A.obroc(X, alfa);
    B.obroc(X, alfa);
}

void odcinek::sym_wzgl_punktu(punkt X)
{
    A.sym_wzgl_punktu(X);
    B.sym_wzgl_punktu(X);
}

void odcinek::sym_wzgl_osi(prosta k)
{
    A.sym_wzgl_osi(k);
    B.sym_wzgl_osi(k);
}

double odcinek::dlugosc_odcinka()
{
    return odleglosc_miedzy_punktami(A, B);
}

bool odcinek::czy_punkt_nalezy(punkt X)
{
    double matrix = A.getx()*B.gety() + B.getx()*X.gety() + X.getx()*A.gety()
                    - B.getx()*A.gety() - A.getx()*X.gety() - X.getx()*B.gety();
    
    if (matrix == 0 && min(A.getx(), B.getx()) <= X.getx() && max(A.getx(), B.getx()) >= X.getx()
            && min(A.gety(), B.gety()) <= X.gety() && max(A.gety(), B.gety()) >= X.gety())
        return true;
    return false;
}

punkt odcinek::getA()
{
    return A;
}

punkt odcinek::getB()
{
    return B;
}

void odcinek::setA(punkt X)
{
    A = X;
}

void odcinek::setB(punkt X)
{
    B = X;
}