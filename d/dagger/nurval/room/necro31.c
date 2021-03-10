#include "../tomb.h"

inherit ROOM;

void create(){
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_name("Necropolis");
    set_short("%^BOLD%^%^BLUE%^Gates to the necropolis, %^WHITE%^Tomb of Nurval%^RESET%^");
    set_long(query_short() + "
%^BLUE%^This %^BOLD%^%^BLACK%^endless%^RESET%^%^BLUE%^ graveyard is build upon a %^BOLD%^%^BLACK%^ruined%^RESET%^%^BLUE%^ city. Walls of houses destroyed with fire stand next to the grave stones. Most of the graves are ancient. Some are newly made. Tombs and graves have been moved into the city from elsewhere, as if two places - the graveyard and the city - were joined together. The %^CYAN%^cold%^BLUE%^ rises from the ground touching everything.

%^BOLD%^%^BLACK%^Arch in the obsidian wall signifies the entrance. The main road passes through to the south.
");

    set_exits(([
                   //"north":"/d/dagger/road/road35",
//                "northwest":ROOMS+"/necro28",
//                "west":ROOMS+"/necro28",
//                "southwest":ROOMS+"/necro27",
                   "south":ROOMS+"/necro30",
//                "southeast":ROOMS+"/necro26",
//                "east":ROOMS+"/necro32",
//                "northeast":ROOMS+"/necro32",
                   ]));
    set_heart_beat(0);
}

void reset()
{
    ::reset();
    if (!present("street_light", TO))
        new("/d/common/obj/misc/street_light")->move(TO);
    if (!present("warning sign", TO))
        new(OBJS + "/entrysign")->move(TO);
    if (!present("guard"))
        new(MONS + "/necroknight")->move(TO);
    if (!present("guard 2"))
        new(MONS + "/necroknight")->move(TO);
    if (!present("guard 3"))
        new(MONS + "/necroknight")->move(TO);
}
