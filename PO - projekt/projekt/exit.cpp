#include "exit.hpp"

//*******************************************

int Exit::use_me()
{
    std::string ans;
    if (unlocked)
    {
        std::cout<< "The exit is unlocked! Do you want to go out of here? [y/n]\n";
        std::cin>> ans;
        if (ans == "y")
            return 1;
        return 0;
    }

    std::cout<< "This is the exit! Do you want to try to open it? [y/n]\n";
    std::cin>> ans;

    if (ans == "n")
        return 0;
    return -1;
}
