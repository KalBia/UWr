#pragma once
#include "door.hpp"
#include "key.hpp"

//*******************************************

/** \class Door_Key
 * \brief The door that needs a key to open it. It checks the key_id to determine that.
 ****************************************************************************************/
class Door_Key : public Door
{
private:

    /** \var int key_id
     * \brief Holds integer representing unique key_id.
     ****************************************************************************************/
    int key_id;

public:

    /** \fn Door_Key()
     * \brief A basic constructor, no parameters.
     ****************************************************************************************/
    Door_Key() noexcept
    {
        key_id = 0;
        description = "";
        unlocked = false;
    }


    /** \fn Door_Key(int k_i, string d, bool u = false)
     * \brief A constructor, basic parameters.
     * \param k_i the key_id needed to open the door
     * \param d the description of the door
     * \param u information if the door is initially locked/unlocked
     ****************************************************************************************/
    Door_Key(int k_i, std::string d, bool u = false) noexcept
    {
        key_id = k_i;
        description = d;
        unlocked = u;
    }


    /** \fn int use_me()
     * \brief Checks if the player fulfils all the terms to go to the next are.
     *
     * It overrides abstract function from class Door.
     * Returns
     * - 1 if the door was already unlocked
     * - key_id if the player wants to go to the next area
     * - 0 otherwise
     ****************************************************************************************/
    int use_me() override;
};
