#include "classic_door.hpp"

//*******************************************

int Door_Classic::use_me()
{
    std::cout<< "The door is unlocked! Do you want to go through it? [y/n]\n";
    std::string ans;
    std::cin>> ans;
    if (ans == "y")
        return 1;
    return 0;
}
