#include <iostream>
#include <fstream>
#include "tabbit.hpp"
#include <algorithm>
#include <bitset>
using namespace std;

//*******************************************

int main()
{
    // TEST PIERWSZY
    tab_bit t(46); // tablica 46-bitowa (zainicjalizowana zerami)
    cout<< "t: " << t << "    dl: " << t.rozmiar() << endl;
    tab_bit u(45ull); // tablica 64-bitowa (sizeof(uint64_t)*8)
    cout<< "u: " << u << "    dl: " << u.rozmiar() << endl;
    tab_bit v(t); // tablica 46-bitowa (skopiowana z t)
    cout<< "v: " << v << "    dl: " << v.rozmiar() << endl;
    v[0] = 1; // ustawienie bitu 0-go bitu na 1
    cout<< "v: " << v << endl;
    t[45] = true; // ustawienie bitu 45-go bitu na 1
    cout<< "t: " << t << endl;
    bool b = v[1]; // odczytanie bitu 1-go
    cout<< "b: " << b << endl;
    u[45] = u[46] = u[63]; // przepisanie bitu 63-go do bitow 45-go i 46-go
    cout<< "u: " << u << endl;
    tab_bit w(tab_bit{1, 0, 1, 1, 0, 0, 0, 1}); // tablica 8-bitowa (przeniesiona)
    cout<< "w: " << w << "    dl: " << w.rozmiar() << endl;
}