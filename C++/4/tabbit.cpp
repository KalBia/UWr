#include <iostream>
#include <fstream>
#include "tabbit.hpp"
#include <algorithm>
#include <initializer_list>
#include <math.h>
#include <typeinfo>
using namespace std;

//*******************************************

tab_bit::myref::operator bool() const 
{ 
    return tb.czytaj(id); 
}

//*******************************************

tab_bit::myref& tab_bit::myref::operator=(bool b) 
{
    tb.pisz(id, b);
    return *this;
}

//*******************************************

tab_bit::myref& tab_bit::myref::operator=(const myref &r) 
{
    if (this == &r)
        return *this; 
    bool b = r.operator bool();
    tb.pisz(id, b);  
    return *this;
}

//*******************************************

tab_bit::tab_bit (int rozm)
    : dl(rozm)
{
    int nr_bajta = dl / 8;
    int nr_bita = dl % 8;
    tab = new slowo[(int)ceil(dl/8)+1]{};
}

//*******************************************

tab_bit::tab_bit (slowo tb)
    : dl(rozmiarSlowa)
{
    int roz_tab = ceil(dl/rozmiarSlowa)+1;
    tab = new slowo[roz_tab];
    tab[0] = tb;
}

//*******************************************

tab_bit::tab_bit (initializer_list<bool> lst)
{
    dl = lst.size();
    tab = new slowo[(int)ceil(dl/rozmiarSlowa)+1];
    int i = 0;
    for (auto x : lst)
    {
        pisz(i, x);
        i++;
    }
}

//*******************************************

tab_bit::tab_bit (const tab_bit& tb)
    : dl(tb.dl)
{
    int nr_bajta = dl / rozmiarSlowa;
    int nr_bita = dl % rozmiarSlowa;
    tab = new slowo[nr_bajta + 1];
    for (int i = 0; i < dl; i++)
        tab[i] = tb.tab[i];
}

//*******************************************

tab_bit::tab_bit(tab_bit &&tb) : tab_bit(1)
{
    swap(dl, tb.dl);
    swap(tab, tb.tab);
}

//*******************************************

tab_bit& tab_bit::operator=(const tab_bit& tb)
{
    if (this != &tb)
    {
        dl = tb.dl;
        delete[] tab;
        int rozm = (int)ceil(dl/rozmiarSlowa)+1;
        tab = new slowo[rozm];
        for (int i = 0; i < rozm; i++)
            pisz(i, tb.czytaj(i));
        }

    return *this;
}

//*******************************************

tab_bit& tab_bit::operator=(tab_bit &&tb)
{
    if (this != &tb)
    {
        swap(dl, tb.dl);
        swap(tab, tb.tab);
    }
    
    return *this;
}

//*******************************************

tab_bit::~tab_bit()
{
    delete[] tab;
    tab = nullptr;
}

//*******************************************

bool tab_bit::czytaj(int i) const
{
    if (i >= dl || i < 0)
        throw std::invalid_argument("Czytaj, Index out of range");

    int nr_bajta = i / rozmiarSlowa;
    int nr_bita = i % rozmiarSlowa;

    uint64_t x = (1ull << (uint64_t)nr_bita);
    bool res = tab[nr_bajta] & x;
    return res;
}

//*******************************************

void tab_bit::pisz(int i, bool b)
{
    if (i >= dl || i < 0)
    {
        cout<< "\ni: " << i << " dl: " << dl << endl;
        throw std::invalid_argument("Pisz, Index out of range: ");
    }

    int nr_bajta = i / rozmiarSlowa;
    int nr_bita = i % rozmiarSlowa;

    uint64_t x = (1ull << (uint64_t)nr_bita);
    bool res = tab[nr_bajta] & x;

    tab[i] = (bool)(res? res & b : res | b);
}

//*******************************************

bool tab_bit::operator[] (int i) const
{
    return czytaj(i);
}

//*******************************************

tab_bit::myref tab_bit::operator[] (int i)
{
    return myref(i, *this);
}

//*******************************************

int tab_bit::rozmiar () const
{
    return dl;
}

//*******************************************

istream & operator>> (istream &we, tab_bit &tb)
{
    string in;
    we >> in;

    int rozmiar = in.size();
    int rozm = (int)ceil(rozmiar/tab_bit::rozmiarSlowa)+1;
    delete[] tb.tab;
    tb.tab = new tab_bit::slowo[rozm];

    for (int i = 0; i < rozmiar; i++)
    {
        if (in[i] != '0' && in[i] != '1')
            throw invalid_argument("Not a bit");

        bool wartosc = (bool)(in[i] - '0');
        tb.pisz(i, wartosc);
    }

    return we;
}

//*******************************************

ostream & operator<<(ostream &wy, const tab_bit &tb)
{
    if (tb.rozmiar() == 0)
        wy << "empty";
    else
    {
        for (int i = 0; i < tb.rozmiar(); i++)
        {
            wy << tb.czytaj(i);
            if ((i+1) % 8 == 0)
            {
                wy << " ";
            }
        }
    }
    wy << endl;

    return wy;
}

//*******************************************

tab_bit operator| (tab_bit tb, tab_bit other)
{
    tab_bit res(1);
    if (tb.rozmiar() > other.rozmiar())
        res = tab_bit(tb);
    else
        res = tab_bit(other);

    for (int i = 0; i < min(tb.rozmiar(), other.rozmiar()); i++)
    {
        res[i] = tb[i] | other[i];
    }

    return res;
}

//*******************************************

tab_bit operator& (tab_bit tb, tab_bit other)
{
    tab_bit res(1);
    if (tb.rozmiar() > other.rozmiar())
        res = tab_bit(tb);
    else
        res = tab_bit(other);

    for (int i = 0; i < min(tb.rozmiar(), other.rozmiar()); i++)
    {
        res[i] = tb[i] & other[i];
    }

    return res;
}

//*******************************************

tab_bit operator^ (tab_bit tb, tab_bit other)
{
    tab_bit res = tab_bit(1);
    if (tb.rozmiar() > other.rozmiar())
        res = tab_bit(tb);
    else
        res = tab_bit(other);

    for (int i = 0; i < min(tb.rozmiar(), other.rozmiar()); i++)
    {
        res[i] = tb[i] ^ other[i];
    }

    return res;
}

//*******************************************

tab_bit operator! (tab_bit tb)
{
    tab_bit res = tab_bit(tb.rozmiar());
    for (int i = 0; i < tb.rozmiar(); i++)
    {
        res[i] = !tb[i];
    }

    return res;
}

//*******************************************

tab_bit tab_bit::operator|= (tab_bit other)
{
    for (int i = 0; i < min(this->rozmiar(), other.rozmiar()); i++)
    {
        if (czytaj(i) == 1 || other.czytaj(i) == 1)
            pisz(i, 1);
        pisz(1, 0);
    }

    return *this;
}

//*******************************************

tab_bit tab_bit::operator&= (tab_bit other)
{
    for (int i = 0; i < min(this->rozmiar(), other.rozmiar()); i++)
    {
        if (czytaj(i) == 1 && other.czytaj(i) == 1)
            pisz(i, 1);
        pisz(1, 0);
    }

    return *this;
}

//*******************************************

tab_bit tab_bit::operator^= (tab_bit other)
{
    for (int i = 0; i < min(this->rozmiar(), other.rozmiar()); i++)
    {
        if (czytaj(i) != other.czytaj(i))
            pisz(i, 1);
        pisz(1, 0);
    }

    return *this;
}