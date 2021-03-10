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
A wooden palisade runs along the road. This street has a few offices and businesses but is not as busy as those toward the more traveled parts of the city. The side of a building is to the south of the road. Just to the west, another street crosses this one.  
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
   ]));
   set_exits(([
      "west":MAINTOWN"nstreet4",
      "east":MAINTOWN"erstreet8",
   ]));
}

void reset(){
	::reset();
	if(!present("street_light",TO))
	new(MISCDIR+"street_light")->move(TO);
}
