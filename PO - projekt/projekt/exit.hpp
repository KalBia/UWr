#pragma once
#include "door_with_key.hpp"

//*******************************************

/** \class Exit
 * \brief The door to the End Area.
 * Using it ends the game.
 ****************************************************************************************/
class Exit : public Door
{
public:

    /** \fn Exit()
     * \brief A basic constructor, no parameters.
     ****************************************************************************************/
    Exit()
    {
        unlocked = false;
        description = "";
    }


    /** \fn Exit(string d)
     * \brief A constructor, basic parameters.
     * \param d the description of the door.
     ****************************************************************************************/
    Exit(std::string d)
    {
        unlocked = false;
        description = d;
    }

    //*******************************************

    /** \fn int use_me()
     * \brief Checks if the player fulfils all the terms to go to the next are.
     *
     * It overrides abstract function from class Door.
     * Returns
     * - 1 if the door is unlocked and the player wants to go to the next area
     * - (-1) if the door is locked and the player wants to unlock it
     * - 0 otherwise
     ****************************************************************************************/
    int use_me() override;
};
