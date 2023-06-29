#pragma once
#include <iostream>

//*******************************************

/** \class Door
 * \brief An abstract class of doors.
 ****************************************************************************************/
class Door
{
protected:

    /** \var string description
     * \brief The description of the door, might be useful to determine which key to use.
     ****************************************************************************************/
    std::string description;


    /** \var bool unlocked
     * \brief Holds state of the door [locked/unlocked].
     ****************************************************************************************/
    bool unlocked;

public:

    /** \fn virtual int use_me()
     * \brief Virtual function that checks if the player can use the door.
     ****************************************************************************************/
    virtual int use_me() = 0;


    /** \fn string get_description()
     * \brief Getter for description in class Door and its subclasses.
     ****************************************************************************************/
    std::string get_description() const noexcept { return description; }


    /** \fn void set_unlocked(bool u)
     * \brief Setter for unlocked in class Door and its subclasses.
     * \param u the new state of door [locked/unlocked]
     ****************************************************************************************/
    void set_unlocked(bool u) { unlocked = u; }
};
