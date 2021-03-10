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
        "The hallway here leads to a chamber to the south "
	"and into a hall to the west. The walls are made of stone "
	"have flickering torches hanging from them. "
        "%^RESET%^"
    );
    set_smell("default","It smells of dirty goblins.");
    set_listen("default","You hear the occasional goblin shouting somewhere in "
	"the stronghold.");
    set_items(([
        "torches":"The flickering torches provide some light.",
        "walls":"The walls are made of stone.",
    ]));
    set_exits(([
        "south": RPATH "inner3",
	"west": RPATH "inner5",
    ]));
}
void reset() {
    ::reset();
    if(!random(3))
    if(!present("goblin")) {
        new( MPATH "soldier.c" )->move(TO);
        new( MPATH "footman.c" )->move(TO);
      if(!random(3))
        new( MPATH "soldier.c" )->move(TO);
      if(!random(8))
        new( MPATH "footman.c" )->move(TO);
      if(!random(10))
        new( MPATH "raider.c" )->move(TO);
    }
}
