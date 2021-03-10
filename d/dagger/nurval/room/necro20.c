#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLACK%^Ancient obsidian pyramid opens its gates to the east.
");
        set_exits(([
                "north":ROOMS+"/necro21",
                "northwest":ROOMS+"/necro12",
                "west":ROOMS+"/necro11",
                "southwest":ROOMS+"/necro10",
                "south":ROOMS+"/necro19",
//                "southeast":ROOMS+"/necro25",
                "east":ROOMS+"/tomb1",
//                "northeast":ROOMS+"/necro24",
                ]));
}

void reset(){
   ::reset();
   if(!present("street_light",TO))
       new("/d/common/obj/misc/street_light")->move(TO);
    if (!present("guard"))
        new(MONS + "/necroknight")->move(TO);
    if (!present("guard 2"))
        new(MONS + "/necroknight")->move(TO);
    if (!present("guard 3"))
        new(MONS + "/necroknight")->move(TO);
    if (!present("banshee"))
        new(MONS + "/banshee")->move(TO);
}
