#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLACK%^An obsidian pyramid towers over the necropolis to the southeast.
");
        set_exits(([
                "north":ROOMS+"/necro23",
                "northwest":ROOMS+"/necro14",
                "west":ROOMS+"/necro13",
                "southwest":ROOMS+"/necro12",
                "south":ROOMS+"/necro21",
//                "southeast":ROOMS+"/necro25",
                "east":ROOMS+"/necro35",
                "northeast":ROOMS+"/necro27",
                ]));
}
