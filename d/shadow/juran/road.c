#include <std.h>
#include "juran.h"
inherit VAULT;

void create(){
::create();
    	set_name("ruined road");
	set_short("ruined road");
	set_long(
    		"%^RESET%^%^ORANGE%^"+
		"The once fine road now lies broken before you.  It is obvious that "+
		"the road was once well travelled and well kept, but now weeds grow "+
		"up through the cracks and great chunks of the stone stand pointing "+
		"to the sky.  Wheeled vehicles would find large portions of this "+
		"road unpassable.\n"+
		"%^RESET%^"
    	);
	set_property("indoors",0);
	set_property("light",1);
    	set_terrain(SCRUB_LANDS);
    	set_travel(RUTTED_TRACK);
	set_smell("default","The smell of decay and ruin permeates the air.");
	set_listen("default","It is as quiet as death along this portion of the road.");
	set_items(([
      	"road" : "Broken in more places than than iit is whole, the road "+
      		"only meets the definition of a road through its past use.\n",
		({"weed","weeds"}) : "Weeds and other vegetation poke up from the "+
			"cracks in the road.\n",
		({"stones","stone","chunks","chunk"}) : "Great pieces of the road "+
			"jut from the ground as if thrown up by some great force only "+
			"to settle back on its ends.\n"
        	]));
}
