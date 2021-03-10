#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLACK%^An obsidian wall isolates the necropolis.
");
        set_exits(([
//                "north":ROOMS+"/necro28",
                "northwest":ROOMS+"/necro25",
                "west":ROOMS+"/necro24",
                "southwest":ROOMS+"/necro23",
                "south":ROOMS+"/necro27",
                "southeast":ROOMS+"/necro29",
                "east":ROOMS+"/necro30",
//                "northeast":ROOMS+"/necro30",
                ]));
}
