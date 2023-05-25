#include <stdio.h>
#include <algorithm>
#include "klasa_liczba.hpp"

//*******************************************

const int liczba::max_size_history = 3;

//*******************************************

liczba::liczba (double number) : // z zadaną wartością
    current_index(0), 
    real_size_history(1)
{
    history = new double[max_size_history];
    history[0] = number;
}

//*******************************************

liczba::liczba () : liczba(0) {}// bezparametrowy i delegatowy

//*******************************************

liczba::liczba (liczba &other) : // kopiujący
    current_index(other.current_index), 
    real_size_history(other.real_size_history)
{
    history = new double[max_size_history];
}

//*******************************************

liczba::liczba (liczba&& other) // przenoszący
{
// SWAP!
    current_index = other.current_index;
    real_size_history = other.real_size_history;
    history = other.history;

    other.current_index = 0;
    other.real_size_history = 0;
    other.history = nullptr;
}

//*******************************************

liczba& liczba::operator=(const liczba& other) // kopiujący
{    
    current_index = other.current_index;
    real_size_history = other.real_size_history;

    for (int i = 0; i < other.real_size_history; i++)
    {
        history[i] = other.history[i];
    }

    return *this;
}

//*******************************************

liczba& liczba::operator=(liczba&& other) //przenoszący
{
    if (this != &other)
    {
        delete[] history;
// lepszy jest SWAP!
        current_index = other.current_index;
        real_size_history = other.real_size_history;
        history = other.history;

        other.current_index = 0;
        other.real_size_history = 0;
        other.history = nullptr;
    }

    return *this;
}

//*******************************************

liczba::~liczba()
{
    if (history != nullptr)
        delete[] history;
}

//*******************************************

double liczba::getValue () // zwracanie bieżącej wartości liczby
{
    if (real_size_history == 0) return 0;
    return history[current_index];
}

//*******************************************

void liczba::setValue (double number) // ustawianie nowej wartości
{
    current_index = (current_index + 1) % max_size_history;
    history[current_index] = number;
    real_size_history = std::min(max_size_history, real_size_history + 1);
}

//*******************************************

void liczba::revertValue () // cofanie do poprzedniej wartości z historii
{
    if (real_size_history > 1) // wpp to jest nasza bieżąca wartość
    {
        current_index = (current_index + max_size_history - 1) % max_size_history;
        real_size_history -= 1;
    }
}