#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLACK%^An obsidian wall isolates the necropolis.
");
        set_exits(([
//                "north":ROOMS+"/necro25",
//                "northwest":ROOMS+"/necro16",
//                "west":ROOMS+"/necro15",
//                "southwest":ROOMS+"/necro14",
//                "south":ROOMS+"/necro24",
                "southeast":ROOMS+"/necro6",
                "east":ROOMS+"/necro7",
                "northeast":ROOMS+"/necro8",
                ]));
}
