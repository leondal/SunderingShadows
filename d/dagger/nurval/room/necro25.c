#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLACK%^An obsidian wall isolates the necropolis.
");
        set_exits(([
//                "north":ROOMS+"/necro25",
                "northwest":ROOMS+"/necro16",
                "west":ROOMS+"/necro15",
//                "southwest":ROOMS+"/necro14",
                "south":ROOMS+"/necro24",
                "southeast":ROOMS+"/necro28",
//                "east":ROOMS+"/necro28",
//                "northeast":ROOMS+"/necro28",
                ]));
}
