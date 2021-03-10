#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLUE%^A large tomb blocks passage to the south.
");
        set_exits(([
                "north":ROOMS+"/necro16",
//                "northwest":ROOMS+"/necro7",
                "west":ROOMS+"/necro8",
                "southwest":ROOMS+"/necro7",
//                "south":ROOMS+"/necro13",
                "southeast":ROOMS+"/necro24",
                "east":ROOMS+"/necro25",
//                "northeast":ROOMS+"/necro24",
                ]));
}
