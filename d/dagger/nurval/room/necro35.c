#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLACK%^An obsidian pyramid towers over the necropolis to the south.
");
        set_exits(([
                       "north":ROOMS+"/necro27",
                "northwest":ROOMS+"/necro23",
                "west":ROOMS+"/necro22",
//                "southwest":ROOMS+"/necro32",
//                "south":ROOMS+"/necro32",
//                "southeast":ROOMS+"/necro26",
                "east":ROOMS+"/necro34",
                "northeast":ROOMS+"/necro29",
                ]));
}
