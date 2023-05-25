#ifndef _OUT_
#define _OUT_
#include <iostream>
//*******************************************

inline std::ostream& comma(std::ostream& os)
{
    return os << ", ";
}

inline std::ostream& colon(std::ostream& os)
{
    return os << ": ";
}

class index
{
    int liczba, szerokosc;
    friend std::ostream& operator<<(std::ostream &os, const index &ig);

public:
    index(int x, int w)
        : liczba(x), szerokosc(w)
    {}
};

std::ostream& operator<<(std::ostream &os, const index &ind)
{
    int dlugosc_liczby = 0;
    int temp = ind.liczba;
    while (temp != 0)
    {
        dlugosc_liczby++;
        temp /= 10;
    }

    if (ind.liczba == 0)
        dlugosc_liczby = 1;

    int odstep = ind.szerokosc - dlugosc_liczby;
    os << "[";
    while (odstep > 0)
    {
        os << " ";
        odstep--;
    }

    return os << ind.liczba << "]";
}

//*******************************************
#endif
