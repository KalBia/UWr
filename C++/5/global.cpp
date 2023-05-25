#include <iostream>
#include "global.hpp"
#include <math.h>

//*******************************************

int odleglosc(const piksel &P, const piksel &Q)
{
    double resX = P.getx() - Q.getx();
    double resY = P.gety() - Q.gety();

    resX *= resX;
    resY *= resY;

    int result = round( sqrt( resX + resY ) );

    return result;
}