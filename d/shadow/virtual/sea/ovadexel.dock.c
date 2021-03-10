//dock.c
//Ovadexel Dock - Cythera 
#include <std.h>
#include "/d/islands/dreams/defs.h"

inherit DOCK;

void create(){ 
 	::create();
   	set_property("light",2);
   	set_property("no teleport",1);
  	set_terrain(BARREN);
  	set_travel(DECAYED_FLOOR);
	set_climate("tropical");
   	set_short("%^BOLD%^The Dock of Ovadexel");

   	set_long("%^CYAN%^An old battered dock juts out of a small island."+
		"  The dock seems as if it has not been used in some time."+
		"  The weathered wood in some spots looks to have rotted "+
		"away, giving it an apperance as if it might collapse at "+
		"any moment.  The white sand beaches of the island look "+
		"inviting.\n");
	set_smell("default","%^BOLD%^%^CYAN%^The salty ocean air fills"+
		" your senses.");
   	set_listen("default","%^BOLD%^%^BLUE%^The waves lap up against"+
		" the shore.");
   set_items(([
      "ocean":"%^CYAN%^Waves roll across the azure colored sea as far"+
		" as your eyes can see.",
      "dock":"The dock looks unsafe and abandonded.",
   ]));

   set_exits(([
      "east":ROOMDIR"island1",
   ]));

 }
