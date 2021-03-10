/*changed to use set_search instead of add action.  Error corrected so that it would not keep scrolling and ask "what?" (it was returning 0 on the search.  Circe 10/21/03 */
//Coded by Diego//
// opened up to non-magi *Styx* 2/10/06


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
		"were to have set a trap for you.  The north wall is curiously still "+
		"standing complete and free of debris.\n"+
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
      		"is still standing.  The north wall stands complete and "+
      		"strong and is free of debris at its base.\n",
      	"north wall" : "The north wall looks complete and strong.  No "+
      		"debris has accumulated at its base.",
		({"weed","weeds","mold"}) : "Weeds, mold, and other vegetation poke "+
			"up from the rotting wood and crumbling stone.\n",
		({"stones","stone","chunks","chunk"}) : "Much of the stone comes "+
			"from the collapsed walls and ceiling.\n",
		"debris" : "Trash and dead vegetation that has blown into the "+
			"alley accumlates along the walls.\n"
         	]));
    	set_exits(([
   		"portal" : JROOMS+"mt1",
   		"south" : JROOMS+"a8"
    	]));

    	set_invis_exits( ({"portal"}) );
//    	set_pre_exit_functions(({"portal"}),({"allow"}));
      set_search("north wall", (: TO, "search_wall" :) );  //added to use search function Circe 10/21/03
}
/*
void init() {
  	::init();
  	add_action("search","search");
}
Not needed any longer.  Circe 10/21/03
*/

void reset() {
   ::reset(); 
   write("%^BOLD%^%^BLUE%^You notice a slight glimmer from the north wall.\n%^RESET%^");
}
	

void search_wall(){
/*
    		if(!TP->is_class("mage") && !TP->is_class("bard") && !avatarp(TP)){
        		tell_object(TP,"You examine the north wall carefully and see "+
        			"nothing other than a stone wall.\n");
        		tell_room(TO,TPQCN+" searches the north wall carefully.",TP);
        		return 1;
    		}
*/
	tell_object(TP,"You see the glimmer of a darkly shimmering portal "+
		"to the north.\n");
	tell_room(TO,TPQCN+" searches the north wall carefully.",TP);
	return 1;
}

/* no longer used
int allow(){
    	if(!TP->is_class("mage") && !TP->is_class("bard") && !avatarp(TP)){
        	tell_object(TP,"You try to go north and smack into a wall.\n");
        	tell_room(TO,TPQCN+" attempts to walk through a stone wall, but "+
        		"bounces painfully off the wall.",TP);
        	return 0;
    	}
    	tell_object(TP, "You enter a darkly shimmering portal to the north.");
    	tell_room(ETP, TPQCN+" steps into the north wall and disappears.", TP);
    	return 1;
}
*/