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
A wooden palisade runs along the road.  This street has a few offices and businesses but is not as busy as those toward the more traveled parts of the city.  The shop on the south side of the street does not seem to have much traffic but a %^GREEN%^sign %^RESET%^swings in the light breeze.  A man peeks his head out of the door looking around expectantly from time to time.
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
      "sign":"The sign looks to be fairly new and has %^GREEN%^Dulan's Scribe Shop%^RESET%^ written in many different languages, if some can be called writing.",
   ]));
   set_exits(([
      "west":MAINTOWN"erstreet8",
      "east":MAINTOWN"erstreet6",
      "south":MAINTOWN"scribe",
   ]));
}

void reset(){
	::reset();
	if(!present("street_light",TO))
	new(MISCDIR+"street_light")->move(TO);
}
