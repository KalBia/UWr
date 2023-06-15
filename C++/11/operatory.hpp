#pragma once
#include "symbol.hpp"

namespace kalkulator
{
    class operatory : public symbol
    {
    protected:
        virtual double op(double a, double b) = 0;

    public:
        void eval(std::stack<double> &stos) override;
    };

    //*******************************************

    class dodawanie : public operatory
    {
        double op(double a, double b) override
        {return a + b;}

    public:
        using operatory::eval;
    };

    //*******************************************

    class odejmowanie : public operatory
    {
        double op(double a, double b) override
        {return b - a;}

    public:
        using operatory::eval;
    };

    //*******************************************

    class mnozenie : public operatory
    {
        double op(double a, double b) override
        {return a * b;}

    public:
        using operatory::eval;
    };

    //*******************************************

    class dzielenie : public operatory
    {
        double op(double a, double b) override
        {
            try
            {
                if (a == 0)
                    throw std::invalid_argument("+");
            }
            catch (std::invalid_argument e)
            {
                std::clog<< "ERROR: dzielenie przez 0\n";
                throw std::invalid_argument("+");
            }

            return b / a;
        }

    public:
        using operatory::eval;
    };
}
