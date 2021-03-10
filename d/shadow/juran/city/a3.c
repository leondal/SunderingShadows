//Coded by Diego//

#include <std.h>
#include "../juran.h"
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
		"were to have set a trap for you.  In the southwest corner you see "+
		"a crack in the wall and darkness looms behind it.\n"+
		"%^RESET%^"
    	);
	set_property("indoors",0);
	set_property("light",-3);
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
			"alley accumlates along the walls.\n",
		"crack" : "You can see it may lead somewhere but is well concealed."
         	]));
    	set_exits(([
   		"east" : JROOMS+"a2",
		"crack" : JROOMS+"tg1"
    	]));
	set_search("crack","You search the crack carefully and realize "
		"that it's larger than you thought but well concealed, "
		"likely for a reason you may not want to know.\n");

/*	set_search("crack","You search the crack carefully and determine "+
		"that only someone very flexible and dexterious should be "+
		"able to squeeze through that opening.\n");
*/
    	set_invis_exits( ({"crack"}) );
//    	set_pre_exit_functions(({"crack"}),({"allow"}));
}

int allow(){
      if(TP->is_monster()) return 0;
/*
    	if(!TP->is_class("thief") && !TP->is_class("bard") && !avatarp(TP)){
        	tell_object(TP,"You try hard as you can to squeeze into the crack, "+
        		"but for some reason you get nowhere.\n");
        	tell_room(TO,TPQCN+" attempts to squeeze through a crack in the "+
        		"stone wall, but cannot seem to fit inside.",TP);
        	return 0;
    	}
    	tell_object(TP, "As you bend and squeeze your body into the small "+
    		"crack you feel it give way to accomodate you regardless of your size.");
*/
    	tell_object(TP, "You make your way carefully through the crack.");
    	tell_room(ETP, TPQCN+" manages to get through what looks like a small crack.", TP);
    	return 1;
}
