#include "../undead.h"

inherit ROOM;

void create() 
{
    ::create();

    set_name("A trail along the river bank");
    set_terrain(LIGHT_FOREST);
    set_travel(FOOT_PATH);
    set_climate("temperate");
    set_property("light", 2);

    set_short("%^BOLD%^You are on a trail.%^RESET%^");

    set_long("%^BOLD%^You are on a small trail which winds along the river bank.\n%^RESET%^"
        "To the south you see the %^GREEN%^Peth Forest%^RESET%^, a dark and dangerous "
        "assortment of trees and brush. Along the river bank, to the south, you "
        "can make out a nasty looking swamp. Currently you are traveling along "
        "the west bank of the %^BLUE%^River of Sorrows%^RESET%^ which appears to "
        "flow between the towering %^MAGENTA%^Canyon of Decision%^RESET%^.  "
        "Though what lays on the other side of the canyon is anyone's guess.%^RESET%^");

    set_exits(([
        "north":BO+"path13",
        "east":BO+"sroom18",
        "south":BO+"sroom15",
        "southwest":BO+"path11"
             ]));

    set_smell("default","The smell of the wild pervades your senses.");
    set_listen("default","You can hear the ravens cawing and the river rushing.");

}