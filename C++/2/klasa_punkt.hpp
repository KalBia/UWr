#ifndef klasa_punkt
#define klasa_punkt
#include "klasa_wektor.hpp"
#include "klasa_prosta.hpp"

//*******************************************

class punkt
{
private:
    double x;
    double y;

public:
    punkt() = default;
    punkt(double a, double b);
    punkt(const punkt &other);
    punkt& operator=(const punkt &other);

    void przesun(wektor w);
    void obroc(punkt X, int alfa);
    void sym_wzgl_punktu(punkt X);
    void sym_wzgl_osi(prosta k);

    double getx();
    double gety();
    void setx(double a);
    void sety(double a);
};

//*******************************************

#endif