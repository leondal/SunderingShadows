#include <std.h>
#include "../defs.h"
inherit BASE"coralsea2";

// Coral Sea Area - Created January 2009 by Ari

int FLAG;

void create(){
	::create();
		set_exits(([
			"north":ROOMS"coral_s16",
			"northeast":ROOMS"coral_s17",
			"east":ROOMS"coral_s19",
			"south":ROOMS"coral_s21",
			"southwest":ROOMS"coral_s20"
		]));
		
		set_search("default","%^BOLD%^%^BLACK%^That large clump of "+
			"coral might have something interesting.%^RESET%^");
		set_search("coral",(:TO,"search_coral":));
		set_search("clump",(:TO,"search_coral":));
}

int search_coral(string str){
	object ob;
        if(FLAG == 0){
		if(str == "coral"){
		tell_object(TP,"%^BOLD%^%^BLACK%^You begin to search the large "+
			"clump of coral when suddenly it breaks free revealing a "+
			"hole in the structure's wall!%^RESET%^");
		tell_room(ETO,"%^BOLD%^%^BLACK%^There is a flood of coral dust "+
			"in the water as a big chunk is knocked free!%^RESET%^",TP);
		add_exit(ROOMS"coral_b4","hole");
		FLAG = 1;
		}
	return 1;
	}
	else{
		tell_object(TP,"%^BOLD%^%^BLACK%^You chip away at the wall to "+
			"no avail.%^RESET%^");
		return 1;
	}
}

void reset(){
	::reset();
		remove_exit("coral_b4");
		FLAG = 0;

}
