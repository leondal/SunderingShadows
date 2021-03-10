#include <std.h>
#include "../defs.h"
inherit BASE"coraltunnel";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
	
		set_long("%^BOLD%^%^WHITE%^You exit the tunnel to find "+
			"yourself in a large %^CYAN%^bubbling chamber%^WHITE%^.  "+
			"All around you the rush of %^BLACK%^natural gases "+
			"%^WHITE%^rise up from small %^BLACK%^vents %^WHITE%^in "+
			"the chamber's floor.  %^CYAN%^Bubbles %^WHITE%^churn "+
			"and blur your vision, making it difficult to see.  "+
			"Especially where you came from or what else might be "+
			"lurking within the %^CYAN%^bubbles%^WHITE%^.  You do "+
			"notice, however, a larger %^BLACK%^hole %^WHITE%^in "+
			"the roof where most of these %^CYAN%^bubbles %^WHITE%^"+
			"rush in a swiftly moving vent.  Perhaps you could "+
			"follow them upward and out of this underground cavern."+
			"%^RESET%^");
	
		set_exits(([
			"vent":ROOMS"coral_s1"
		]));
		
		set_pre_exit_functions(({"vent"}),({"GoThroughDoor"}));
}

int GoThroughDoor(){
	tell_object(TP,"\n\n%^BOLD%^%^WHITE%^You swim quickly upward, "+
		"entering the stream of bubbles!%^RESET%^\n");
	tell_object(TP,"%^BOLD%^%^CYAN%^You're quickly caught up in "+
		"the fast moving stream and are propelled upward "+
		"lightning quick!%^RESET%^\n");
	tell_object(TP,"%^BOLD%^%^WHITE%^You tumble about, turning "+
		"this way and that!%^RESET%^\n");
	tell_object(TP,"%^BOLD%^%^CYAN%^You finally "+
		"surface, dizzy and disoriented.%^RESET%^\n\n");
	tell_room(ETO,"%^BOLD%^%^WHITE%^"+TP->QCN+" vanishes into "+
		"the stream of bubbles!%^RESET%^",TP);
	TP->set_paralyzed(15,"%^BOLD%^%^WHITE%^You're still trying "+
		"to get your bearings.%^RESET%^");
	return 1;
}
	
void reset(){
    ::reset();
    if(!present("aysu")){new(MON"coral_aysu.c")->move(TO);}
}