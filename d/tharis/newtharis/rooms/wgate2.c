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
    set_long("%^RESET%^%^BOLD%^%^BLACK%^City walls rise up high above you."+
" The walls themselves are old, made up from giant blocks of %^RESET%^%^WHITE%^granite"+
" %^RESET%^%^BOLD%^%^BLACK%^cut and placed carefully. Age has worn the stones smooth "+
"and there is no purchase to climb. There are signs of repaired damage though, as some"+
" spots are li%^RESET%^%^WHITE%^g%^RESET%^%^BOLD%^%^BLACK%^hte%^RESET%^%^WHITE%^r%^RESET%^"+
"%^BOLD%^%^BLACK%^ than others. A narrow %^RESET%^%^ORANGE%^path %^RESET%^%^BOLD%^%^BLACK%^"+
"runs along the wall, most likely used by guards on patrol or those who want to avoid the "+
"bustle of the city. %^RESET%^%^GREEN%^Spar%^RESET%^%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^e "+
"v%^RESET%^%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^getation %^RESET%^%^BOLD%^%^BLACK%^fights "+
"for survival along the base of the wall. A giant %^RESET%^%^ORANGE%^set of gates%^BLACK%^"+
"%^BOLD%^ lead into the city.%^RESET%^\n");
    set_smell("default","%^RESET%^%^ORANGE%^The air carries a thousand scents of a busy city.%^RESET%^");
    set_listen("default","%^BLACK%^%^BOLD%^You hear the bustle of the city.");
    set_exits(([
      "east" : ROOMS"wgate1",
      "north" : ROOMS"wall36",
      "west" : "/d/tharis/road/wroad2",
      "up" : ROOMS"west_tower",
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
    if(!present("golem")){new(MOBS"bladegolem.c")->move(TO);}
}