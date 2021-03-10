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
      "You are on the only southern guard tower of Tonovi.  The tower room itself is sparsely furnished, with just a cloth on poles to provice protection from the sun and rain.  You can see a lot of the Yniam plains, the emerald plains rolling in the distance."
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
	"down" : RPATH "tower5",
      ]) );
}
