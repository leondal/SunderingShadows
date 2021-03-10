#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLACK%^Arch in obsidian wall signifies the entrance. The main road passes through to the south.
");
        set_exits(([
                "north":ROOMS+"/necro31",
//                "northwest":ROOMS+"/necro28",
                "west":ROOMS+"/necro28",
                "southwest":ROOMS+"/necro27",
                "south":ROOMS+"/necro29",
                "southeast":ROOMS+"/necro26",
                "east":ROOMS+"/necro32",
//                "northeast":ROOMS+"/necro32",
                ]));
}

void reset(){
   ::reset();
   if(!present("street_light",TO))
       new("/d/common/obj/misc/street_light")->move(TO);
}
