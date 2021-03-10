#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLACK%^An obsidian wall isolates the necropolis.
");
        set_exits(([
                "north":ROOMS+"/necro18",
                "northwest":ROOMS+"/necro9",
//                "west":ROOMS+"/necro8",
//                "southwest":ROOMS+"/necro8",
//                "south":ROOMS+"/necro15",
//                "southeast":ROOMS+"/necro25",
//                "east":ROOMS+"/necro25",
//                "northeast":ROOMS+"/necro24",
                ]));
}
