#include <iostream>
#include "kolor.hpp"
#include "piksel.hpp"
#include "global.hpp"
using namespace std;

//*******************************************

int main()
{
    cout<< "\nKLASA: KOLOR\n";

    kolor Kpusty = kolor();
    cout<< "\nKONSTRUKTOR NR 1\n";
    cout<< Kpusty;

    kolor Kwart = kolor(100, 120, 200);
    cout<< "\nKONSTRUKTOR NR 2\n";
    cout<< Kwart;
    //cout<< "\nBledne wartosci:\n";
    //kolor Kblad = kolor(100, 300, 0);

    cout<< "\nGETTERY\n";
    cout<< "R: " << Kwart.getR() << "\n";
    cout<< "G: " << Kwart.getG() << "\n";
    cout<< "B: " << Kwart.getB() << "\n";

    cout<< "\nSETTERY\n";
    Kwart.setR(150);
    Kwart.setG(117);
    Kwart.setB(42);
    cout<< Kwart;
    //cout<< "Bledna wartosc:\n";
    //Kwart.setR(-15);

    cout<< "\nBRIGHT\n";
    Kwart.bright();
    cout<< Kwart;
    cout<< "\nDARK\n";
    Kwart.dark();
    cout<< Kwart;

    kolor Kwart2 = kolor(50, 100, 150);
    cout<< "\nMIX\n";
    cout<< kolor::mix(Kwart, Kwart2);

    cout<< "\n\nKLASA: KOLOR TRANSPARENTNY\n";

    kolortransparentny KTpusty = kolortransparentny();
    cout<< "\nKONSTRUKTOR NR 1\n";
    cout<< KTpusty;

    kolortransparentny KTwart = kolortransparentny(100, 120, 200, 50);
    cout<< "\nKONSTRUKTOR NR 2\n";
    cout<< KTwart;
    //cout<< "\nBledne wartosci:\n";
    //kolortransparentny KTblad = kolortransparentny(100, 100, 0, 500);

    cout<< "\nGETTERY\n";
    cout<< "alfa: " << KTwart.getAlfa() << "\n";

    cout<< "\nSETTERY\n";
    KTwart.setAlfa(150);
    cout<< KTwart;
    //cout<< "Bledna wartosc:\n";
    //KTwart.setAlfa(-15);

    cout<< "\n\nKLASA: KOLOR NAZWANY\n";

    kolornazwany KNpusty = kolornazwany();
    cout<< "\nKONSTRUKTOR NR 1\n";
    cout<< KNpusty;

    kolornazwany KNwart = kolornazwany(100, 120, 200, "rose");
    cout<< "\nKONSTRUKTOR NR 2\n";
    cout<< KNwart;
    //cout<< "\nBledne wartosci:\n";
    //kolornazwany KNblad = kolornazwany(100, 100, 0, "a17a");

    cout<< "\nGETTERY\n";
    cout<< "name: " << KNwart.getName() << "\n";

    cout<< "\nSETTERY\n";
    KNwart.setName("ocean");
    cout<< KNwart;
    //cout<< "Bledna wartosc:\n";
    //KNwart.setName("WEIRD");

    cout<< "\n\nKLASA: KOLOR NT\n";

    kolornt KNTpusty = kolornt();
    cout<< "\nKONSTRUKTOR NR 1\n";
    cout<< KNTpusty;

    kolornt KNTwart = kolornt(100, 120, 200, 50, "rose");
    cout<< "\nKONSTRUKTOR NR 2\n";
    cout<< KNTwart;
    //cout<< "\nBledne wartosci:\n";
    //kolornt KNTblad = kolornt(100, 100, 0, 500, "sth");

    cout<< "\nGETTERY\n";
    cout<< "alfa: " << KNTwart.getAlfa() << "\n";
    cout<< "name: " << KNTwart.getName() << "\n";

    cout<< "\nSETTERY\n";
    KNTwart.setAlfa(150);
    cout<< KNTwart;
    //cout<< "Bledna wartosc:\n";
    //KNTwart.setAlfa(-15);
    KNTwart.setName("ocean");
    cout<< KNTwart;
    //cout<< "Bledna wartosc:\n";
    //KNTwart.setName("St7");

    cout<< "\n\nKLASA: PIKSEL\n";

    piksel Ppusty = piksel();
    cout<< "\nKONSTRUKTOR NR 1\n";
    cout<< Ppusty;

    piksel Pwart = piksel(100, 200);
    cout<< "\nKONSTRUKTOR NR 2\n";
    cout<< Pwart;
    //cout<< "\nBledne wartosci:\n";
    //piksel Pblad = piksel(3000, 200);

    cout<< "\nGETTERY\n";
    cout<< "x: " << Pwart.getx() << "\n";
    cout<< "y: " << Pwart.gety() << "\n";

    cout<< "\nSETTERY\n";
    Pwart.setx(150);
    cout<< Pwart;
    //cout<< "Bledna wartosc:\n";
    //Pwart.setx(-17);
    Pwart.sety(150);
    cout<< Pwart;
    //cout<< "Bledna wartosc:\n";
    //Pwart.sety(-17);

    cout<< "\nDIST-\n";
    cout<< "LEFT: " << Pwart.distLeft() << endl;
    cout<< "RIGHT: " << Pwart.distRight() << endl;
    cout<< "UP: " << Pwart.distUp() << endl;
    cout<< "DOWN: " << Pwart.distDown() << endl;

    cout<< "\n\nKLASA: PIKSEL KOLOROWY\n";

    pikselkolorowy PKpusty = pikselkolorowy();
    cout<< "\nKONSTRUKTOR NR 1\n";
    cout<< PKpusty;

    pikselkolorowy PKwart = pikselkolorowy(100, 200, KTwart);
    cout<< "\nKONSTRUKTOR NR 2\n";
    cout<< PKwart;
    //cout<< "\nBledne wartosci:\n";
    //pikselkolorowy PKblad = pikselkolorowy(300, 20000, KTwart);

    cout<< "\nGETTERY\n";
    cout<< "kolor: " << PKwart.getKolor() << "\n";

    cout<< "\nMOVE\n";
    PKwart.movePiksel(5, 9);
    cout<< PKwart;
    //cout<< "Bledna wartosc:";
    //PKwart.movePiksel(3000, 0);

    cout<< "\nODLEGLOSC\n";
    cout<< odleglosc(Pwart, PKwart);

    cout<< "\n\nKONIEC\n";
}