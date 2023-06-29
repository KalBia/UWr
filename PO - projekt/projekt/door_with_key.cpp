#include "door_with_key.hpp"

//*******************************************

int Door_Key::use_me()
{
    std::string ans;
    if (unlocked)
    {
        std::cout<< "The door is unlocked! Do you want to go through it? [y/n]\n";
        std::cin>> ans;
        if (ans == "y")
            return 1;
        return 0;
    }

    std::cout<< "The door is locked with the key! Do you want to look for the key in the inventory? [y/n]\n";
    std::cin>> ans;

    if (ans == "n")
        return 0;

    return key_id;
}
