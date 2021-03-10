#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLACK%^An obsidian wall isolates the necropolis.
");
        set_exits(([
                "north":ROOMS+"/necro4",
                "southeast":ROOMS+"/necro9",
                "east":ROOMS+"/necro10",
                "northeast":ROOMS+"/necro11",
                ]));
}
