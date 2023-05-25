#pragma once
#include "list.hpp"
//*******************************************

namespace calc
{
    template<typename T>
    class stos : private lista<T>
    {
    public:
        stos() noexcept
            : lista<T>()
        {}

        stos(const stos<T> &other) noexcept
            : lista<T>(&other)
        {}

        stos(std::initializer_list<T> lst) noexcept
            : lista<T>(lst)
        {}

        using lista<T>::push_front;
        using lista<T>::get_front;
        using lista<T>::pop_front;

        using lista<T>::length;
        using lista<T>::is_empty;

        ~stos()
            : ~lista<T>()
        {}
    };
}
