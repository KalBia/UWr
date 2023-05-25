#ifndef klasa_wektor
#define klasa_wektor

//*******************************************

class wektor
{
private:
    double x;
    double y;

public:
    wektor(double a, double b);

    double getx();
    double gety();
    void setx(double a);
    void sety(double a);
};

//*******************************************

#endif