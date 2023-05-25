#include "klasa_odcinek.hpp"
#include "klasa_punkt.hpp"
#include "klasa_trojkat.hpp"
#include "klasa_wektor.hpp"
#include "klasa_prosta.hpp"
#include <cmath>
#include <stdexcept>
#include <iostream>
using namespace std;

//*******************************************

double odleglosc_miedzy_punktami(punkt A, punkt B)
{
    double res1 = (B.getx() - A.getx());
    res1 *= res1;
    double res2 = (B.gety() - A.gety());
    res2 *= res2;
    double res = res1 + res2;
    res = sqrt(res);
    return res;
}

bool czy_odcinki_rownolegle(odcinek A, odcinek B)
{
    wektor a( (A.getB().getx() - A.getA().getx()), (A.getB().gety() - A.getA().gety()) );
    wektor b( (B.getB().getx() - B.getA().getx()), (B.getB().gety() - B.getA().gety()) );

    if (a.getx()*b.gety() - a.gety()*b.getx() == 0)
        return true;
    return false;
}

bool czy_odcinki_prostopadle(odcinek A, odcinek B)
{
    wektor a( (A.getB().getx() - A.getA().getx()), (A.getB().gety() - A.getA().gety()) );
    wektor b( (B.getB().getx() - B.getA().getx()), (B.getB().gety() - B.getA().gety()) );

    if (a.getx()*b.getx() + a.gety()*b.gety() == 0)
        return true;
    return false;
}

prosta prosta_zawierajaca_odcinek(odcinek X)
{
    punkt K = X.getA();
    punkt L = X.getB();

    if (K.getx() == L.getx())
        throw invalid_argument("Nie da się zapisać w postaci kierunkowej");

    double new_a = (K.gety() - L.gety())/(K.getx() - L.getx());
    double new_b = K.gety() - new_a*K.getx();

    return prosta(new_a, new_b);
}

bool czy_trojkaty_rozlaczne(trojkat A, trojkat B)
{
    // sprawdzenie czy któryś punkt z A zawiera się w B
    if ( B.czy_punkt_nalezy(A.getA()) || B.czy_punkt_nalezy(A.getB()) || B.czy_punkt_nalezy(A.getC()) )
        return false;

    // sprawdzenie czy któryś punkt z B zawiera się w A
    if ( A.czy_punkt_nalezy(B.getA()) || A.czy_punkt_nalezy(B.getB()) || A.czy_punkt_nalezy(B.getC()) )
        return false;

    // jedna para wierzcholkow jest po roznych stronach jednego boku AND
    // inna para wierzcholkow jest po roznych stronach innego boku
    odcinek Aa(A.getA(), A.getB());
    odcinek Ab(A.getB(), A.getC());
    odcinek Ac(A.getC(), A.getA());
    odcinek Ba(B.getA(), B.getB());
    odcinek Bb(B.getB(), B.getC());
    odcinek Bc(B.getC(), B.getA());

    prosta PAa = prosta_zawierajaca_odcinek(Aa);
    prosta PAb = prosta_zawierajaca_odcinek(Ab);
    prosta PAc = prosta_zawierajaca_odcinek(Ac);
    prosta PBa = prosta_zawierajaca_odcinek(Ba);
    prosta PBb = prosta_zawierajaca_odcinek(Bb);
    prosta PBc = prosta_zawierajaca_odcinek(Bc);

    //*******************************************

    if (!PAa.czy_po_tej_samej_stronie(B.getA(), B.getB()))
    {
        if (!PAb.czy_po_tej_samej_stronie(B.getA(), B.getC()) || !PAc.czy_po_tej_samej_stronie(B.getA(), B.getC()))
            return false;

        if (!PAb.czy_po_tej_samej_stronie(B.getB(), B.getC()) || !PAc.czy_po_tej_samej_stronie(B.getB(), B.getC()))
            return false;
    }

    if (!PAb.czy_po_tej_samej_stronie(B.getA(), B.getB()))
    {
        if (!PAa.czy_po_tej_samej_stronie(B.getA(), B.getC()) || !PAc.czy_po_tej_samej_stronie(B.getA(), B.getC()))
            return false;

        if (!PAa.czy_po_tej_samej_stronie(B.getB(), B.getC()) || !PAc.czy_po_tej_samej_stronie(B.getB(), B.getC()))
            return false;
    }

    if (!PAc.czy_po_tej_samej_stronie(B.getA(), B.getB()))
    {
        if (!PAb.czy_po_tej_samej_stronie(B.getA(), B.getC()) || !PAa.czy_po_tej_samej_stronie(B.getA(), B.getC()))
            return false;

        if (!PAb.czy_po_tej_samej_stronie(B.getB(), B.getC()) || !PAa.czy_po_tej_samej_stronie(B.getB(), B.getC()))
            return false;
    }

    //*******************************************

    if (!PBa.czy_po_tej_samej_stronie(A.getA(), A.getB()))
    {
        if (!PBb.czy_po_tej_samej_stronie(A.getA(), A.getC()) || !PBc.czy_po_tej_samej_stronie(A.getA(), A.getC()))
            return false;

        if (!PBb.czy_po_tej_samej_stronie(A.getB(), A.getC()) || !PBc.czy_po_tej_samej_stronie(A.getB(), A.getC()))
            return false;
    }

    if (!PBb.czy_po_tej_samej_stronie(A.getA(), A.getB()))
    {
        if (!PBa.czy_po_tej_samej_stronie(A.getA(), A.getC()) || !PBc.czy_po_tej_samej_stronie(A.getA(), A.getC()))
            return false;

        if (!PBa.czy_po_tej_samej_stronie(A.getB(), A.getC()) || !PBc.czy_po_tej_samej_stronie(A.getB(), A.getC()))
            return false;
    }

    if (!PBc.czy_po_tej_samej_stronie(A.getA(), A.getB()))
    {
        if (!PBb.czy_po_tej_samej_stronie(A.getA(), A.getC()) || !PBa.czy_po_tej_samej_stronie(A.getA(), A.getC()))
            return false;

        if (!PBb.czy_po_tej_samej_stronie(A.getB(), A.getC()) || !PBa.czy_po_tej_samej_stronie(A.getB(), A.getC()))
            return false;
    }

    //*******************************************

    return true;
}

bool czy_zawiera_sie_trojkaty(trojkat A, trojkat B)
{
    /*
    //definicja zawierania: jeden cały trojkat jest w drugim
    if ( ( B.czy_punkt_nalezy(A.getA()) ) && ( B.czy_punkt_nalezy(A.getB()) ) &&
        ( B.czy_punkt_nalezy(A.getC()) ) )
        return true;
    
    if ( ( A.czy_punkt_nalezy(B.getA()) ) && ( A.czy_punkt_nalezy(B.getB()) ) &&
        ( A.czy_punkt_nalezy(B.getC()) ) )
        return true;
    
    return false;
    */

    // definicja zawierania: mają część wspólną
    return !(czy_trojkaty_rozlaczne(A, B));
}

punkt przeciecie_prostych(prosta k, prosta l)
{
    if (k.geta() == l.geta()) 
        throw invalid_argument("Proste sa rownolegle. Nie maja punktu przeciecia");

    double resX = (l.getb() - k.getb())/(k.geta() - l.geta());
    double resY = k.geta()*resX + k.getb();
    return punkt(resX, resY);
}