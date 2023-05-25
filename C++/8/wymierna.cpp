#include <iostream>
#include "wymierna.hpp"
#include "wyjatki.hpp"
#include <vector>
#include <map>

//*******************************************

bool obliczenia::mult_overflow(int a, int b) noexcept
{
    if (a < 0 && b < 0 && (a * b < 0 || a < a * b || b < a * b))
        return true;
    if (a > 0 && b > 0 && (a * b < 0 || a > a * b || b > a * b))
        return true;
    if (a < 0 && b > 0 && a * b > 0)
        return true;
    if (a > 0 && b < 0 && a * b > 0)
        return true;

    return false;
}

bool obliczenia::add_overflow(int a, int b) noexcept
{
    if (a < 0 && b < 0 && a + b > 0)
        return true;
    if (a > 0 && b > 0 && a + b < 0)
        return true;

    return false;
}

//*******************************************

int obliczenia::NWD(int a, int b) noexcept
{
    a = abs(a);
    b = abs(b);

    if (b != 0)
        return NWD(b, a % b);
    return a;
}

int obliczenia::NWW(int a, int b)
{
    int nww;

    try
    {
        int nwd = NWD(a, b);
        nww = (a / nwd) * b;

        if (mult_overflow(a, b))
            throw przekroczenie_zakresu("NWW: overflow");
    }
    catch (przekroczenie_zakresu e)
    {
        std::cerr << e.what() << '\n';
        nww = 1;
    }

    return nww;
}

//*******************************************

void obliczenia::wymierna::uprosc() noexcept
{
    int nwd = NWD(licz, mian);
    licz /= nwd;
    mian /= nwd;

    if (mian < 0)
    {
        licz *= -1;
        mian *= -1;
    }
}

//*******************************************

obliczenia::wymierna::wymierna() noexcept
    : licz(0), mian(1)
{}

obliczenia::wymierna::wymierna(int l, int m)
{
    try
    {
        if (m == 0)
            throw dzielenie_przez_0("konstruktor-wymierna: mianownik jest zerem");

        licz = l;
        mian = m;
        uprosc();
    }
    catch (dzielenie_przez_0 e)
    {
        std::cerr << e.what() << '\n';
    }
}

obliczenia::wymierna::wymierna(int l)
    : wymierna(l, 1)
{}

//*******************************************

int obliczenia::wymierna::get_licz() const noexcept
{
    return licz;
}

int obliczenia::wymierna::get_mian() const noexcept
{
    return mian;
}

//*******************************************

obliczenia::wymierna obliczenia::operator+(const wymierna &w, const wymierna &v)
{
    int nww;
    int add_w;
    int add_v;

    try
    {
        nww = NWW(w.mian, v.mian);
        int changew = nww / w.mian;
        int changev = nww / v.mian;

        if (mult_overflow(w.licz, changew))
            throw przekroczenie_zakresu("rozszerzanie ulamka - overflow");

        if (mult_overflow(v.licz, changev))
            throw przekroczenie_zakresu("rozszerzania ulamka - overflow");

        add_w = w.licz*changew;
        add_v = v.licz*changev;

        if (add_overflow(add_w, add_v))
            throw przekroczenie_zakresu("dodawanie/odejmowanie - overflow");
    }
    catch (przekroczenie_zakresu e)
    {
        std::cerr << e.what() << '\n';
        return w;
    }

    return wymierna(add_w + add_v, nww);
}

obliczenia::wymierna obliczenia::operator-(const wymierna &w, const wymierna &v)
{
    wymierna temp_v;

    try
    {
        temp_v = -v;

        if (v.licz == temp_v.licz)
            throw przekroczenie_zakresu("odejmowanie - przekroczenie zakresu");
    }
    catch (przekroczenie_zakresu e)
    {
        std::cerr << e.what() << '\n';
        return w;
    }

    return (w + temp_v);
}

obliczenia::wymierna obliczenia::operator*(const wymierna &w, const wymierna &v)
{
    try
    {
        if (mult_overflow(w.licz, v.licz))
            throw przekroczenie_zakresu("mnozenie/dzielenie - overflow");

        if (mult_overflow(w.mian, v.mian))
            throw przekroczenie_zakresu("mnozenie/dzielenie - overflow");
    }
    catch(przekroczenie_zakresu e)
    {
        std::cerr << e.what() << '\n';
        return w;
    }

    return wymierna(w.licz*v.licz, w.mian*v.mian);
}

obliczenia::wymierna obliczenia::operator/(const wymierna &w, const wymierna &v)
{
    try
    {
        if (v.licz == 0)
            throw dzielenie_przez_0("dzielenie: dzielenie przez zero");
    }
    catch (dzielenie_przez_0 e)
    {
        std::cerr << e.what() << '\n';
        return w;
    }

    wymierna temp = wymierna(v.mian, v.licz);
    return (w * temp);
}

//*******************************************

obliczenia::wymierna obliczenia::operator-(const wymierna &w)
{
    int temp_licz_w;

    try
    {
        temp_licz_w = (-1) * w.licz;

        if (temp_licz_w == w.licz)
            throw przekroczenie_zakresu("unarny minus - overflow");
    }
    catch (przekroczenie_zakresu e)
    {
        std::cerr << e.what() << '\n';
        return w;
    }

    return wymierna(temp_licz_w, w.mian);
}

obliczenia::wymierna obliczenia::operator!(const wymierna &w)
{
    wymierna result;

    try
    {
        if (w.licz == 0)
            throw dzielenie_przez_0("odwrotnosc - licznik jest rowny zero");

        result = wymierna(w.mian, w.licz);
        result.uprosc();
    }
    catch (dzielenie_przez_0 e)
    {
        std::cerr << e.what() << '\n';
        return w;
    }

    return result;
}

//*******************************************

obliczenia::wymierna::operator double()
{
    return (double) licz / mian;
}

obliczenia::wymierna::operator int()
{
    if (licz < mian /2)
        return (int) licz / mian;
    return ((int)licz / mian) + 1;
}

//*******************************************

std::ostream& obliczenia::operator<<(std::ostream &wyj, const wymierna &w)
{
    int l = w.licz;
    int m = w.mian;
    bool ujemna = false;

    if (l < 0)
    {
        ujemna = true;
        l *= (-1);
    }

    int pre_dot = l / m;
    l -= pre_dot * m;
    l *= 10;

    std::vector<int> post_dot;
    std::map<int, int> powtorka;
    bool okres_found = false;
    bool czy_okresowa = true;
    bool check = false;
    int index = 0;
    while (!okres_found)
    {
        if (l == 0)
        {
            czy_okresowa = false;
            okres_found = true;
            index = post_dot.size();
        }
        else if (powtorka.count(l) > 0)
        {
            index = powtorka.at(l);
            okres_found = true;
        }
        else
        {
            powtorka.insert({l, index});
        }

        int liczba = l / m;
        l -= liczba * m;
        l *= 10;

        post_dot.push_back(liczba);
        ++index;
    }
    index--;

    if (ujemna)
        wyj<< "-";

    wyj<< pre_dot;

    if ( !(post_dot.size() == 1 && post_dot[0] == 0) )
    {
        wyj<< ".";
        int i = 0;
        while (i < index)
        {
            wyj<< post_dot[i];
            i++;
        }

        if (czy_okresowa)
        {
            wyj<< "(";
            while (i < post_dot.size()-1)
            {
                wyj<< post_dot[i];
                i++;
            }
            wyj<< ")";
        }
    }

    return wyj;
}
