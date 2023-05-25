#ifndef klasa_trojkat
#define klasa_trojkat
#include "klasa_punkt.hpp"
#include "klasa_odcinek.hpp"

//*******************************************

class trojkat
{
private:
    punkt A;
    punkt B;
    punkt C;

public:
    trojkat(punkt X, punkt Y, punkt Z);
    trojkat(const trojkat &other);
    trojkat& operator=(const trojkat &other);

    void przesun(wektor w);
    void obroc(punkt X, int alfa);
    void sym_wzgl_punktu(punkt X);
    void sym_wzgl_osi(prosta k);
    double obwod_trojkata();
    double pole_trojkata();
    bool czy_punkt_nalezy(punkt X);

    punkt getA();
    punkt getB();
    punkt getC();
    void setA(punkt X);
    void setB(punkt X);
    void setC(punkt X);
};

//*******************************************

#endif