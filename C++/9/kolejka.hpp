#pragma once
#include "list.hpp"
//*******************************************

namespace calc
{
    template<typename T>
    class kolejka : private lista<T>
    {
    public:
        kolejka() noexcept
            : lista<T>()
        {}

        kolejka(const kolejka<T> &other) noexcept
            : lista<T>(&other)
        {}

        kolejka(std::initializer_list<T> lst) noexcept
            : lista<T>(lst)
        {}

        using lista<T>::push_back;
        using lista<T>::get_front;
        using lista<T>::pop_front;

        using lista<T>::length;
        using lista<T>::is_empty;

        ~kolejka()
            : ~lista<T>()
        {}

    };
}
