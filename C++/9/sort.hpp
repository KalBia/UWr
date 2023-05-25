#pragma once
#include "list.hpp"
//*******************************************

namespace calc
{
    template<typename T>
    class less_eq
    {
    public:
        static bool lq(const T &l, const T &r)
        {
            return l <= r;
        }
    };

    template<typename T>
    class less_eq<T*>
    {
    public:
        static bool lq(const T &l, const T &r)
        {
            return *l <= *r;
        }
    };

    template<typename T>
    class great_eq
    {
    public:
        static bool ge(const T &l, const T &r)
        {
            return l >= r;
        }
    };

    template<typename T>
    class great_eq<T*>
    {
    public:
        static bool lq(const T &l, const T &r)
        {
            return *l >= *r;
        }
    };

    //*******************************************

    template<typename T, typename C = less_eq<T>>
    bool issorted(const lista<T>& L)
    {
        if (L.length() < 2)
            return true;

        for (int i = 1; i < L.length(); i++)
        {
            if (!(C::lq(L.get_elem(i-1), L.get_elem(i))))
                return false;
        }

        return true;
    }

    //*******************************************

    template<typename T, typename C = less_eq<T>>
    void sort(lista<T>& L)
    {
        if (L.length() < 2)
            return;

        bool sorted = false;
        int i = 1;
        while(!sorted)
        {
            bool change = false;
            if (!(C::lq(L.get_elem(i-1), L.get_elem(i))))
            {
                T one = L.get_elem(i-1);
                T two = L.get_elem(i);

                L.pop_position(i-1);
                L.pop_position(i-1);

                L.insert(two, i-1);
                L.insert(one, i);

                change = true;
            }

            if (change)
            {
                i = 1;
            }
            else
            {
                i++;

                if (i == L.length())
                    sorted = true;
            }
        }
    }
}
