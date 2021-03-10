#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLACK%^The main road passes from the west to the east.
");
        set_exits(([
                "north":ROOMS+"/necro12",
                "northwest":ROOMS+"/necro5",
                "west":ROOMS+"/necro4",
                "southwest":ROOMS+"/necro3",
                "south":ROOMS+"/necro10",
                "southeast":ROOMS+"/necro19",
                "east":ROOMS+"/necro20",
                "northeast":ROOMS+"/necro21",
                ]));
}

void reset(){
   ::reset();
   if(!present("street_light",TO))
       new("/d/common/obj/misc/street_light")->move(TO);
}
