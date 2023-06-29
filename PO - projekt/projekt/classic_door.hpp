#pragma once
#include "door.hpp"

//*******************************************

/** \class Door_Classic
 * \brief Door that is always unlocked (or always locked).
 ****************************************************************************************/
class Door_Classic : public Door
{
public:

    /** \fn Door_Classic()
     * \brief A basic construtor, no parameters.
     ****************************************************************************************/
    Door_Classic()
    {
        description = "";
        unlocked = true;
    }


    /** \fn Door_Classic(string d, bool u = true)
     * \brief A constructor with parameters.
     * \param d the description of the door
     * \param u the state of door - unlocked/locked
     ****************************************************************************************/
    Door_Classic(std::string d, bool u = true)
    {
        description = d;
        unlocked = u;
    }


    /** \fn int use_me()
     * \brief Checks if the player fulfils all the terms to go to the next are.
     *
     * It overrides abstract function from class Door.
     * Returns
     * - 1 if the player fulfils all the terms to go to the next area
     * - 0 otherwise
     ****************************************************************************************/
    int use_me() override;
};
