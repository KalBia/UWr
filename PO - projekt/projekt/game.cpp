#include "game.hpp"

//*******************************************

void Game::add_to_inventory(Key *key)
{
    backpack->add_item(key);
}

//*******************************************

void Game::check_inventory()
{
    backpack->show_inventory();
}

//*******************************************

void Game::run_game()
{
    std::cout<< "You wake up in the dark, unpleasent place. The only thing you remember are the words: find all parts of the treasure and get out of here...\n";
    std::cout<< "You have a backpack but you can't remember if it's your. Above you is a trapdoor but there is no way to reach it. It's too high. You have to find another way.\n";

    while (current != end) // why so weird? We don't want a big recursion in explore_area :D
        explore_area();

    std::cout<< "Finally! A daylight! You missed it. You leave this hell and go back to your life... Eventually.\n";
}

//*******************************************

bool Game::look_for_key(int key_id, int i)
{
    check_inventory();
    std::cout<< "Give number of key you want to use here: ";
    std::string s;
    std::cin>> s;

    int n = std::stoi(s);
    if (n < 0 || n >= backpack->size_of_inv())
    {
        std::cout<< "Wrong number of item. Try again.\n";
        return look_for_key(key_id, i);
    }

    if (backpack->find_key(n) != key_id)
    {
        std::cout<< "Wrong key.\n";
        return false;
    }

    auto d = current->doors[i];
    d->set_unlocked(true);
    std::cout<< "You unlocked the door! Do you want to go through it? [y/n]\n";
    std::string ans;
    std::cin>> ans;

    if (ans == "n")
        return false;
    return true;
}

//*******************************************

void Game::explore_area()
{
    current->show_description_and_actions();
    std::pair<int, int> action = current->make_action();

    int x;
    switch(action.first)
    {
        case 0: // use door
            x = current->use_door( action.second );
            if (x == 1)
            {
                current = current->areas[action.second];
                std::cout<< "You moved to the next place!\n";
            }
            else if (x == 0)
                std::cout<< "You didn't use the door. What now? You are still in the same place...\n";
            else if (x == -1)
                if (!backpack->try_to_put_treasure_together(tres))
                    std::cout<< "You didn't use the door. What now? You are still in the same place...\n";
                else
                {
                    current = current->areas[action.second];
                    std::cout<< "You moved to the next place!\n";
                }
            else // opcja door with key
                if (!look_for_key(x, action.second))
                    std::cout<< "You didn't use the door. What now? You are still in the same place...\n";
                else
                {
                    current = current->areas[action.second];
                    std::cout<< "You moved to the next place!\n";
                }
            break;
        case 1: // pick up item
            current->pick_up_item( action.second, backpack );
            std::cout<< "You picked it up. What now? You are still in the same place...\n";
            break;
        case 2: // examine sculpture
            current->check_scul();
            std::cout<< "What now? You are still in the same place...\n";
            break;
        case 3: // check inventory
            check_inventory();
            std::cout<< "What now? You are still in the same place...\n";
            break;
    }
}
