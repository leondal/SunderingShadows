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
You are at walking along Goldstone Way, in the middle of a small 
residential area. A sidestreet leads to the west while the main street
continues to the north and south. You see a few houses down the road,
but there are very few people around. 
NEWBIE
   );
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly and lights your way.");
   set_listen("default","The noise of the city seems to be quieter here.");
   set_smell("default","The air is fresh and clean.");
   set_property("light",2);
   set_items(([
      "streets":"The streets are cobbled and new. They lead throughout the city.",
      "houses":"The houses are good-sized estates, surrounded by gates or fences.",
   ]));
   set_exits(([
      "north":MAINTOWN"wrstreet5",
      "south":MAINTOWN"wrstreet1",
      "west":MAINTOWN"wrstreet3",
   ]));
}

void reset(){
	::reset();
	if(!present("street_light",TO))
	new(MISCDIR+"street_light")->move(TO);
}
