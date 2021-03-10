#include "../undead.h"

inherit ROOM;

void create() 
{
    ::create();
    
    set_name("Approaching a darkened bog");
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
        "footing. You see a large marsh in the valley below you, it looks like "
        "something out of your worst nightmares. You hope the path you are on "
        "now does not lead you down there.");
 
    set_exits(([
        "northwest" :MTS+"room53",
        "southeast" :MTS+"room51"
             ]));

    set_smell("default","The fresh scent of nature is about you.");
    set_listen("default","You can hear a few birds chirping around you.");

}