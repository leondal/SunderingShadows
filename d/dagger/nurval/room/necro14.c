#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLUE%^To the north one of the tombs is open, faint light comes out of it.
");
        set_exits(([
//                "north":ROOMS+"/library",
                "northwest":ROOMS+"/necro7",
                "west":ROOMS+"/necro6",
//                "southwest":ROOMS+"/necro5",
                "south":ROOMS+"/necro13",
                "southeast":ROOMS+"/necro22",
                "east":ROOMS+"/necro23",
                "northeast":ROOMS+"/necro24",
                ]));
}
