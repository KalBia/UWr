#pragma once
#ifndef _piksel
#define _piksel
#include <iostream>
#include <fstream>
#include "kolor.hpp"

//*******************************************

class piksel
{
protected:
    int x;
    int y;
    static const int screen_x = 1920;
    static const int screen_y = 1080;

public:
    piksel();
    piksel(int _x, int _y);

    int getx() const;
    int gety() const;

    void setx(int _x);
    void sety(int _y);

// lewy gorny piksel ma wspolrzedne (0 , 0)
    int distLeft();
    int distRight();
    int distUp();
    int distDown(); 

    friend std::ostream & operator << (std::ostream &wy, const piksel &P);
};

//*******************************************

class pikselkolorowy : public piksel
{
protected:
    kolortransparentny KOLOR;

public:
    pikselkolorowy();
    pikselkolorowy(int _x, int _y, kolortransparentny k);

    kolortransparentny getKolor() const;
    void setKolor(kolortransparentny k);

    void movePiksel(int moveX, int moveY);

    friend std::ostream & operator << (std::ostream &wy, const pikselkolorowy &P);
};

//*******************************************

#endif