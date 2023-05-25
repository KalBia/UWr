#include <iostream>
#include <stdexcept>
#include "klasa_odcinek.hpp"
#include "klasa_prosta.hpp"
#include "klasa_punkt.hpp"
#include "klasa_trojkat.hpp"
#include "klasa_wektor.hpp"
#include "globalne.hpp"
using namespace std;

//*******************************************

int main()
{
    // bank zmiennych
    punkt A(2, 5);
    punkt B(3, 4);
    punkt C(7, 3);
    punkt X(4, 7);
    punkt Y(6, 0);
    punkt Z(0, 5);
    punkt K(-5, 6);
    punkt L(-4, 5);
    punkt M(-3, 6);
    punkt S(1, 1);
    odcinek AB(A, B); // (2, 5)   (3, 4)
    odcinek CX(C, X); // (7, 1)   (4, 7)
    odcinek KL(K, L); // (-5, 6)  (-4, 5)
    odcinek LM(L, M); // (-4, 5)  (-3, 6)
    trojkat ABC(A, B, C); // (2, 5)   (3, 4)   (7, 1)
    trojkat XYZ(X, Y, Z); // (4, 7)   (6, 0)   (0, 5)
    trojkat KLM(K, L, M); // (-5, 6)  (-4, 5)  (-3, 6)
    trojkat CMS(C, M, S); // (7, 3)   (-3, 6)  (1, 1)
    wektor w(1, 2); // [1, 2]
    prosta k(1, 7); // y = x + 7

    //*******************************************

    cout<< "\nPUNKT\n";
    A.przesun(w);
    cout<< "\nPunkt A przesuniety o wektor w: ( " << A.getx() << " , " << A.gety() << " )";
    A.obroc(X, 45);
    cout<< "\nPunkt A obrocony wzgl X o 45 stopni: ( " << A.getx() << " , " << A.gety() << " )";
    A.sym_wzgl_punktu(X);
    cout<< "\nPunkt A po symetrii wzgl X: ( " << A.getx() << " , " << A.gety() << " )";
    A.sym_wzgl_osi(k);
    cout<< "\nPunkt A po symetrii wzgl k: ( " << A.getx() << " , " << A.gety() << " )";
    cout<< "\nPowrot do oryginalnych wspolrzednych punktu A";
    A = punkt(2, 5);

    //*******************************************

    cout<< "\n\nODCINEK\n";
    AB.przesun(w);
    cout<< "\nOdcinek AB przesuniety o wektor w: ( " 
        << AB.getA().getx() << " , " << AB.getA().gety() << " )   " <<
        "( " << AB.getB().getx() << " , " << AB.getB().gety() << " )";
    AB.obroc(X, 45);
    cout<< "\nOdcinek AB obrocony wzgl X o 45 stopni: ( " 
        << AB.getA().getx() << " , " << AB.getA().gety() << " )   " <<
        "( " << AB.getB().getx() << " , " << AB.getB().gety() << " )";
    AB.sym_wzgl_punktu(X);
    cout<< "\nOdcinek AB po symetrii wzgl X: ( " 
        << AB.getA().getx() << " , " << AB.getA().gety() << " )   " <<
        "( " << AB.getB().getx() << " , " << AB.getB().gety() << " )";
    AB.sym_wzgl_osi(k);
    cout<< "\nOdcinek AB po symetrii wzgl k: ( " 
        << AB.getA().getx() << " , " << AB.getA().gety() << " )   " <<
        "( " << AB.getB().getx() << " , " << AB.getB().gety() << " )";

    cout<< "\nPowrot do oryginalnych wspolrzednych odcinka AB";
    AB = odcinek(A, B);
    cout<< "\nDlugosc odcinka AB: " << AB.dlugosc_odcinka();
    cout<< "\nCzy X nalezy do AB? " << AB.czy_punkt_nalezy(X);
    cout<< "\nCzy A nalezy do AB? " << AB.czy_punkt_nalezy(A);

    //*******************************************

    cout<< "\n\nTROJKAT\n";
    ABC.przesun(w);
    cout<< "\nTrojkat ABC przesuniety o wektor w: ( " 
        << ABC.getA().getx() << " , " << ABC.getA().gety() << " )   " <<
        "( " << ABC.getB().getx() << " , " << ABC.getB().gety() << " )   " <<
        "( " << ABC.getC().getx() << " , " << ABC.getC().gety() << " )";
    ABC.obroc(X, 45);
    cout<< "\nTrojkat ABC obrocony wzgl X o 45 stopni:: ( " 
        << ABC.getA().getx() << " , " << ABC.getA().gety() << " )   " <<
        "( " << ABC.getB().getx() << " , " << ABC.getB().gety() << " )   " <<
        "( " << ABC.getC().getx() << " , " << ABC.getC().gety() << " )";
    ABC.sym_wzgl_punktu(X);
    cout<< "\nTrojkat ABC po symetrii wzgl X: ( " 
        << ABC.getA().getx() << " , " << ABC.getA().gety() << " )   " <<
        "( " << ABC.getB().getx() << " , " << ABC.getB().gety() << " )   " <<
        "( " << ABC.getC().getx() << " , " << ABC.getC().gety() << " )";
    ABC.sym_wzgl_osi(k);
    cout<< "\nTrojkat ABC po symetrii wzgl k: ( " 
        << ABC.getA().getx() << " , " << ABC.getA().gety() << " )   " <<
        "( " << ABC.getB().getx() << " , " << ABC.getB().gety() << " )   " <<
        "( " << ABC.getC().getx() << " , " << ABC.getC().gety() << " )";

    cout<< "\nPowrot do oryginalnych wspolrzednych wierzcholkow trojkata ABC";
    ABC = trojkat(A, B, C);
    cout<< "\nObwod trojkata ABC: " << ABC.obwod_trojkata();
    cout<< "\nPole trojkata ABC: " << ABC.pole_trojkata();
    cout<< "\nCzy X nalezy do ABC? " << ABC.czy_punkt_nalezy(X);
    cout<< "\nCzy A nalezy do ABC? " << ABC.czy_punkt_nalezy(A);
    cout<< "\nCzy A nalezy do XYZ? " << XYZ.czy_punkt_nalezy(A);

    //*******************************************

    cout<< "\n\nGLOBALNE\n";
    cout<< "\nOdleglosc miedzy punktami A i B: " << odleglosc_miedzy_punktami(A,B);
    cout<< "\nCzy odc AB || do CX? " << czy_odcinki_rownolegle(AB, CX);
    cout<< "\nCzy odc AB || do KL? " << czy_odcinki_rownolegle(AB, KL);
    cout<< "\nCzy odc AB prost. do CX? " << czy_odcinki_prostopadle(AB, CX);
    cout<< "\nCzy odc AB prost. do LM? " << czy_odcinki_prostopadle(AB, LM);
    cout<< "\nCzy trojkaty ABC i XYZ rozlaczne? " << czy_trojkaty_rozlaczne(ABC, XYZ);
    cout<< "\nCzy trojkaty ABC i KLM rozlaczne? " << czy_trojkaty_rozlaczne(ABC, KLM);
    cout<< "\nCzy trojkaty XYZ i CMS rozlaczne? " << czy_trojkaty_rozlaczne(XYZ, CMS);
    cout<< "\nCzy trojkaty ABC i XYZ sie zawieraja? " << czy_zawiera_sie_trojkaty(ABC, XYZ);
    cout<< "\nCzy trojkaty ABC i KLM sie zawieraja? " << czy_zawiera_sie_trojkaty(ABC, KLM);
    cout<< "\nCzy trojkaty KLM i CMS sie zawieraja? " << czy_zawiera_sie_trojkaty(KLM, CMS);
}