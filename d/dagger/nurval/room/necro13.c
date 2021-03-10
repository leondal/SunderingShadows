#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLACK%^An obsidian wall isolates the necropolis.
");

        set_exits(([
                "north":ROOMS+"/necro14",
                "northwest":ROOMS+"/necro6",
//                "west":ROOMS+"/necro5",
                "southwest":ROOMS+"/necro5",
                "south":ROOMS+"/necro12",
                "southeast":ROOMS+"/necro21",
                "east":ROOMS+"/necro22",
                "northeast":ROOMS+"/necro23",
                ]));
}
