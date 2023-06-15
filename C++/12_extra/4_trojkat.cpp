#include "4_trojkat.hpp"

//*******************************************

trojkat::trojkat(std::initializer_list<double> lst, std::string n)
{
    if (lst.size() != 3)
        throw std::invalid_argument("za malo argumentow");

    auto it = lst.begin();
    bok1 = *it++;
    bok2 = *it++;
    bok3 = *it;

    if ((bok1 + bok2) <= bok3 || (bok1 + bok3) <= bok2 || (bok2 + bok3) <= bok1)
        throw std::invalid_argument("argumenty nie spelniaja warunku trojkata");

    nazwa = n;
}

//*******************************************

trojkat::trojkat(const trojkat &other) noexcept
    : bok1(other.bok1), bok2(other.bok2), bok3(other.bok3), nazwa(other.nazwa)
{}

//*******************************************

trojkat& trojkat::operator=(const trojkat &other) noexcept
{
    if (this != &other)
    {
        bok1 = other.bok1;
        bok2 = other.bok2;
        bok3 = other.bok3;
        nazwa = other.nazwa;
    }

    return *this;
}

//*******************************************

double trojkat::obwod() const
{
    return bok1 + bok2 + bok3;
}

//*******************************************

double trojkat::pole() const
{
    double p = obwod() / 2;
    return std::sqrt( p*(p-bok1)*(p-bok2)*(p-bok3) );
}

//*******************************************

std::ostream& operator<<(std::ostream& os, const trojkat& T)
{
    os<< "Trojkat: " << T.nazwa << "\n";
    os<< "Boki: " << T.bok1 << " " << T.bok2 << " " << T.bok3 << "\n";
    return os;
}
