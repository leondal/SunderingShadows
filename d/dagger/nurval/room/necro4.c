#include "../tomb.h"

inherit NECROPOLIS;

void create()
{
    ::create();
    set_long(::query_long() + "
%^BOLD%^%^BLACK%^Arch in obsidian wall signifies the exit. The main road passes through to the east.
");
        set_exits(([
                "north":ROOMS+"/necro5",
                "west":ROOMS+"/necro1",
                "south":ROOMS+"/necro3",
                "southeast":ROOMS+"/necro10",
                "east":ROOMS+"/necro11",
                "northeast":ROOMS+"/necro12",
                ]));
}

void reset()
{
    ::reset();
    if (!present("street_light", TO))
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
