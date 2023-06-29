#pragma once
#include "door.hpp"
#include <iostream>

//*******************************************

/** \class Door_Riddle
 * \brief The door that needs the answer to its riddle to open it. It compares players guess with answer.
 ****************************************************************************************/
class Door_Riddle : public Door
{
private:

    /** \var string riddle
     * \brief Holds the riddle that need to be answered in order to open the door.
     ****************************************************************************************/
    std::string riddle;


    /** \var solution
     * \brief Holds the correct answer to the riddle.
     ****************************************************************************************/
    std::string solution;


    /** \fn string lowercase_and_no_whitespace(string s)
     * \brief Deletes whitespaces (" ") and turns all letters to lowercase.
     ****************************************************************************************/
    std::string lowercase_and_no_whitespace(std::string s);

public:

    /** \fn Door_Riddle()
     * \brief A basic constructor, no parameters.
     ****************************************************************************************/
    Door_Riddle() noexcept
    {
        riddle = "";
        solution = "";
        description = "";
        unlocked = false;
    }


    /** \fn Door_Riddle(string d, string r, string s, bool u)
     * \brief A constructor with basic parameters.
     * \param d the description of the door
     * \param r the text of the riddle
     * \param s the answer to the riddle
     * \param u initial state of door (locked/unlocked)
     ****************************************************************************************/
    Door_Riddle(std::string d, std::string r, std::string s, bool u = false) noexcept
    {
        riddle = r;
        solution = s;
        description = d;
        unlocked = u;
    }


    /** \fn string get_riddle()
     * \brief Getter for riddle.
     ****************************************************************************************/
    std::string get_riddle() const noexcept { return riddle; }


    /** \fn bool check_answer_to_riddle(string answer)
     * \brief Compares given string with solution to riddle.
     ****************************************************************************************/
    bool check_answer_to_riddle(std::string answer);


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
