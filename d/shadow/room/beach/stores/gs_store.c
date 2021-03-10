#include "zeek.h"
#include <daemons.h>

inherit ROOM;

void create() {
    ::create();
    set_light(2);
    set_indoors(1);
    set_short("Beach General Store");
    set_long(
" "
"You are in a large gerneral store.  "
"There are many things on the walls.  "
"Youw would mostly use these things for fun adventures. You can <buy> "
"or <sell> items here. Behind the counter is Jeff, the clerk."
""
);

    set_items(
	(["shop" : "This is the Beach Gerneral Store.",
      "store" : "You can buy and sell things here.",
	  "counter" : "The counter has several things sitting on it.",
	  "shelves" : "The shelves are stocked with goods."]) );
    set_exits( 
	      (["out"	: "/d/shadow/room/beach/park1"]) );
    set_property("no castle", 1);
    set_smell("default","The smell new and used goods.");
    set_listen("default","You hear talking about prices going on all over.");
 }


void init(){
      ::init();
      if(!present("jeff",TO))
              new("/d/shadow/room/beach/mon/jeff.c")->move(TO);

}
