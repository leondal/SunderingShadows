#include <std.h>
#include "../defs.h"
inherit BASE"coraltunnel";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_exits(([
			"southeast":ROOMS"coral_t3",
			"northwest":ROOMS"coral_t1"
		]));

		set_pre_exit_functions(({"southeast"}),({"GoThroughDoor"}));		
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

