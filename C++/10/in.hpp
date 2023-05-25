#ifndef _IN_
#define _IN_
#include <iostream>
#include <string>
//*******************************************

inline std::istream& clearline(std::istream &is)
{
    std::string wynik;
    std::getline(is, wynik);

    return is;
}

class myignore
{
    int how_many;
    friend std::istream& operator>>(std::istream &is, const myignore &ig);

public:
    myignore(int x)
        : how_many(x)
    {}
};

std::istream& operator>>(std::istream &is, const myignore &ig)
{
    char znak;
    is.get(znak);
    znak = ' ';
    int x = ig.how_many;
    while (x > 0 && !is.eof() && znak != '\n')
    {
        is.get(znak);
        x--;
    }

    return is;
}

//*******************************************
#endif
