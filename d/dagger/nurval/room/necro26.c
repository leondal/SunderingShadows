#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
        set_exits(([
                       "north":ROOMS+"/necro32",
                       "northwest":ROOMS+"/necro30",
                       "west":ROOMS+"/necro29",
                       "southwest":ROOMS+"/necro34",
                       "south":ROOMS+"/necro33",
//                "southeast":ROOMS+"/necro26",
                       "east":ROOMS+"/necro36",
//                "northeast":ROOMS+"/necro32",
                ]));
}
