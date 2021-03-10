#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLACK%^An obsidian pyramid towers over the necropolis to the east.
");
        set_exits(([
                "north":ROOMS+"/necro22",
                "northwest":ROOMS+"/necro13",
                "west":ROOMS+"/necro12",
                "southwest":ROOMS+"/necro11",
                "south":ROOMS+"/necro20",
//                "southeast":ROOMS+"/necro25",
//                "east":ROOMS+"/tomb1",
//                "northeast":ROOMS+"/necro24",
                ]));
}
