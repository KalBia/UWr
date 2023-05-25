#pragma once
#ifndef tabbit
#define tabbit

#include <iostream>
#include <fstream>
#include <initializer_list>
using namespace std;

//*******************************************

class tab_bit
{
    typedef uint64_t slowo; // komorka w tablicy
    static const int rozmiarSlowa = 64; // rozmiar slowa w bitach
    friend istream & operator >> (istream &we, tab_bit &tb);
    friend ostream & operator << (ostream &wy, const tab_bit &tb);
    class myref // klasa pomocnicza do adresowania bitów
    {
        friend class tab_bit;
        tab_bit &tb;
        int id;
    public:
        myref(int i, tab_bit &t) : tb(t), id(i) {};
        operator bool() const;
        myref &operator=(bool b);
        myref &operator=(const myref &r);
    };

public:
    int dl; // liczba bitów
    slowo *tab; // tablica bitów

public:
    explicit tab_bit (int rozm); // wyzerowana tablica bitow [0...rozm]
    explicit tab_bit (slowo tb); // tablica bitów [0...rozmiarSlowa]
    explicit tab_bit (initializer_list<bool> lst);
    tab_bit (const tab_bit &tb); // konstruktor kopiujący
    explicit tab_bit (tab_bit &&tb); // konstruktor przenoszący
    tab_bit & operator = (const tab_bit &tb); // przypisanie kopiujące
    tab_bit & operator = (tab_bit &&tb); // przypisanie przenoszące
    ~tab_bit (); // destruktor


    bool czytaj (int i) const; // metoda pomocnicza do odczytu bitu
    void pisz (int i, bool b); // metoda pomocnicza do zapisu bitu

public:
    bool operator[] (int i) const; // indeksowanie dla stałych tablic bitowych
    myref operator[] (int i); // indeksowanie dla zwykłych tablic bitowych
    int rozmiar () const; // rozmiar tablicy w bitach

public:
    // operatory bitowe: | i |=, & i &=, ^ i ^= oraz !
    friend tab_bit operator| (tab_bit tb, tab_bit other);
    friend tab_bit operator& (tab_bit tb, tab_bit other);
    friend tab_bit operator^ (tab_bit tb, tab_bit other);
    friend tab_bit operator! (tab_bit tb);

    tab_bit operator|= (tab_bit other);
    tab_bit operator&= (tab_bit other);
    tab_bit operator^= (tab_bit other);
};

//*******************************************
#endif