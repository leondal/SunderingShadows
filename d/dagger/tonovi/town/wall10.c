#include <std.h>
#include "/d/dagger/tonovi/town/short.h"

inherit MAIN; 

void create(){
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_room_type("walls");
    set_short("In the walls of Tonovi");
    set_long(
      "You are in the passageways that lead through the walls of Tonovi.  In some places you can see where the outer walls have been attacked and repaired, but the city itself has withstood great sieges.  The walls themselves are made of stone with wooden planks above your head for the archers to walk on when patrolling the area."
      +"  From here you can see guard towers to the southeast, southwest and northwest.  To the east and north the passageways continue through the walls.  To the northeast through the gates is the town square."
    );
    set_smell("default", "The smells of old refuse and the stench of the city sit on the dead air.");
    set_listen("default", "You hear the wail of orphaned children as they beg for alms.");

    set_items( ([
	({"stone", "stones"}) : "The stones here range in size and weight, but they all look as if they must have come from a great distance.",
	"planks" : "These wooden planks rest on crossbeams in the walls and allow the guards and archers to patrol the tops of the walls.",
	({"tower", "towers"}) : "These are the guard towers in place to try to discourage invaders from attacking the walls of the city.",
      ]) );

    set_exits( ([
	"east" : RPATH "wall9",
	"north" : RPATH "wall11",
	"northeast" : RPATH "bazaar7",
	"northwest" : RPATH "tower8", 
	"southwest" : RPATH "tower7",
	"southeast" : RPATH "tower6",
      ]) );

}
