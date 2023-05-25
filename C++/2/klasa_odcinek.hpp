#ifndef klasa_odcinek
#define klasa_odcinek
#include "klasa_punkt.hpp"
#include "klasa_wektor.hpp"
#include "klasa_prosta.hpp"

//*******************************************

class odcinek
{
private:
    punkt A;
    punkt B;

public:
    odcinek(punkt X, punkt Y);
    odcinek(const odcinek &other);
    odcinek& operator=(const odcinek &other);

    void przesun(wektor w);
    void obroc(punkt X, int alfa);
    void sym_wzgl_punktu(punkt X);
    void sym_wzgl_osi(prosta k);
    double dlugosc_odcinka();
    bool czy_punkt_nalezy(punkt X);

    punkt getA();
    punkt getB();
    void setA(punkt X);
    void setB(punkt X);
};

//*******************************************

#endif