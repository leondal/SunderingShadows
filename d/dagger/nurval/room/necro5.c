#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLACK%^An obsidian wall isolates the necropolis.
");

        set_exits(([
//                "north":ROOMS+"/necro4",
//                "northwest":ROOMS+"/necro4",
//                "west":ROOMS+"/necro4",
//                "southwest":ROOMS+"/necro4",
                "south":ROOMS+"/necro4",
                "southeast":ROOMS+"/necro11",
                "east":ROOMS+"/necro12",
                "northeast":ROOMS+"/necro13",
                ]));
}
