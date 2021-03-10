#include "../undead.h"

inherit ROOM;

void create() 
{
    ::create();

    set_name("A dark warehouse");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);

    set_short("%^BOLD%^%^BLACK%^You are inside a dark warehouse.%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^You are inside a dark warehouse.%^RESET%^\n"
        "Boxes and crates are piled up every where, you figure that this is "
        "where merchants store all of there goods. It looks like there are "
        "a lot of war supplies in here too.");
 
    set_exits(([
        "east"      :TOWN+"room11"
             ]));

    set_smell("default","The fresh scent of the ocean assails you.");
    set_listen("default","You hear the sounds of battle in the distance.");
}
