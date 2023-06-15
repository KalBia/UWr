#pragma once
#include "symbol.hpp"
#include <map>

namespace kalkulator
{
    class liczba : public symbol
    {
        double wartosc;

    public:
        liczba()
            : wartosc(0.0) {}

        liczba(double w)
            : wartosc(w) {}

        void eval(std::stack<double> &stos) override;
    };

    //*******************************************

    class zmienna : public symbol
    {
        std::string nazwa;
        double wartosc;

    public:
        static std::map<std::string, double> spis_zmiennych;

        zmienna()
            : nazwa("x"), wartosc(0.0) {}

        zmienna(std::string n, double w)
            : nazwa(n), wartosc(w) {}

        std::string getnazwa() const {return nazwa;}
        double getwartosc() const {return wartosc;}

        void eval(std::stack<double> &stos) override;
    };

    //*******************************************

    class stala : public symbol
    {
        double wartosc;

    public:
        void eval(std::stack<double> &stos) override;
    };

    //*******************************************

    class e : public stala
    {
        double wartosc = 2.718281828459;

    public:
        using stala::eval;
    };

    //*******************************************

    class pi : public stala
    {
        double wartosc = 3.141592653589;

    public:
        using stala::eval;
    };

    //*******************************************

    class fi : public stala
    {
        double wartosc = 1.618033988750;

    public:
        using stala::eval;
    };
}
