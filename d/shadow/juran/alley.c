#include <std.h>
#include "juran.h"
inherit VAULT;

void create(){
::create();
    	set_name("alley");
	set_short("alley");
	set_long(
    		"%^RESET%^%^ORANGE%^"+
		"This road is flanked on both sides by the remains of the walls of "+
		"the ruined buildings.  It is dark here and debris has accumulated "+
		"along the ground.  This alley could be a dangerous place if someone "+
		"were to have set a trap for you.\n"+
		"%^RESET%^"
    	);
	set_property("indoors",0);
	set_property("light",1);
    	set_terrain(CITY);
    	set_travel(BACK_ALLEY);
	set_smell("default","The smell of decay and rotted wood fills the air.");
	set_listen("default","Aside from the wind blowing through the alley it is "+
		"as quiet as death.");
	set_items(([
          ({"wall","walls"}) : "More wall is in rubble at your feet than "+
      		"is still standing.\n",
		({"weed","weeds","mold"}) : "Weeds, mold, and other vegetation poke "+
			"up from the rotting wood and crumbling stone.\n",
		({"stones","stone","chunks","chunk"}) : "Much of the stone comes "+
			"from the collapsed walls and ceiling.\n",
		"debris" : "Trash and dead vegetation that has blown into the "+
			"alley accumlates along the walls.\n"
         	]));
}
