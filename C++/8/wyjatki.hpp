#ifndef _WYJATKI
#define _WYJATKI
#include <stdexcept>

//*******************************************

class wyjatek_wymierny : public std::logic_error
{
public:
    explicit wyjatek_wymierny(const std::string& kom)
        : std::logic_error(kom)
    {};
};

class przekroczenie_zakresu : public wyjatek_wymierny
{
public:
    explicit przekroczenie_zakresu(const std::string& kom)
        : wyjatek_wymierny(kom)
    {};
};

class dzielenie_przez_0 : public wyjatek_wymierny
{
public:
    explicit dzielenie_przez_0(const std::string& kom)
        : wyjatek_wymierny(kom)
    {};
};

//*******************************************

#endif
