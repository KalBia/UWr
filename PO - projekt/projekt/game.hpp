#pragma once
#include "inventory.hpp"
#include "area.hpp"
#include "key.hpp"
#include "door.hpp"
#include "door_with_key.hpp"
#include "door_with_riddle.hpp"

//*******************************************

/** \class Game
 * \brief The main manager of the game.
 * It delegates control to other classes according to the action took by the player.
 ****************************************************************************************/
class Game
{
private:

    /** \var Inventory* backpack
     * \brief The container for items/keys picked up by the player.
     ****************************************************************************************/
    Inventory* backpack;


    /** \var Treasure* tres
     * \brief Information about the treasure needed to end the game.
     ****************************************************************************************/
    Treasure* tres;


    /** \var Area* current
     * \brief Holds information about the current position of the player.
     ****************************************************************************************/
    Area* current;


    /** \var Area* end
     * \brief Holds information about the last location of the game.
     ****************************************************************************************/
    Area* end;

public:

    /** \fn Game()
     * \brief A basic constructor, no parameters
     ****************************************************************************************/
    Game() noexcept
        : backpack(new Inventory()), current(new Area()), end(new Area()), tres(new Treasure())
    {}


    /** \fn Game(Inventory* b, Area* s, Area* e, Treasure* t)
     * \brief A constructor, basic parameters.
     * \param b the initial inventory for the player
     * \param s the current/start position/area
     * \param e the last area of the game
     * \param t the treasure to find
     ****************************************************************************************/
    Game(Inventory* b, Area* s, Area* e, Treasure* t) noexcept
        : backpack(b), current(s), end(e), tres(t)
    {}


    /** \fn void run_game()
     * \brief Start and conduct the game.
     ****************************************************************************************/
    void run_game();


    /** \fn void add_to_invetory(Key *key)
     * \brief Adds a key to the inventory.
     * \param key Key to add to the inventory
     ****************************************************************************************/
    void add_to_inventory(Key *key);


    /** \fn void check_inventory()
     * \brief Writes to the standard output all items in the inventory.
     ****************************************************************************************/
    void check_inventory();


    /** \fn void explore_area()
     * \brief Manages the descriptions of objects and actions of player.
     ****************************************************************************************/
    void explore_area();


    /** \fn bool look_for_key(int key_id, int i)
     * \brief Checks if the key on the given position in inventory is the one with the key_id given.
     * \param key_id the key's id we look for
     * \param i the position of the candidate for the correct key
     ****************************************************************************************/
    bool look_for_key(int key_id, int i);
};
