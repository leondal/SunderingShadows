#include <std.h>
#include "../tharis.h"
inherit CROOM;

void create(){
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",0);
    set_property("light",2);
    set_name("City Gates");
    set_short("%^RESET%^%^ORANGE%^City Gates%^RESET%^");
    set_long("%^RESET%^%^BOLD%^%^BLACK%^City walls rise up high above you. "
"The walls themselves are old, made up from giant blocks of %^RESET%^%^WHITE%^granite "
"%^BOLD%^%^BLACK%^cut and placed carefully. Age has worn the stones smooth "
"and there is no purchase to climb. There are signs of repaired damage though, as "
"some spots are li%^RESET%^%^WHITE%^g%^BOLD%^%^BLACK%^hte%^RESET%^%^WHITE%^r"
"%^BOLD%^%^BLACK%^ than others. A narrow %^RESET%^%^ORANGE%^path %^BOLD%^%^BLACK%^"
"runs along the wall, most likely used by guards on patrol or those who want to avoid "
"the bustle of the city. %^RESET%^%^GREEN%^Spar%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^e "
"v%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^getation %^BOLD%^%^BLACK%^fights for survival "
"along the base of the wall. A giant %^RESET%^%^ORANGE%^set of gates%^BOLD%^%^BLACK%^ "
"lead into the city.%^RESET%^\n");
    set_smell("default","%^RESET%^%^ORANGE%^The air carries a thousand scents of a busy city.%^RESET%^");
    set_listen("default","%^BOLD%^%^BLACK%^This side of the city is uncommonly quiet.%^RESET%^");

    set_exits(([
      "east" : "/d/tharis/road/eroad2",
      "west" : ROOMS"egate1",
      "north" : ROOMS"wall22",
    ]));
    set_items (([
      "vegetation" : "%^RESET%^%^GREEN%^Small shrubs and sparse grass fight for survival.%^RESET%^",
      "walls" : "%^BLACK%^%^BOLD%^The walls themselves are old, made up from giant blocks of "
"granite cut and placed%^RESET%^ carefully%^BOLD%^%^BLACK%^.%^RESET%^",
      "gates" : "%^BLACK%^%^BOLD%^Giant gates are held open, yet could lock down to close down the city.%^RESET%^",
    ]));
}

void reset(){
    ::reset();
    if(!present("golem")){new("/d/tharis/newtharis/mobs/bladegolem.c")->move(TO);}
}
