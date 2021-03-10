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
        "You stand within the gatehouse "
	"of the %^MAGENTA%^Goblin stronghold%^BLUE%^. "
	"The gates to the south are open and even if they "
	"were closed and locked, they dont look like they could keep "
	"much in or out. The walkway through the stronghold's large "
	"walls lead off to the east and the west and you "
        "see no other means of gaining access to the interior of the "
	"stronghold other than "
	"the hall to the north."
        "%^RESET%^"
    );
    set_smell("default","It smells of dirty goblins.");
    set_items(([
        "torches":"The flickering torches provide some light.",
        "walls":"The walls are made of stone.",
        "gates":"The gates lay open to the south.",
    ]));
    set_exits(([
        "north": RPATH "inner2",
	"south": RPATH "gate1",
	"east": RPATH "arch11",
	"west": RPATH "arch1",
    ]));
}
void reset() {
    ::reset();
    if(!present("goblin")) {
        new( MPATH "soldier.c" )->move(TO);
        new( MPATH "soldier.c" )->move(TO);
        if(!random(4))
           new( MPATH "keeper.c" )->move(TO); 
    }
}
