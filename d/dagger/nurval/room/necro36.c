#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLACK%^An obsidian wall isolates the necropolis.
");
        set_exits(([
//                "north":ROOMS+"/necro28",
                "northwest":ROOMS+"/necro32",
                "west":ROOMS+"/necro26",
                "southwest":ROOMS+"/necro33",
//                "south":ROOMS+"/necro24",
//                "southeast":ROOMS+"/necro28",
//                "east":ROOMS+"/necro29",
//                "northeast":ROOMS+"/necro30",
                ]));
}
