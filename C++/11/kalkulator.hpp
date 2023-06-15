#pragma once
#include "operandy.hpp"
#include "operatory.hpp"
#include "funbin.hpp"
#include "funun.hpp"
#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <exception>
#include <map>

//*******************************************

namespace kalkulator
{
    static std::unordered_set<std::string> nazwy_zastrzezone;
    static std::map<std::string, int> func_match;
    static std::map<std::string, int> con_match;

    void prep_maps();
    void menedzer();
    bool parser(std::string, int, std::queue<symbol*>&);
    double evaluator(std::queue<symbol*>&);
    void sprzatacz();
    void opiekun(std::string, double);

    void func_parser(std::string, int, std::queue<symbol*>&);
    void con_parser(std::string, int, std::queue<symbol*>&);
    bool czy_liczba(std::string);
}
