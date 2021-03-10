
#include <std.h>
#include "/d/shadow/room/shadow.h"

inherit "/d/shadow/room/inherits/owagon.c";

void create(){
    ::create();
	set_long(
"%^GREEN%^An old wagon trail%^RESET%^\n%^ORANGE%^This old wagon "+ 
"%^WHITE%^trail%^ORANGE%^ leads north and east through the rocky "+ 
"terrain that makes up the foot hill area south and east of the "+ 
"joint between the Echoes Mountains and the Charu Mountains. "+ 
"This rocky rutted trail has seen little use. Obviously once a "+ 
"smugglers wagon trail blazed to bypass the tariffs found in "+ 
"Shadow City. Now those traveling here risk bandits and worse, "+ 
"for this is obviously not patrolled. You notice that the "+ 
"%^BOLD%^%^BLACK%^boulders%^RESET%^%^ORANGE%^ and %^GREEN%^scrub%^ORANGE%^ "+ 
"forest growth provide ample ambush opportunity. A clump of bushes here "+ 
"seems particularly thick.\n%^RESET%^");
    set_items(([
        "boulders": "These large rocks jut up from the ground. Some are quite large.",
        "scrub": "These smaller hardy trees have not achieved the size of those farther south but have managed to form thick copses.",
		"trail" : "That's about all it is now.  The ruts from the travel of many wagons remain among the rocks and make travel somewhat difficult.",
		"bushes" : "They seem to grow thicker here than in other places along the trail.",
			   ]));
	set_search("bushes","You poke around in the bushes and find a narrow hole in the ground that you might be able to enter.");
    set_exits(([
               "southwest":FORESTDIR+"owagon37",
               "east":PASSDIR+"pass6",
               ]));
}

void init() {
  	::init();
  	add_action("enter","enter");
}

int enter(string str){
  	if(str == "hole" || str == "the hole"){
	tell_object(TP,"%^RESET%^%^ORANGE%^You take a deep breath and squeeze yourself into the narrow hole, descending into a dark tunnel.%^RESET%^\n");
	tell_room(ETP,"%^RESET%^%^ORANGE%^"+TPQCN+" clambers down into a hole hidden within the thick bushes.%^RESET%^",TP);
	TP->move_player("/d/shadow/city/room/dirttunnel1");
	}
}