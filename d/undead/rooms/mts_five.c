#include "../undead.h"

inherit ROOM;

void create() 
{
    ::create();
    
    set_name("A mountain path above a river");
    set_terrain(NEW_MOUNTS);
    set_travel(GAME_TRACK);
    set_property("indoors", 0);
    set_property("light", 2);
    set_climate("mountain");

    set_short("%^MAGENTA%^You are in the mountains");

    set_long("%^MAGENTA%^You are traveling a small path in the mountains.%^RESET%^\n"
        "All around you the treacherous peaks of the Thoradin Range rise up "
        "like daggers through the clouds. Right now you are traveling between "
        "the peaks in no particular direction, trying your best to keep your "
        "footing. Below you, to the east, you see the raging waters of the "
        "%^BLUE%^River of Sorrows%^RESET%^.");
 
    set_exits(([
        "north"     :MTS+"room38",
        "southwest" :MTS+"room11"
             ]));

    set_smell("default","The fresh scent of nature is about you.");
    set_listen("default","You can hear a few birds chirping around you.");

}