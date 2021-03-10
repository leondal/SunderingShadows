#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLACK%^An obsidian wall isolates the necropolis.
");
        set_exits(([
                "north":ROOMS+"/necro7",
                "northwest":ROOMS+"/necro2",
//                "west":ROOMS+"/necro4",
//                "southwest":ROOMS+"/necro4",
//                "south":ROOMS+"/necro4",
                "southeast":ROOMS+"/necro13",
                "east":ROOMS+"/necro14",
//                "northeast":ROOMS+"/necro13",
                ]));
}
