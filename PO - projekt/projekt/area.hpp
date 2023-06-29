#pragma once
#include <iostream>
#include <vector>
#include <initializer_list>
#include "sculpture.hpp"
#include "door.hpp"
#include "door_with_key.hpp"
#include "door_with_riddle.hpp"
#include "key.hpp"
#include "inventory.hpp"

//*******************************************

/** \class Area
 * \brief aka rooms, map parts, locations. Holds items, next areas, doors, sculptures.
 ****************************************************************************************/
class Area
{
private:
    friend class Game;

    /** \var vector<Door*> doors, vector<Area*> areas
    * \brief Store information about possible next destinations from current area.
    *
    * They are always modified together - they act like it was vector of pair<door, area>.
    ****************************************************************************************/
    std::vector<Door*> doors;
    std::vector<Area*> areas;


    /** \var vector<Key*> items
    * \brief Store information about items present in the current area.
    ****************************************************************************************/
    std::vector<Key*> items;


    /** \var Sculpture* scul
    * \brief Have value = nullptr if there is no sculpture in the current area.
    ****************************************************************************************/
    Sculpture* scul;


    /** \var string description
    * \brief It builds story, not essential for gameplay.
    ****************************************************************************************/
    std::string description;


    /** \fn bool is_number(string n)
    * \brief It checks if string n is convertible to natural number.
    * \param n string to be checked
    ****************************************************************************************/
    bool is_number(std::string n);

public:

    /** \fn Area()
     * \brief A basic constructor without parameters.
     ****************************************************************************************/
    Area() noexcept
        : scul(nullptr), description("")
    {}


    /** \fn Area(Sculpture* s, string des)
     * \brief A constructor with basic parameters.
     * Doors and items have to be added manually with another function.
     * \param s the sculpture or nullptr if there is no sculpture in the area
     * \param des the string with description to give hints to riddles in the game
     ****************************************************************************************/
    Area(Sculpture* s, std::string des)
        : scul(s), description(des)
    {}


    /** \fn void add_door(Door* door, Area* area)
     * \brief Adds to vectors "doors" and "areas" a door and area that it leads to.
     * \param door the door to be added
     * \param area the area to be added, door leads to it
    ****************************************************************************************/
    void add_door(Door* door, Area* area)
    {
        doors.push_back(door);
        areas.push_back(area);
    }


    /** \fn void add_item(Key* key)
     * \brief Adds a key to the vector "items".
     * \param key the key to be added
    ****************************************************************************************/
    void add_item(Key* key)
    {
        items.push_back(key);
    }


    /** \fn void show_description_and_actions()
     * \brief Writes the description of area to the standard output.
     *
     * Writes:
     * - description,
     * - list of doors in the area with their index in vector,
     * - list of items in the area with their index in vector,
     * - information if there is a sculpture in the area,
     * - list of actions for player with instruction what to type to the standard input.
    ****************************************************************************************/
    void show_description_and_actions();


    /** \fn pair<int,int> make_action()
     * \brief Takes from the standard input and returns a pair of integers.
     *
     * Pair:
     * - index of the action,
     * - argument for the action (or 0 if none is needed).
    ****************************************************************************************/
    std::pair<int, int> make_action();


    /** \fn void check_scul()
     * \brief Writes to the standard output a description of the sculpture.
    ****************************************************************************************/
    void check_scul();


    /** \fn void pick_up_item(int i, Inventory *inv)
     * \brief Adds to inventory the item from vector items from given index.
     * \param i the index of the item to be added
     * \param inv the inventory to what the item will be added
     ****************************************************************************************/
    void pick_up_item(int i, Inventory *inv);


    /** \fn int use_door(int i)
     * \brief Delegates task of checking access to door to class Door.
     * \param i the index of the door from vector doors
    ****************************************************************************************/
    int use_door(int i);
};
