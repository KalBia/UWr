#include <iostream>
#include "kolor.hpp"

//*******************************************
// KOLOR
//*******************************************

kolor::kolor()
    : R(0), G(0), B(0)
{}

//*******************************************

kolor::kolor(int r, int g, int b)
{
    if (r > 255 || g > 255 || b > 255 | r < 0 || g < 0 || b < 0)
        throw std::invalid_argument("Przynajmniej jedna z podanych wartosci jest poza zakresem.\n");
    
    R = r; G = g; B = b;
}

//*******************************************

int kolor::getR() const
{
    return R;
}

//*******************************************

int kolor::getG() const
{
    return G;
}

//*******************************************

int kolor::getB() const
{
    return B;
}

//*******************************************

void kolor::setR(int r)
{
    if (r < 0 || r > 255)
        throw std::invalid_argument("Podana wartosc jest poza zakresem.\n");

    R = r;
}

//*******************************************

void kolor::setG(int g)
{
    if (g < 0 || g > 255)
        throw std::invalid_argument("Podana wartosc jest poza zakresem.\n");

    G = g;
}

//*******************************************

void kolor::setB(int b)
{
    if (b < 0 || b > 255)
        throw std::invalid_argument("Podana wartosc jest poza zakresem.\n");

    B = b;
}

//*******************************************

void kolor::bright()
{
    int Rchange = (255 - R) * 0.1;
    int Gchange = (255 - G) * 0.1;
    int Bchange = (255 - B) * 0.1;

    if (Rchange == 0)
        R = 255;
    if (Gchange == 0)
        G = 255;
    if (Bchange == 0)
        B = 255;
    
    R += Rchange; G += Gchange; B += Bchange;
}

//*******************************************

void kolor::dark()
{
    int Rchange = R * 0.1;
    int Gchange = G * 0.1;
    int Bchange = B * 0.1;

    if (Rchange == 0)
        R = 0;
    if (Gchange == 0)
        G = 0;
    if (Bchange == 0)
        B = 0;
    
    R -= Rchange; G -= Gchange; B -= Bchange;
}

//*******************************************

kolor kolor::mix(const kolor A, const kolor B)
{
    int newR = (A.R + B.R) / 2;
    int newG = (A.G + B.G) / 2;
    int newB = (A.B + B.B) / 2;

    return kolor(newR, newG, newB);
}

//*******************************************

std::ostream & operator<<(std::ostream &wy, const kolor &K)
{
    wy<< "\nWARTOSCI RGB KOLORU:\n";
    wy<< "R: " << K.R << "  G: " << K.G << "  B: " << K.B << std::endl;

    return wy;
}

//*******************************************
// KOLOR TRANSPARENTNY
//*******************************************

kolortransparentny::kolortransparentny()
    : kolor(), alfa(0)
{}

//*******************************************

kolortransparentny::kolortransparentny(int r, int g, int b, int a)
    : kolor(r, g, b)
{
    if (a < 0 || a > 255)
        throw std::invalid_argument("Przynajmniej jedna z podanych zmiennych jest poza zakresem.\n");

    alfa = a;
}

//*******************************************

int kolortransparentny::getAlfa() const
{
    return alfa;
}

//*******************************************

void kolortransparentny::setAlfa(int a)
{
    if (a < 0 || a > 255)
        throw std::invalid_argument("Podana wartosc jest poza zakresem.\n");
    
    alfa = a;
}

//*******************************************

std::ostream & operator<<(std::ostream &wy, const kolortransparentny &K)
{
    wy<< "\nWARTOSCI RGB I ALFA KOLORU:\n";
    wy<< "R: " << K.R << "  G: " << K.G << "  B: " << K.B << std::endl;
    wy<< "alfa: " << K.alfa << std::endl;

    return wy;
}

//*******************************************
// KOLOR NAZWANY
//*******************************************

kolornazwany::kolornazwany()
    : kolor(), name("")
{}

//*******************************************

kolornazwany::kolornazwany(int r, int g, int b, std::string n)
    : kolor(r, g, b)
{
    for (char x : n)
    {
        if (x > 'z' || x < 'a')
            throw std::invalid_argument("Nazwa musi sie skladac jedynie z malych liter alfabetu.\n");
    }

    name = n;
}

//*******************************************

std::string kolornazwany::getName() const
{
    return name;
}

//*******************************************

void kolornazwany::setName(std::string n)
{
    for (char x : n)
    {
        if (x > 'z' || x < 'a')
            throw std::invalid_argument("Nazwa musi sie skladac jedynie z malych liter alfabetu.\n");
    }

    name = n;
}

//*******************************************

std::ostream & operator<<(std::ostream &wy, const kolornazwany &K)
{
    wy<< "\nWARTOSCI RGB I ALFA KOLORU:\n";
    wy<< "R: " << K.R << "  G: " << K.G << "  B: " << K.B << std::endl;
    wy<< "name: " << K.name << std::endl;

    return wy;
}

//*******************************************
// KOLOR NT
//*******************************************

kolornt::kolornt()
    : kolor()
{
    alfa = 0;
    name = "";
}

//*******************************************

kolornt::kolornt(int r, int g, int b, int a, std::string n)
    : kolor(r, g, b), kolornazwany(r, g, b, n), kolortransparentny(r, g, b, a)
{}

//*******************************************

std::ostream & operator<<(std::ostream &wy, const kolornt &K)
{
    wy<< "\nWARTOSCI RGB I ALFA KOLORU:\n";
    wy<< "R: " << K.R << "  G: " << K.G << "  B: " << K.B << std::endl;
    wy<< "alfa: " << K.alfa << std::endl;
    wy<< "name: " << K.name << std::endl;

    return wy;
}

//*******************************************