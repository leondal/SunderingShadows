#include <std.h>
#include "../tharis.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",1);
    set_name("Secret passageway");
    set_short("%^RESET%^%^ORANGE%^Secret passageway%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This dimly lit %^BLACK%^%^BOLD%^cramped%^RESET%^%^ORANGE%^ "
"tunnel is part of a series of smuggling and escape tunnels constructed by the Tharis "
"%^RESET%^thief guild%^ORANGE%^. The tunnels are lit by %^BLACK%^%^BOLD%^torches "
"%^RESET%^%^ORANGE%^and braced by heavy wood beams. The tunnels seem to follow a path, but "
"none of the walls are straight, and its hard to tell exactly what direction you are headed "
"or how far you have actually travelled.");
    set_smell("default","%^ORANGE%^You smell sawdust.%^RESET%^");
    set_listen("default","%^RED%^The sounds of the city are muffled here.%^RESET%^");

    set_items(([
      ({"torches", "wall torches"}) : "%^RESET%^%^ORANGE%^Torches line the walls at even intervals, shedding light and flickering shadows along the passageway.%^RESET%^",
      ({"beams", "walls", "wall"}) : "%^RESET%^%^ORANGE%^The walls are supported by heavy oak beams.%^RESET%^",
    ]));
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}