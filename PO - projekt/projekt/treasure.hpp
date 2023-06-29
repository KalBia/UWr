#pragma once
#include "key.hpp"

//*******************************************

/** \class Treasure
 * \brief The key to the Exit door.
 * It can have multiple parts. The player needs to collect them all in order to open the Exit.
 ****************************************************************************************/
class Treasure : public Key
{
private:

    /** \var int parts
     * \brief Holds the number of parts of treasure to collect.
     ****************************************************************************************/
    int parts;

public:

    /** \fn Treasure()
     * \brief A basic constructor, no parameters.
     ****************************************************************************************/
    Treasure() noexcept
        : parts(1), Key()
    {}


    /** \fn Treasure(int p, string n, string d, int i)
     * \brief A constructor, basic parameters.
     * \param p the number of parts
     * \param n the name of the key, like short description
     * \param d the descripion of the key, may be usefull to determine which door it opens
     * \param i the key_id of the treasure
     ****************************************************************************************/
    Treasure(int p, std::string n, std::string d, int i) noexcept
        : parts(p), Key(n, d, i)
    {}


    /** \fn int get_parts()
     * \brief Getter for parts in class Treasure.
     ****************************************************************************************/
    int get_parts() const noexcept { return parts; }
};
