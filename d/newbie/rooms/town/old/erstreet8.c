#include <std.h>
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
A wooden palisade runs along the road.  This street has a few offices and businesses but is not as busy as those toward the more traveled parts of the city.  A %^ORANGE%^large man %^RESET%^keeps an eye on you as you look over the shop on the south side of the street.
NEWBIE
   );   
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly and lights your way.");
   set_listen("default","You hear snatches of conversation from passersby.");
   set_smell("default","The air is fresh and clean.");
   set_property("light",2);
   set_items(([
      "streets":"The streets are cobbled and new. They lead throughout the city.",
      "palisade":"The palisade stands around 12 feet high, surrounding the city. You notice a few archers and guardsman patrolling.",
      "buildings":"The buildings are a jumble of style and types. They hold the citizens, businesses and adventure of this small city.",
      ({"large man", "man"}):"The man is a guard for the jewelry shop. You figure that he could make just about anyone think twice about stealing.",
   ]));
   set_exits(([
      "west":MAINTOWN"erstreet9",
      "east":MAINTOWN"erstreet7",
      "south":MAINTOWN"jeweler",
   ]));
}

void reset(){
	::reset();
	if(!present("street_light",TO))
	new(MISCDIR+"street_light")->move(TO);
}
