#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLACK%^An obsidian wall isolates the necropolis.
");
        set_exits(([
                "north":ROOMS+"/necro10",
                "northwest":ROOMS+"/necro3",
//                "west":ROOMS+"/necro2",
//                "southwest":ROOMS+"/necro2",
//                "south":ROOMS+"/necro7",
                "southeast":ROOMS+"/necro17",
                "east":ROOMS+"/necro18",
                "northeast":ROOMS+"/necro19",
                ]));
}
