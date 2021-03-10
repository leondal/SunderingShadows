#include <std.h>
#include "../defs.h"
inherit BASE"coralsea3";

// Coral Sea Area - Created January 2009 by Ari

int FLAG;

void create(){
	::create();
		set_exits(([
			"east":ROOMS"coral_s23",
			"south":ROOMS"coral_s24"
		]));

		set_search("default","%^BOLD%^%^BLACK%^Maybe something still "+
			"remains within the rubble below.%^RESET%^");
		set_search("rubble",(:TO,"search_rubble":));
}

int search_rubble(string str){
	object ob;
	
	if(FLAG == 1){
		tell_object(TP,"%^BOLD%^%^BLACK%^Seems there is "+
			"nothing left in the rubble.%^RESET%^");
		return 1;
	}
	
	if(str == "rubble"){
		switch(random(5)){
		case 0..1:
			ob = new (OBJ"coral_prize");
			ob->move(ETP);
			tell_object(TP,"%^RESET%^%^BLUE%^You search through the "+
					"rubble and pull out something valuable looking."+
					"%^RESET%^");
			break;
		
		case 2..4:
			tell_object(TP,"%^RESET%^%^BLUE%^You search through the "+
					"rubble but find nothing of interest.%^RESET%^");
			break;
		}
	FLAG = 1;
	}
return 1;
}

void reset(){
	::reset();
		FLAG = 0;
}