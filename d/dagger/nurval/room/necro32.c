#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLACK%^An obsidian wall isolates the necropolis.
");
        set_exits(([
//                       "north":"/d/dagger/road/road32",
//                "northwest":ROOMS+"/necro30",
                "west":ROOMS+"/necro30",
                "southwest":ROOMS+"/necro29",
                "south":ROOMS+"/necro26",
                "southeast":ROOMS+"/necro36",
//                "east":ROOMS+"/necro32",
//                "northeast":ROOMS+"/necro32",
                ]));
}
