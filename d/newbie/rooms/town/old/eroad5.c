#include <std.h>
#include "../../newbie.h"
inherit INH"townmove.c";

void create() {
   ::create();
	set_terrain(CITY);
	set_travel(PAVED_ROAD);
   set_name("Shale Street in Offestry");
   set_short("Shale Street in Offestry");
   set_long(
@NEWBIE
You are walking along Shale Street, the southern border of the city. 
A wooden palisade runs along this street. You see many people, both citizens and travelers, walking and riding to their destinations. 
NEWBIE
   );   
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly and lights your way.");
   set_listen("default","You hear snatches of conversation from passersby.");
   set_smell("default","The air is fresh and clean.");
   set_property("light",2);
   set_items(([
      "streets":"The streets are cobbled and new. They lead throughout the city.",
      "buildings":"The buildings are a jumble of style and types. They hold the citizens, businesses and adventure of this small city.",
      "palisade":"The palisade stands around 12 feet high, surrounding the city. You notice a few archers and guardsman patrolling.",
   ]));
   set_exits(([
      "east":MAINTOWN"eroad4",
      "west":MAINTOWN"eroad6",
   ]));
}

void reset(){
	::reset();
	if(!present("street_light",TO))
	new(MISCDIR+"street_light")->move(TO);
}
