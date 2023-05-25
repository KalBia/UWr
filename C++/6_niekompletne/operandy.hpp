#ifndef _operandy
#define _operandy
#include <iostream>
#include "wyrazenie.hpp"
#include <vector>

//*******************************************

class liczba : public wyrazenie
{
    double value;

public: 
    double oblicz() override;
    std::string zapis() override;
};

//*******************************************

class zmienna : public wyrazenie
{
    std::string name;
    static std::vector< std::pair<std::string, double> > epickie_zmienne;

public: 
    double oblicz() override;
    std::string zapis() override;

    static void add_var(std::pair<std::string, double> v);
    static void delete_var(std::string v_name);
    static void modify_var(std::pair<std::string, double> v);
};

//*******************************************

class stala : public wyrazenie
{
    std::string name;
    double value;

public:
    double oblicz() override;
    std::string zapis() override;
};

//*******************************************

#endif