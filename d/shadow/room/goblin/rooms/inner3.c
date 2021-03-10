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
        "You stand within a dirty soldier's sleeping chambers. There is a "
	"hall to the west and a opening to the north. Dirty straw mats adorn "
	"the stone chamber. A table lays in the center of the chamber. "
	"The walls are made of stone and have flickering torches hanging from them. "
        "%^RESET%^"
    );
    set_smell("default","It smells of rotting food.");
    set_listen("default","You hear the occasional goblin shouting somewhere in "
	"the stronghold.");
    set_items(([
        "torches":"The flickering torches provide some light.",
        "walls":"The walls are made of stone.",
	"table":"The table stands in the center of the room.",
	"mats":"The straw mats are likely used by goblins to sleep upon."
    ]));
    set_exits(([
        "west": RPATH "inner2",
	"north": RPATH "inner6",
    ]));
}
void reset() {
    ::reset();
    if(!random(3))
    if(!present("goblin")) {
        new( MPATH "soldier.c" )->move(TO);
        new( MPATH "soldier.c" )->move(TO);
      if(!random(3))
        new( MPATH "soldier.c" )->move(TO);
      if(!random(5))
        new( MPATH "royal.c" )->move(TO);
      if(!random(10))
        new( MPATH "raider.c" )->move(TO);
    }
}
