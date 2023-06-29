#include "area.hpp"

//*******************************************

bool Area::is_number(std::string n)
{
    for (char c : n)
    {
        if (c < '0' || c > '9')
            return false;
    }

    return true;
}

//*******************************************

std::pair<int, int> Area::make_action()
{
    std::string action = "";
    std::cout<< "\ntype your action: ";

    getline(std::cin, action);
    if (action == "")
        getline(std::cin, action);

    // we want to check first two words in string
    std::string temp1 = "";
    std::string temp2 = "";
    int i = 0;
    int l = action.length();
    while (i < l && action[i] != ' ')
        temp1 += action[i++];
    i++;
    while(i < l && action[i] != ' ')
        temp2 += action[i++];
    i++;

    // do what player typed
    try
    {
        std::string temp = "";
        if (temp1 == "use" && temp2 == "door")
        {
            while(i < l && action[i] != ' ')
                temp += action[i++];

            if (i < l && action[i] != ' ')
                throw std::invalid_argument("it looks like u typed too much... try again");

            if (!is_number(temp))
                throw std::invalid_argument("it looks like the last word is not a number... try again");

            int n = std::stoi(temp);
            if (n < 0 || n >= doors.size())
                throw std::invalid_argument("wrong number of door, try again");

            return std::make_pair(0, n);
        }
        else if (temp1 == "pick" && temp2 == "up")
        {
            while(i < l && action[i] != ' ')
                temp += action[i++];

            if (i < l && action[i] != ' ')
                throw std::invalid_argument("it looks like u typed too much... try again");

            if (!is_number(temp))
                throw std::invalid_argument("it looks like the last word is not a number... try again");

            int n = std::stoi(temp);
            if (n < 0 || n >= items.size())
                throw std::invalid_argument("wrong number of door, try again");

            return std::make_pair(1, n);
        }
        else if (temp1 == "examine" && temp2 == "sculpture")
        {
            if (i < l && action[i] != ' ')
                throw std::invalid_argument("it looks like u typed too much... try again");

            return std::make_pair(2, 0);
        }
        else if (temp1 == "check" && temp2 == "inventory")
        {
            if (i < l && action[i] != ' ')
                throw std::invalid_argument("it looks like u typed too much... try again");

            return std::make_pair(3, 0);
        }
        else
            throw std::invalid_argument("unknown command, check if you have written it correctly and try again");
    }
    catch (std::invalid_argument e)
    {
        std::cout<< e.what() << "\n";
        return make_action();
    }
}

//*******************************************

void Area::show_description_and_actions()
{
    // description
    std::cout<< "\n\n" << description;

    // doors
    std::cout<< "\n\nThere are " << doors.size() << " doors.\n";
    int i = 0;
    for (auto d : doors)
    {
        std::cout<< i++ << " : " << d->get_description();
        std::cout<< "\n";
    }

    // items
    std::cout<< "\nYou see " << items.size() << " items in here.\n";
    i = 0;
    for (auto it : items)
    {
        std::cout<< i++ << " : " << it->get_name() << "\n";
    }

    // sculpture
    if (scul != nullptr)
    {
        std::cout<< "\nThere is a sculpture in the middle of area.\n";
    }

    // actions
    std::cout<< "\nYou can...\n";
    std::cout<< "...try to use door. [type: use door <number of door>]\n";
    std::cout<< "...pick up an item. [type: pick up <number of item>]\n";
    if (scul != nullptr)
        std::cout<< "...examine the sculpture. [type: examine sculpture]\n";
    std::cout<< "...check your inventory. [type: check inventory]\n";
}

//*******************************************

void Area::check_scul()
{
    std::cout<< "You study the sculpture.\n#######################\n" << scul->get_description() << "\n#######################\n";
}

//*******************************************

void Area::pick_up_item(int i, Inventory *inv)
{
    std::cout<< "Do you want to examine this item right now? [y/n]\n";
    std::string ans;
    std::cin>> ans;

    if (ans == "y")
    {
        std::cout<< "\n################################\n";
        std::cout<< items[i]->get_description() << "\n";
        std::cout<< "################################\n";
    }

    inv->add_item( items[i] );
    items.erase(items.begin() + i);
}

//*******************************************

int Area::use_door(int i)
{
    return doors[i]->use_me();
}
