#pragma once
#include <iostream>

//*******************************************

/** \class Key
 * \brief Holds information about keys that can open doors in game.
 * They use unique id to match to the door.
 ****************************************************************************************/
class Key
{
protected:

    /** \var string name
     * \brief The short description.
     ****************************************************************************************/
    std::string name;


    /** \var string description
     * \brief The description of the key. Helps players to determine which door it opens.
     ****************************************************************************************/
    std::string description;


    /** \var int id
     * \brief Integer to identify the key for the game.
     ****************************************************************************************/
    int id;

public:

    /** \fn Key()
     * \brief A basic constructor, no parameters.
     ****************************************************************************************/
    Key() noexcept
        : name(""), description(""), id(0)
    {}


    /** \fn Key(string n, string d, int i)
     * \brief A constructor, basic parameters.
     ****************************************************************************************/
    Key(std::string n, std::string d, int i) noexcept
        : name(n), description(d), id(i)
    {}


    /** \fn string get_name()
     * \brief Getter for name in class Key.
     ****************************************************************************************/
    std::string get_name() const noexcept { return name; }


    /** \fn string description()
     * \brief Getter for description in class Key.
     ****************************************************************************************/
    std::string get_description() const noexcept { return description; }


    /** \fn int get_id()
     * \brief Getter for id in class Key.
     ****************************************************************************************/
    int get_id() const noexcept { return id; }
};
