#include <std.h>
#include "../defs.h"
inherit BASE"coraltunnel";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_exits(([
			"north":ROOMS"coral_m22",
			"southeast":ROOMS"coral_t2"
		]));
		set_pre_exit_functions(({"southeast"}),({"GoThroughDoor"}));		
}

int GoThroughDoor(){
	object ob;
	if(!TP->query_true_invis()){
		if(TP->query_highest_level()<=25){
		
		tell_object(TP,"%^BOLD%^%^WHITE%^A flood of %^CYAN%^"+
			"bubbles%^WHITE%^ burbles up through the "+
			"tunnel, pushing you backwards.  A shiver of "+
			"dread passes through you!  You feel yourself "+
			"becoming unsettled as you look about this "+
			"narrow space and wonder what might be lurking "+
			"further on.  Maybe you should think about "+
			"turning back.  Surly this can't be what you're "+
			"searching for... %^RESET%^");
		}
	}
	return 1;
}
