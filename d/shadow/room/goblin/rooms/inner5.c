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
        "The hallway here leads to a chamber to the north "
        "and into halls to the east and the west. The walls are made of stone and "
        "have flickering torches hanging from them. A large red banner hangs "
	"on the south wall."
        "%^RESET%^"
    );
    set_smell("default","It smells of dirty goblins.");
    set_listen("default","You hear the occasional goblin shouting somewhere in "
	"the stronghold.");
    set_items(([
        "torches":"The flickering torches provide some light.",
        "walls":"The walls are made of stone.",
	"banner":"The banner bears the symbol of the Goblin army of Chaos.",
    ]));
    set_exits(([
        "north": RPATH "inner8",
	"west": RPATH "inner4",
	"east": RPATH "inner6",
    ]));
}

void reset() {
    ::reset();
    if(!random(2))
    if(!present("goblin")) {
        new( MPATH "royal.c" )->move(TO);
	     new( MPATH "royal.c" )->move(TO);
	     if(!random(10))
	       new( MPATH "royal.c" )->move(TO);
	     if(!random(10))
          new( MPATH "raider.c" )->move(TO);
    }
}
