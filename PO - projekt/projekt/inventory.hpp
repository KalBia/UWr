#pragma once
#include <iostream>
#include <set>
#include <initializer_list>
#include "key.hpp"
#include "treasure.hpp"

//*******************************************

/** \class Inventory
 * \brief Holds the multiset of Keys and manage procedures on it.
 ****************************************************************************************/
class Inventory
{
private:

    /** \var multiset<Key*> inv
     * \brief Holds items picked by player during the game.
     ****************************************************************************************/
    std::multiset<Key*> inv;

public:

    /** \fn Inventory()
     * \brief A basic constructor, no parameters.
     ****************************************************************************************/
    Inventory() noexcept
    {}


    /** \fn Inventory(initializer_list<Key*>)
     * \brief A constructor, basic parameters.
     * \param i the list of items that are initially in players backpack.
     ****************************************************************************************/
    Inventory(std::initializer_list<Key*> i) noexcept
    {
        auto it = i.begin();
        while (it != i.end())
            add_item(*it++);
    }


    /** \fn void add_item(Key* key)
     * \brief Adds a key to the multiset.
     * \param key the key to add
     ****************************************************************************************/
    void add_item(Key *key);


    /** \fn void show_inventory()
     * \brief Writes to the standard output all items in multiset with their index in container.
     ****************************************************************************************/
    void show_inventory();


    /** \fn bool try_to_put_treasure_together(Treasure *treasure)
     * \brief Checks if the player has all parts of treasure in his inventory.
     * \param treasure the treasure that parts we count
     ****************************************************************************************/
    bool try_to_put_treasure_together(Treasure *treasure);


    /** \fn int size_of_inv()
     * \brief Returns the number of items in inventory.
     ****************************************************************************************/
    int size_of_inv() { return inv.size(); };


    /** \fn int find_key(int i)
     * \brief Return the id of the key from this index in the inventory.
     * \param i the index of the key in the inventory
     ****************************************************************************************/
    int find_key(int i);
};
