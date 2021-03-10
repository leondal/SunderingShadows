#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
        set_exits(([
                "north":ROOMS+"/necro13",
//                "northwest":ROOMS+"/necro5",
                "west":ROOMS+"/necro5",
                "southwest":ROOMS+"/necro4",
                "south":ROOMS+"/necro11",
                "southeast":ROOMS+"/necro20",
                "east":ROOMS+"/necro21",
                "northeast":ROOMS+"/necro22",
                ]));
}
