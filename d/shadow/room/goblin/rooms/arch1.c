#include <std.h>
#include "/d/shadow/room/goblin/short.h"

inherit ROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(DIRT_ROAD);
    set_indoors(1);
    set_property("no castle", 1);
    set_property("light", 2);
    set_short("%^BLUE%^Goblin stronghold%^RESET%^");
    set_long( "%^BLUE%^"
        "You stand in a lower chamber within the protective walls "
	"of the Goblin stronghold. The inner walls are made of stone. Small "
	"flickering torches hang from the walls.  %^RED%^Blood%^BLUE%^ is "
	"splattered everywhere as though there have been many fierce battles "
	"waged here.%^RESET%^"
    );
    set_smell("default","You smell the stench of goblins.");
    set_listen("default","You hear high pitched chatter echo off the walls.");
    set_items(([
        "torches":"The flickering torches provide some light.",
        "walls":"The walls are made of stone.",
    ]));
    set_exits(([
        "up": RPATH "tower1",
	     "east": RPATH "gate2",
	     "northwest": RPATH "arch2",
    ]));
}

void reset()
{
    ::reset();
    if (!present("goblin")) {
        switch (random(8)) {
        case 0: new(MPATH "raider.c")->move(TO);
        case 1: new(MPATH "footman.c")->move(TO);
        case 2..4: new(MPATH "footman.c")->move(TO);
        case 5..6: new(MPATH "footman.c")->move(TO);
            break;
        case 7: new(MPATH "witch.c")->move(TO);
        }
    }
}
