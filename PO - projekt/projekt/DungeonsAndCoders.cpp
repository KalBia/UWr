#include "game.hpp"
#include "area.hpp"
#include "classic_door.hpp"
#include "door_with_key.hpp"
#include "door_with_riddle.hpp"
#include "door.hpp"
#include "exit.hpp"
#include "inventory.hpp"
#include "key.hpp"
#include "sculpture.hpp"
#include "treasure.hpp"

//*******************************************

int main()
{
    std::cout<< "\nVERSION ALFA - only easy level available for players.\n\n";

    // keys
    int keys_id_generator = 17;
    auto red_key = new Key("red key", "rather old, crimson red color", keys_id_generator++); // 17
    auto blue_key = new Key("blue key", "shape of lizard, ocean-blue color", keys_id_generator++); // 18

    // treasure
    auto tres = new Treasure(2, "gold triangle", "shiny, looks important", 0);

    // sculpture
    auto sculp = new Sculpture("A woman holding bowl of apples");

    // areas
    auto S = new Area(nullptr, "Dark, dirty, only moss on the walls. You don't feel too well in here.");
    auto A1 = new Area(nullptr, "Water is dripping through the ceiling and the air is musty.");
    A1->add_item(blue_key);
    auto A2 = new Area(nullptr, "Some light is coming through the ceiling. But not much...");
    A2->add_item(red_key);
    auto A3 = new Area(nullptr, "Stones, stones, some grass... and more stones.");
    A3->add_item(tres);
    auto A4 = new Area(sculp, "The walls are painted purple. Interesting.");
    auto A5 = new Area(nullptr, "The room is twice as big as the previous one. It's a lot less claustrophobic.");
    A5->add_item(tres);
    auto E = new Area(nullptr, "You can feel fresh air and freedom.");

    // doors
    auto S_A1 = new Door_Classic("The door looks heavy.");
    auto A1_A2 = new Door_Classic("The door is covered in plants.");
    auto A1_A5 = new Door_Riddle("There is a face of monkey carved on the door.", "What is in the bowl? [singular]", "apple");
    auto A5_E = new Exit("The door is enormous and has a strange shape in the place of the key.");
    auto A2_A3 = new Door_Key(17, "The door is painted red.");
    auto A2_A4 = new Door_Key(18, "The door is painted blue.");

    // add doors to areas
    S->add_door(S_A1, A1);
    A1->add_door(S_A1, S);
    A1->add_door(A1_A2, A2);
    A1->add_door(A1_A5, A5);
    A2->add_door(A1_A2, A1);
    A2->add_door(A2_A3, A3);
    A2->add_door(A2_A4, A4);
    A3->add_door(A2_A3, A2);
    A4->add_door(A2_A4, A2);
    A5->add_door(A1_A5, A1);
    A5->add_door(A5_E, E);

    // game
    auto B = new Inventory();
    auto GAME = new Game(B, S, E, tres);

    GAME->run_game();
}
