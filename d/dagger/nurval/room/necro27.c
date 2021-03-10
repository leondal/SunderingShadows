#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
        set_exits(([
                "north":ROOMS+"/necro28",
                "northwest":ROOMS+"/necro24",
                "west":ROOMS+"/necro23",
                "southwest":ROOMS+"/necro22",
                "south":ROOMS+"/necro35",
                "southeast":ROOMS+"/necro34",
                "east":ROOMS+"/necro29",
                "northeast":ROOMS+"/necro30",
                ]));
}
