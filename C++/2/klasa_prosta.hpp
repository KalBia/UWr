#ifndef klasa_prosta
#define klasa_prosta
class punkt;
class odcinek;

//*******************************************

class prosta
{
private:
    double a;
    double b;

public:
    prosta(double x, double y);
    prosta& operator=(const prosta &other);

    double geta();
    double getb();
    void seta(double x);
    void setb(double x);

    prosta prosta_prostopadla_przez_punkt(punkt X);
    bool czy_po_tej_samej_stronie(punkt X, punkt Y);
};

//*******************************************

#endif