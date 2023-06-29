#pragma once
#include <string>

//*******************************************

/** \class Sculpture
 * \brief Holds information about sculptures in the game.
 * Can be used as a hint to riddle, but it can be a red herring as well.
 ****************************************************************************************/
class Sculpture
{
private:

    /** string description
     * \brief Holds the description of the sculpture.
     * May have hints to riddles [single or more].
     ****************************************************************************************/
    std::string description;

public:

    /** \fn Sculpture()
     * \brief A basic constructor, no parameters.
     ****************************************************************************************/
    Sculpture() noexcept
        : description("")
    {}


    /** \fn Sculpture(string d)
     * \brief A constructor, basic parameters.
     ****************************************************************************************/
    Sculpture(std::string d) noexcept
        : description(d)
    {}


    /** \fn string get_description()
     * \brief Getter for description in class Sculpture.
     ****************************************************************************************/
    std::string get_description() const noexcept { return description; }
};
