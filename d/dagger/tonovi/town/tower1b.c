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
      "You are on the top floor of one of the two guard towers overlooking the gates to the city.  From here the archers can rain down arrows on attackers in relative safety from the stone structures built to protect them.  There is not much to this room, a small cloth on poles to give shelter from the sun and rain is about all that is here."
    );
    set_smell("default", "The smells of old refuse and the stench of the city sit on the unmoving air.");
    set_listen("default", "You hear the wail of orphaned children as they beg for alms.");

    set_items( ([
	"stones" : "These great stones must have traveled a great distance to be placed here.",
	"staircase" : "This staircase leads up through the ceiling and onto the archers posts.",
	"gates" : "The great gates stand open ready to be closed in an instant to defend the city.",
	"cloth" : "This thick waterproof fabric is held up on four poles to provide the archers with some protection from the elements.",
      ]) );

    set_exits( ([
	"down" : RPATH "tower1",
      ]) );
}
