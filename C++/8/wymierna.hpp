#ifndef _WYMIERNA
#define _WYMIERNA
#include <iostream>
#include "wyjatki.hpp"

//*******************************************

namespace obliczenia
{
    int NWD(int, int) noexcept;
    int NWW(int, int);
    bool mult_overflow(int, int) noexcept;
    bool add_overflow(int, int) noexcept;

    class wymierna
    {

        int licz, mian;

    public:
        wymierna() noexcept;
        wymierna(int l, int m);
        wymierna(int l);
        int get_licz() const noexcept;
        int get_mian() const noexcept;
        void uprosc() noexcept;

    public:
        explicit operator double();
        explicit operator int();

        friend std::ostream& operator<< (std::ostream &wyj, const wymierna &w);

        friend wymierna operator+(const wymierna& w, const wymierna& v);
        friend wymierna operator-(const wymierna& w, const wymierna& v);
        friend wymierna operator*(const wymierna& w, const wymierna& v);
        friend wymierna operator/(const wymierna& w, const wymierna& v);

        friend wymierna operator-(const wymierna& w);
        friend wymierna operator!(const wymierna& v);
    };

    std::ostream& operator<< (std::ostream&, const wymierna&);

    wymierna operator+(const wymierna&, const wymierna&);
    wymierna operator-(const wymierna&, const wymierna&);
    wymierna operator*(const wymierna&, const wymierna&);
    wymierna operator/(const wymierna&, const wymierna&);

    wymierna operator-(const wymierna&);
    wymierna operator!(const wymierna&);
}

//*******************************************

#endif
