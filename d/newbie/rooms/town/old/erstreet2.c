#include <std.h>
#include "../../newbie.h"

inherit INH"townmove.c";

void create() {
   ::create();
	set_terrain(CITY);
	set_travel(PAVED_ROAD);
   set_name("Starlight Avenue in Offestry");
   set_short("Starlight Avenue in Offestry");
   set_long(
@NEWBIE
You are at walking along Starlight Avenue, in the middle of a small
residential area. A sidestreet leads to the east while the main street
continues to the north and south. You see some houses along the road,
and most of the people seem to be residents of the city. 
NEWBIE
   );   
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly and lights your way.");
   set_listen("default","You hear the sounds of children playing and neighbors chatting.");
   set_smell("default","The air is fresh and clean.");
   set_property("light",2);
   set_items(([
      "streets":"The streets are cobbled and new. They lead throughout the city.",
      "houses":"The houses appear to be living space for small families. Most likely those who work in the city have their residences in this area.",
   ]));
   set_exits(([
      "north":MAINTOWN"erstreet5",
      "south":MAINTOWN"erstreet1",
      "east":MAINTOWN"erstreet3",
   ]));
}

void reset(){
	::reset();
	if(!present("street_light",TO))
	new(MISCDIR+"street_light")->move(TO);
}
