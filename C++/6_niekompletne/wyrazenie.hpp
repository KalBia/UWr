#ifndef _wyrazenie
#define _wyrazenie
#include <iostream>

//*******************************************

class wyrazenie
{
public:
    virtual double oblicz() = 0;
    virtual std::string zapis() = 0;
};

//*******************************************

#endif