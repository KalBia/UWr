#include "door_with_riddle.hpp"

//*******************************************

std::string Door_Riddle::lowercase_and_no_whitespace(std::string s)
{
    std::string result = "";
    for (char c : s)
    {
        if (c != ' ')
        {
            if (c >= 'A' && c <= 'Z')
                result += (c + ('a' - 'A'));
            else
                result += c;
        }
    }
    return result;
}

//*******************************************

bool Door_Riddle::check_answer_to_riddle(std::string a)
{
    if (lowercase_and_no_whitespace(a) == lowercase_and_no_whitespace(solution))
        return true;
    return false;
}

//*******************************************

int Door_Riddle::use_me()
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

    std::cout<< "The door is locked with riddle! Do you want to read it? [y/n]\n";
    std::cin>> ans;

    if (ans == "n")
        return 0;

    std::cout<< "\n#############################\n";
    std::cout<< riddle << "\n";
    std::cout<< "#############################\n";
    std::cout<< "Do you want to give an answer to the riddle? [y/n]\n";
    std::cin>> ans;

    if (ans == "n")
        return 0;

    std::cout<< "type your answer: ";
    std::cin>> ans;

    if (check_answer_to_riddle(ans))
    {
        unlocked = true;
        std::cout<< "You unlocked the door! Do you want to go through it? [y/n]\n";
        std::cin>> ans;
        if (ans == "y")
            return 1;
    }
    else
        std::cout<< "It's the wrong answer...\n";

    return 0;
}
