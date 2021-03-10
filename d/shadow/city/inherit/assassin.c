#include <std.h>
#include "../defs.h"

inherit ROOM;


void create(){
    ::create();
    set_indoors(1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_climate("temperate");
    set_property("light", 2);
    set_name("Shadow's Assassin Guild");
}
