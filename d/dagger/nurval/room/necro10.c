#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
        set_exits(([
                "north":ROOMS+"/necro11",
                "northwest":ROOMS+"/necro4",
                "west":ROOMS+"/necro3",
//                "southwest":ROOMS+"/necro2",
                "south":ROOMS+"/necro9",
                "southeast":ROOMS+"/necro18",
                "east":ROOMS+"/necro19",
                "northeast":ROOMS+"/necro20",
                ]));
}
