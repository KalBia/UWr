#include <iostream>
#include "piksel.hpp"

//*******************************************
// PIKSEL
//*******************************************

piksel::piksel()
    : x(0), y(0)
{}

//*******************************************

piksel::piksel(int _x, int _y)
{
    if (_x < 0 || _y < 0 || _x > screen_x || _y > screen_y)
        throw std::invalid_argument("Przynajmniej jedna z podanych wartosci jest poza zakresem.\n");

    x = _x; y = _y;
}

//*******************************************

int piksel::getx() const
{
    return x;
}

//*******************************************

int piksel::gety() const
{
    return y;
}

//*******************************************

void piksel::setx(int _x)
{
    if (_x < 0 || _x > screen_x)
        throw std::invalid_argument("Podana wartosc jest poza zakresem.\n");
    
    x = _x;
}

//*******************************************

void piksel::sety(int _y)
{
    if (_y < 0 || _y > screen_y)
        throw std::invalid_argument("Podana wartosc jest poza zakresem.\n");
    
    y = _y;
}

//*******************************************

int piksel::distLeft()
{
    return x;
}

//*******************************************

int piksel::distRight()
{
    return (screen_x - x);
}

//*******************************************

int piksel::distUp()
{
    return y;
}

//*******************************************

int piksel::distDown()
{
    return (screen_y - y);
}

//*******************************************

std::ostream & operator<<(std::ostream &wy, const piksel &P)
{
    wy<< "\nWSPOLRZEDNE PIKSELU:\n";
    wy<< "x: " << P.x << "  y: " << P.y << std::endl;

    return wy;
}

//*******************************************
// PIKSEL KOLOROWY
//*******************************************

pikselkolorowy::pikselkolorowy()
    : piksel(), KOLOR(kolortransparentny())
{}

//*******************************************

pikselkolorowy::pikselkolorowy(int _x, int _y, kolortransparentny k)
    : piksel(_x, _y), KOLOR(k)
{}

//*******************************************

kolortransparentny pikselkolorowy::getKolor() const
{
    return KOLOR;
}

//*******************************************

void pikselkolorowy::setKolor(kolortransparentny k)
{
    KOLOR = k;
}

//*******************************************

void pikselkolorowy::movePiksel(int moveX, int moveY)
{
    int newX = x + moveX;
    int newY = y + moveY;

    if (newX < 0 || newX > screen_x || newY < 0 || newY > screen_y)
        throw std::invalid_argument("Wektor przesunie piksel poza ekran.\n");
    
    x = newX;
    y = newY;
}

//*******************************************

std::ostream & operator<<(std::ostream &wy, const pikselkolorowy &P)
{
    wy<< "\nWSPOLRZEDNE PIKSELU I KOLOR:\n";
    wy<< "x: " << P.x << "  y: " << P.y << std::endl;
    wy<< "kolor: " << P.KOLOR;

    return wy;
}