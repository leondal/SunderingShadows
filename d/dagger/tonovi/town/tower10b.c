#include <std.h>
#include "/d/dagger/tonovi/town/short.h"

inherit MAIN;

void create(){
    ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_short("In the walls of Tonovi");
    set_room_type("walls");
    set_long(
   "This guard tower guards the northwest corner of the town.  Below you to the west is the small yet well used road that travels to the Duke's keep a short distance to the northwest.  You can see another tower on the other side of the road.  A cloth stretched across some poles is the only visible furnishings here."
    );
    set_smell("default", "The smells of old refuse and the stench of the city sit on the unmoving air.");
    set_listen("default", "You hear the wail of orphaned children as they beg for alms.");

    set_items( ([
	"stones" : "These great stones must have traveled a great distance to be placed here.",
	"staircase" : "This staircase leads up through the ceiling and onto the archers posts.",
	"gates" : "The great gates stand open ready to be closed in an instant to defend the city.",
	"cloth" : "This thick waterproof fabric is held up on four poles to provide the archers with some protection from the elements.",
	"hills" : "The emerald hills of the plains roll off into the distance.",
      ]) );

    set_exits( ([
	"down" : RPATH "tower10",
      ]) );
}
