#include <std.h>
#include "../defs.h"
inherit BASE"coralsea1";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_long(::query_long()+"%^BOLD%^%^CYAN%^ Only the %^RESET%^"+
			"%^ORANGE%^coral%^CYAN%^%^BOLD%^ covered structure to the "+
			"south offers any point of reference out in this vast "+
			"nothingness.%^RESET%^");

		set_exits(([
			"southeast":ROOMS"coral_s3",
			"southwest":ROOMS"coral_s2"
		]));
}

void reset(){
	switch(random(10)){
		case 0..4:
			tell_room(TO,"%^BOLD%^%^WHITE%^A rush of bubbles "+
				"rushes upward from deep below the sea.%^RESET%^");
		break;
		case 5..9:  
			tell_room(TO,"%^BOLD%^%^CYAN%^A natural gas vent "+
				"deep under the sea spills a burst of bubbles."+
				"%^RESET%^");
		break;
   }
}