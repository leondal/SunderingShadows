#include <std.h>
#include "../defs.h"
inherit BASE"coraltunnel";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_exits(([
			"east":ROOMS"coral_t4",
			"northwest":ROOMS"coral_t2"
		]));

		set_pre_exit_functions(({"east"}),({"GoThroughDoor"}));		
}

int GoThroughDoor(){
	object ob;
	if(!TP->query_true_invis()){
		if(TP->query_highest_level()<=25){
		
		tell_object(TP,"%^BOLD%^%^WHITE%^A flood of %^CYAN%^"+
			"bubbles%^WHITE%^ burbles up through the "+
			"tunnel, pushing you backwards.  You start to "+
			"wonder if going this way is such a good "+
			"idea!%^RESET%^");
		}
	}
	return 1;
}
