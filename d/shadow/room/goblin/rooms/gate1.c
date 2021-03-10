#include <std.h>
#include "/d/shadow/room/goblin/short.h"
inherit ROOM;
 
void create() {
    ::create();
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
    set_property("no castle", 1);
    set_property("light", 2);
    set_short("%^BLUE%^Goblin stronghold%^RESET%^");
    set_long( "%^BLUE%^"
        "You stand before a large set of gates leading into the front "
	"of the %^MAGENTA%^Goblin stronghold%^BLUE%^. "
	"The gates are open and even if they "
	"were closed and locked, they dont look like they could keep "
	"much out. The large walls lead off to the east and the west and you "
        "see no other means of gaining access to the stronghold other than "
	"the gate to the north. Small mini-towers dot the upper levels of the "
	"walls and you notice small windows with shadowed shapes passing in "
	"front of the windows."
    "\n%^BOLD%^%^RED%^Off in the distance, you hear the horrible laughter of Grazzt echo through the forest."
        "%^RESET%^"
    );
    set_smell("default","It smells of dirty goblins.");
    set_items(([
        "torches":"The flickering torches provide some light.",
        "walls":"The walls are made of stone and have a series of towers "
	"located on top of them.",
        "towers":"The small towers are used by Goblin archers to shoot "
	"attackers of the stronghold.",
        "gates":"The gates lay open to the north.",
    ]));
    set_exits(([
        "north": RPATH "gate2",
		"northwest":"/d/darkwood/tabor/road/road3",
    ]));
}

void reset() {
    ::reset();
    if(!present("goblin")) {
        new( MPATH "keeper.c" )->move(TO);
        new( MPATH "keeper.c" )->move(TO);
        if(!random(4))
           new( MPATH "keeper.c" )->move(TO);
    }
}
