#include <std.h>
#include "juran.h"
inherit VAULT;

void create(){
::create();
    	set_name("overgrown park");
	set_short("overgrown park");
	set_long(
    		"%^RESET%^%^GREEN%^"+
		"This area in the center of the town must have been a park at one "+
		"time, but looking at it now it is hard to picture the way it must "+
		"have looked when it was green.  Broken stone statues lie amongst "+
		"the tall weeds.  Trees that once provided shade now grow crooked "+
		"and stunted with few leaves poking out through the thorny vines "+
		"that seem to strangle the once verdant plants.  In the center of "+
		"the park you can see the remains of a fountain rising up through "+
		"the horrid weeds and vines.\n"+
		"%^RESET%^"
    	);
	set_property("indoors",0);
	set_property("light",1);
    	set_terrain(LIGHT_FOREST);
    	set_travel(FOOT_PATH);
	set_smell("default","The smell of decay and ruin permeates the air.");
	set_listen("default","It is as quiet as death except for a gurgling "+
		"you can hear from the fountain in the center of the park.");
	set_items(([
      	({"statues","statue"}) : "Broken pieces of what must have been "+
      		"statues, pillars and benches lie amoungst the tall weeds.\n",
		({"weed","weeds"}) : "Weeds and other vegetation poke up from the "+
			"cracks in the road.\n",
		({"vines","vine","thorns","thorn"}) : "Wicked thorns poke out "+
			"menacingly from the vines that cover the tree trunks and ground.\n"
        	]));
}
