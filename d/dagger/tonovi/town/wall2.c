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
      "You are in one of the passageways of the walls circling the city.  To the south the passage continues, and to the southeast one of the lookout towers rest.  The walls themselves are made of stone with wooden planks above you for the archers to stand on.",
    );
    set_smell("default", "The smells of old refuse and the stench of the city sit on the unmoving air.");
    set_listen("default", "You hear the wail of orphaned children as they beg for alms.");

    set_items( ([
	"stones" : "These great stones must have traveled a great distance to be placed here.",
	"planks" : "These planks are there for the archers to stand on while shooting at attackers.",
      ]) );

    set_exits( ([
	"south" : RPATH "wall1",
	"southeast" : RPATH "tower2",
      ]) );
}
