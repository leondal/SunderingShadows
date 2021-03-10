#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLACK%^An obsidian pyramid towers over the necropolis to the east.
");
        set_exits(([
                "north":ROOMS+"/necro20",
                "northwest":ROOMS+"/necro11",
                "west":ROOMS+"/necro10",
                "southwest":ROOMS+"/necro9",
                "south":ROOMS+"/necro18",
//                "southeast":ROOMS+"/necro25",
//                "east":ROOMS+"/necro25",
//                "northeast":ROOMS+"/necro24",
                ]));
}
