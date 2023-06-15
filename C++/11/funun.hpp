#pragma once
#include "symbol.hpp"
#include <cmath>

namespace kalkulator
{
    class unfun : public symbol
    {
    protected:
        virtual double op(double x) = 0;

    public:
        void eval(std::stack<double> &stos) override;
    };

    //*******************************************

    class abs : public unfun
    {
        double op(double x) override
        {return std::abs(x);}

    public:
        using unfun::eval;
    };

    //*******************************************

    class sgn : public unfun
    {
        double op(double x) override
        {return (x > 0) - (x < 0);}

    public:
        using unfun::eval;
    };

    //*******************************************

    class floor : public unfun
    {
        double op(double x) override
        {return std::floor(x);}

    public:
        using unfun::eval;
    };

    //*******************************************

    class ceil : public unfun
    {
        double op(double x) override
        {return std::ceil(x);}

    public:
        using unfun::eval;
    };

    //*******************************************

    class frac : public unfun
    {
        double op(double x) override
        {
            double temp;
            return std::modf(x, &temp);
        }

    public:
        using unfun::eval;
    };

    //*******************************************

    class sin : public unfun
    {
        double op(double x) override
        {return std::sin(x);}

    public:
        using unfun::eval;
    };

    //*******************************************

    class cos : public unfun
    {
        double op(double x) override
        {return std::cos(x);}

    public:
        using unfun::eval;
    };

    //*******************************************

    class atan : public unfun
    {
        double op(double x) override
        {return std::atan(x);}

    public:
        using unfun::eval;
    };

    //*******************************************

    class acot : public unfun
    {
        double op(double x) override
        {
            try
            {
                if (x == 0)
                    throw std::invalid_argument("+");
            }
            catch (std::invalid_argument e)
            {
                std::clog<< "ERROR: dzielenie przez zero\n";
                throw std::invalid_argument("+");
            }

            return std::atan(1/x);
        }

    public:
        using unfun::eval;
    };

    //*******************************************

    class ln : public unfun
    {

        double op(double x) override
        {
            try
            {
                if (x == 0)
                    throw std::invalid_argument("+");
            }
            catch (std::invalid_argument e)
            {
                std::clog<< "ERROR: dzielenie przez zero\n";
                throw std::invalid_argument("+");
            }

            return std::log(x);
        }

    public:
        using unfun::eval;
    };

    //*******************************************

    class exp : public unfun
    {
        double op(double x) override
        {return std::exp(x);}

    public:
        using unfun::eval;
    };
}
