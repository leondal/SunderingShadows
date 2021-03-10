#include "../../newbie.h"

inherit INH"townmove.c";

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Highspire Avenue in Offestry");
   set_short("Highspire Avenue in Offestry");
   set_long(
@NEWBIE
You are walking along Highspire Avenue, the northern border of the city.
A wooden palisade runs along the road. On the south side of the street
is a small building with few windows.
NEWBIE
   );
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly and lights your way.");
	set_listen("default","You hear snatches of conversation from passersby.");
   set_smell("default","The air is fresh and clean.");
   set_property("light",2);
   set_items(([
      "streets":"The streets are cobbled and new. They lead throughout the city.",
      "palisade":"The palisade stands around 12 feet high, surrounding the city. You notice a few archers and guardsman patrolling.",
   ]));
   set_exits(([
      "east":MAINTOWN"wrstreet8",
      "west":MAINTOWN"wrstreet6",
      "south":MAINTOWN"library",
   ]));
}

void reset(){
	::reset();
	if(!present("street_light",TO))
	new(MISCDIR+"street_light")->move(TO);
}
