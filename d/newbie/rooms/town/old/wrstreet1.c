#include "../../newbie.h"

inherit INH"townmove.c";

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Goldstone Way in Offestry");
   set_short("Goldstone Way in Offestry");
   set_long(
@NEWBIE
You are at walking along Goldstone Way, along the western border
of the city. This road leads to and from a small residential area.
A wooden palisade runs along this street. Just to the south, two
other streets meet with this one. This street is not as busy as 
others, since it is used mainly by the local residents.
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
      "north":MAINTOWN"wrstreet2",
      "south":MAINTOWN"wstreet2"
   ]));
}

void reset(){
	::reset();
	if(!present("street_light",TO))
	new(MISCDIR+"street_light")->move(TO);
}
