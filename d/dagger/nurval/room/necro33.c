#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLACK%^An obsidian wall isolates the necropolis to the east. Ancient pyramid towers over the necropolis to the south.
");
        set_exits(([
                       "north":ROOMS+"/necro26",
                       "northwest":ROOMS+"/necro29",
                "west":ROOMS+"/necro34",
//                "southwest":ROOMS+"/necro32",
//                "south":ROOMS+"/necro32",
//                "southeast":ROOMS+"/necro26",
//                "east":ROOMS+"/necro35",
                "northeast":ROOMS+"/necro36",
                ]));
}
