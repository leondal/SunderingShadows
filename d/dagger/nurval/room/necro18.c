#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
        set_exits(([
                "north":ROOMS+"/necro19",
                "northwest":ROOMS+"/necro10",
                "west":ROOMS+"/necro9",
//                "southwest":ROOMS+"/necro8",
                "south":ROOMS+"/necro17",
//                "southeast":ROOMS+"/necro25",
//                "east":ROOMS+"/necro25",
//                "northeast":ROOMS+"/necro24",
                ]));
}
