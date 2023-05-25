#pragma once
#ifndef klasa_liczba
#define klasa_liczba

//*******************************************

class liczba
{
private:
    static const int max_size_history;
    double *history;
    int current_index;
    int real_size_history;

public:
    liczba (double number); // z zadaną wartością
    liczba (); // bezparametrowy i delegatowy
    liczba (liczba &other); // kopiujący
    liczba (liczba&& other); // przenoszący

    liczba& operator=(const liczba& other); // kopiujący
    liczba& operator=(liczba&& other); //przenoszący

    ~liczba();

    double getValue (); // zwracanie bieżącej wartości liczby
    void setValue (double number); // ustawianie nowej wartości
    void revertValue (); // cofanie do poprzedniej wartości z historii

};

//*******************************************

#endif