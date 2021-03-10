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
      "You are standing in the passageways of the walls circling the city.  To the southwest are the main gates.  To the north the passage continues a short distance.  The walls themselves are made of thick stone, with wooden planks above you for the archers to stand on."
    );
    set_smell("default", "The smells of old refuse and the stench of the city sit on the unmoving air.");
    set_listen("default", "You hear the wail of orphaned children as they beg for alms.");

    set_items( ([
	"stones" : "These great stones must have traveled a great distance to be placed here.",
	"planks" : "These planks are there for the archers to stand on while shooting at attackers.",
      ]) );

    set_exits( ([
	"southwest" : RPATH "maingate",
	"south" : RPATH "tower1",
	"north" : RPATH "wall2",
      ]) );
}

void reset() {
  ::reset();
}