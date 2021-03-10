#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLACK%^Ancient obsidian pyramid opens its gates to the south.
");
        set_exits(([
                "north":ROOMS+"/necro29",
                "northwest":ROOMS+"/necro27",
                "west":ROOMS+"/necro35",
//                "southwest":ROOMS+"/necro23",
                "south":ROOMS+"/tomb2",
//                "southeast":ROOMS+"/necro29",
                "east":ROOMS+"/necro33",
                "northeast":ROOMS+"/necro26",
                ]));
}

void reset(){
   ::reset();
   if(!present("street_light",TO))
       new("/d/common/obj/misc/street_light")->move(TO);
}
