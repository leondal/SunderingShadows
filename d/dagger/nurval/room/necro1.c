#include <std.h>
#include "../tomb.h"

inherit ROOM;

void create()
{
    ::create();
    set_terrain(CEMETERY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_name("Necropolis");
    set_short("%^BOLD%^%^BLUE%^Gates to the necropolis, %^WHITE%^Tomb of Nurval%^RESET%^");
    set_long(query_short() + "
%^BLUE%^This %^BOLD%^%^BLACK%^endless%^RESET%^%^BLUE%^ graveyard is build upon a %^BOLD%^%^BLACK%^ruined%^RESET%^%^BLUE%^ city. Walls of houses destroyed with fire stand next to the grave stones. Most of the graves are ancient. Some are newly made. Tombs and graves have been moved into the city from elsewhere, as if two places - the graveyard and the city - were joined together. The %^CYAN%^cold%^BLUE%^ rises from the ground touching everything.

%^BOLD%^%^BLACK%^Arch in the obsidian wall signifies the entrance. The main road passes through to the east.
");
    set_exits(([
                   //"west": "/d/dagger/road/road25",
                   "east":ROOMS + "/necro4",
                   ]));
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
    if (!present("guard 4"))
        new(MONS + "/necroknight")->move(TO);
    if (!present("guard 5"))
        new(MONS + "/necroknight")->move(TO);
    if (!present("bonewyvern"))
        new(MONS + "/bonewyvern")->move(TO);
    if (!present("bonewyvern 2"))
        new(MONS + "/bonewyvern")->move(TO);
}
