#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLACK%^An obsidian wall isolates the necropolis.
");

        set_exits(([
//                "north":ROOMS+"/necro8",
//                "northwest":ROOMS+"/necro2",
//                "west":ROOMS+"/necro2",
                "southwest":ROOMS+"/necro2",
                "south":ROOMS+"/necro7",
//                "southeast":ROOMS+"/necro14",
                "east":ROOMS+"/necro15",
                "northeast":ROOMS+"/necro16",
                ]));
}
