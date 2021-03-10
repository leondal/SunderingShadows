#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLUE%^A large tomb blocks passage to the west.
");
        set_exits(([
                "north":ROOMS+"/necro25",
                "northwest":ROOMS+"/necro15",
//                "west":ROOMS+"/necro14",
                "southwest":ROOMS+"/necro14",
                "south":ROOMS+"/necro23",
                "southeast":ROOMS+"/necro27",
                "east":ROOMS+"/necro28",
//                "northeast":ROOMS+"/necro28",
                ]));
}
