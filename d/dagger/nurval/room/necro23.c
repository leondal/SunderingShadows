#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
        set_exits(([
                "north":ROOMS+"/necro24",
//                "northwest":ROOMS+"/necro14",
                "west":ROOMS+"/necro14",
                "southwest":ROOMS+"/necro13",
                "south":ROOMS+"/necro22",
                "southeast":ROOMS+"/necro35",
                "east":ROOMS+"/necro27",
                "northeast":ROOMS+"/necro28",
                ]));
}
