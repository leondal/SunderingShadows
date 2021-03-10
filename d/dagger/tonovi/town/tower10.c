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
      "You are in the bottom of one of the guard towers on the walls of Tonovi.  In this room there is a large table and chairs around it with a deck of cards sitting in the middle.  To the north along one of the circular walls rests a staircase rising up onto the floor above you."
    );
    set_smell("default", "The smells of old refuse and the stench of the city sit on the unmoving air.");
    set_listen("default", "You hear the wail of orphaned children as they beg for alms.");

    set_items( ([
	"stones" : "These great stones must have traveled a great distance to be placed here.",
	"table" : "This great table is made with oak, and has many markings from the abuse given by the guards.",
	"chairs" : "These chairs are old and severly beaten.",
	"cards" : "Hmmm...  5 aces on the table.  Someone had a problem.",
	"staircase" : "This staircase leads up through the ceiling and onto the archers posts.",
      ]) );

    set_exits( ([

	"southeast" : RPATH "wall16",
	"up" : RPATH "tower10b",
      ]) );
}

void reset() {
  ::reset();
}