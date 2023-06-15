#pragma once
#include <iostream>
#include <initializer_list>
#include <cmath>

//*******************************************

class trojkat
{
private:
    double bok1, bok2, bok3;
    std::string nazwa;

public:
    // konstruktory
    trojkat() : bok1(1), bok2(1), bok3(1), nazwa("ABC") {}
    trojkat(std::initializer_list<double> lst, std::string n="ABC");

    // kopiowalnosc
    trojkat(const trojkat &other) noexcept;
    trojkat& operator=(const trojkat &other) noexcept;

    // gettery
    double getbok1() const noexcept { return bok1; }
    double getbok2() const noexcept { return bok2; }
    double getbok3() const noexcept { return bok3; }
    std::string getnazwa() const noexcept { return nazwa; }

    // obliczenia
    double obwod() const;
    double pole() const;

    //wypisywanie
    friend std::ostream& operator<<(std::ostream& os, const trojkat& T);
};

std::ostream& operator<<(std::ostream& os, const trojkat& T);
