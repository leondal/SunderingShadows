#include <std.h>
#include "../defs.h"
inherit BASE"coralmaze2";

// Coral Sea Area - Created January 2009 by Ari

void init(){
	::init();
		add_action("find_tunnel","clear");
}

void create(){
	::create();
	
		set_long(::query_long()+"%^RESET%^%^GREEN%^ One in particular "+
			"looks a bit larger then the others.  Almost like it "+
			"could be a hole of some sort.%^RESET%^");
		
		add_item(({"hole"}),"%^BOLD%^%^BLACK%^It looks like it might "+
			"be larger then you first thought.  Maybe you could clear "+
			"some seaweed out of the way and take a look.");
			
		set_exits(([
			"east":ROOMS"coral_m23"
		]));
}

int find_tunnel(string str){
	if(str == "seaweed"){
		tell_object(TP,"%^BOLD%^%^GREEN%^You pull away several clumps "+
			"of seaweed and reveal a tunnel leading downward!%^RESET%^");
		tell_room(ETP,"%^BOLD%^%^GREEN%^"+TP->QCN+" pulls at some "+
			"seaweed revealing an underground tunnel!%^RESET%^",TP);
		add_exit(ROOMS"coral_t1","tunnel");
	return 1;
	}
	tell_object(TP,"%^GREEN%^What did you want to clear?%^RESET%^");
	return 0;
}