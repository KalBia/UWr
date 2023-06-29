#include "inventory.hpp"

//*******************************************

void Inventory::add_item(Key *key)
{
    inv.insert(key);
}

//*******************************************

void Inventory::show_inventory()
{
    std::cout<< "\n\nYOUR INVENTORY\n";
    int i = 0;
    for (auto e : inv)
    {
        std::cout<< i++ << " : " << e->get_name() << "\n";
    }
    std::cout<< "\n\n";
}

//*******************************************

bool Inventory::try_to_put_treasure_together(Treasure *treasure)
{
    if (inv.count(treasure) == treasure->get_parts())
        return true;
    return false;
}

//*******************************************

int Inventory::find_key(int i)
{
    int ind = 0;
    for (auto e : inv)
    {
        if (ind == i)
            return e->get_id();
        ind++;
    }
    return -1;
}
