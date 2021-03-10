#include <std.h>
#include "../tomb.h"

inherit ROOM;

void create()
{
    ::create();
    set_property("light", 2);
    set_property("indoors", 0);
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
    set_short("%^BOLD%^%^BLACK%^Gloomy Village");
    set_long(query_short() + "
%^RESET%^%^ORANGE%^A small village of mortals has been set up by this side of %^BOLD%^%^BLACK%^the %^BLACK%^p%^BLACK%^y%^BLACK%^r%^BLACK%^a%^BLACK%^m%^BLACK%^i%^BLACK%^d%^BLACK%^.%^RESET%^%^ORANGE%^ Most houses are newly-build wooden buildings, it seems not much thought had been put into their construction but they look sturdy enough. Several mortals wander around on their business. This place isn't free of looming presence of the pyramid, people of the village occasionally glance over it. To the east you see a path wide enough to let a wagon to pass, and further %^ORANGE%^a %^BOLD%^%^BLACK%^marbl%^RESET%^%^RED%^e %^RED%^s%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^u%^RESET%^%^RED%^ct%^BOLD%^%^BLACK%^u%^RESET%^%^RED%^re%^BOLD%^%^BLACK%^%^RESET%^%^ORANGE%^.

%^ORANGE%^Sign to the north reads %^BOLD%^'Bakery'%^RESET%^.
");
    set_smell("default", "Your nose catches smells of dozens of people.");
    set_listen("default", "You hear humming noise of village's life.");
    set_exits(([
                   "west" : ROOMS + "/village",
                   "north" : ROOMS + "/bakery",
                   "east" : "/d/dagger/road/p8",
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
    if (!present("guard 4"))
        new(MONS + "/necroknight")->move(TO);
    if (!present("guard 5"))
        new(MONS + "/necroknight")->move(TO);
    if (!present("banshee"))
        new(MONS + "/banshee")->move(TO);
}
