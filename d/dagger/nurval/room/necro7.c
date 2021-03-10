#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLUE%^A large tomb blocks passage to the east.
");
        set_exits(([
                "north":ROOMS+"/necro8",
//                "northwest":ROOMS+"/necro2",
                "west":ROOMS+"/necro2",
//                "southwest":ROOMS+"/necro4",
                "south":ROOMS+"/necro6",
                "southeast":ROOMS+"/necro14",
//                "east":ROOMS+"/necro14",
                "northeast":ROOMS+"/necro15",
                ]));
}
