#pragma once
#ifndef _kolor
#define _kolor
#include <iostream>
#include <string>
#include <fstream>

//*******************************************

class kolor
{
protected:
    int R;
    int G;
    int B;

public:
// konstruktory
    kolor();
    kolor(int r, int g, int b);

// gettery
    int getR() const;
    int getG() const;
    int getB() const;

// settery
    void setR(int r);
    void setG(int g);
    void setB(int b);

// rozjasnianie i przyciemnianie koloru
    void bright(); // za jednym razem zawsze o 10%
    void dark(); // ---//---

// laczenie koloru
    static kolor mix (const kolor A, const kolor B);

// strumienie
    friend std::ostream & operator<< (std::ostream &wy, const kolor &K);
};

//*******************************************

class kolortransparentny : public virtual kolor
{
protected:
    int alfa;

public:
    kolortransparentny();
    kolortransparentny(int r, int g, int b, int a);

    int getAlfa() const;
    void setAlfa(int a);

    friend std::ostream & operator << (std::ostream &wy, const kolortransparentny &K);
};

//*******************************************

class kolornazwany : public virtual kolor
{
protected:
    std::string name;

public:
    kolornazwany();
    kolornazwany(int r, int g, int b, std::string n);

    std::string getName() const;
    void setName(std::string n);

    friend std::ostream & operator << (std::ostream &wy, const kolornazwany &K);
};

//*******************************************

class kolornt : public kolortransparentny, public kolornazwany
{
public:
    kolornt();
    kolornt(int r, int g, int b, int a, std::string n);

    friend std::ostream & operator << (std::ostream &wy, const kolornt &K);
};

//*******************************************

#endif