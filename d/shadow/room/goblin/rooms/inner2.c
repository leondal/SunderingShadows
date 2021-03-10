#include <std.h>
#include "/d/shadow/room/goblin/short.h"
inherit ROOM;
 
void create() {
  object ob;
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(DIRT_ROAD);
   set_indoors(1);
    set_property("no castle", 1);
    set_property("evil city", 1);
    set_property("light", 2);
    set_short("%^BLUE%^Goblin stronghold%^RESET%^");
    set_long( "%^BLUE%^"
        "The hallway here leads out of the stronghold to the south "
	"and into chambers to the east and west. The walls are made of stone "
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
        "west": RPATH "inner1",
	"south": RPATH "gate2",
	"east": RPATH "inner3",
    ]));
/*if (!objectp(find_object("/d/common/assassins/dryzil"))){
        find_object_or_load("/d/common/assassins/dryzil")->move(TO);
    }*/
    new("/d/shadow/room/goblin/mon/rogue")->move(TO);
//    ob->move(TO);
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
        new( MPATH "raider.c" )->move(TO);
      if(!random(10))
        new( MPATH "archer.c" )->move(TO);
    }
}
