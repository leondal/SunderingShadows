#include <std.h>
#include "../defs.h"
inherit BASE"coraltower";

// Coral Sea Area - Created January 2009 by Ari

void init(){
	::init();
		add_action("move_curtains","move");
}

void create(){
	::create();
		set_long("%^RESET%^%^CYAN%^Once a large and well appointed "+
			"dining room, this chamber has long since fallen away "+
			"into decay.  The stately %^ORANGE%^dining table "+
			"%^RESET%^%^CYAN%^has collapsed against one of the "+
			"walls, shattering its chairs and creating a large "+
			"pile of %^BOLD%^%^BLACK%^rubble %^RESET%^%^CYAN%^over "+
			"which several tattered %^RESET%^curtains %^CYAN%^have "+
			"fallen.  This has created a cave like area within the "+
			"room.  One within which even the ever present tiny "+
			"%^RESET%^fish %^CYAN%^dare not to enter.%^RESET%^");
		
		add_item(({"curtains","curtain"}),"%^RESET%^%^ORANGE%^Most "+
			"of the curtains appear to be little more then a few "+
			"tatters of some old table cloth or window hanging.  "+
			"There's not much left to them any more, but you might "+
			"be able to move them aside and peer under the table's "+
			"remains.");
		
		add_item(({"table","chair","chairs"}),"%^RESET%^%^ORANGE%^"+
			"There isn't much left of any of them, but the large, "+
			"heavy wood slabs that were used to make the dinning "+
			"table appear to have weathered the damage better "+
			"then its surrounding chairs.  This has created a "+
			"small cave within the dinning room.%^RESET%^");
		
		add_item(({"cave","hole"}),"%^BOLD%^%^BLACK%^It looks "+
			"pretty dark under the table, but you might be able "+
			"to get a better look if you were to move some of "+
			"those curtains out of the way.%^RESET%^");
		
		set_exits(([
			"west":ROOMS"coral_b8",
		]));
}

int move_curtains(string str){
	object ob;
	if(str == "curtains"){
		tell_object(TP,"%^BOLD%^%^WHITE%^You shift the curtains "+
			"aside, revealing a passage under the table and "+
			"through the wall of the structure!%^RESET%^");
		tell_room(ETP,"%^BOLD%^%^WHITE%^Some debris shift and "+
			"open a passageway.%^RESET%^",TP);
				add_exit(ROOMS"coral_w2","passage");
		return 1;
	}
	else{
		tell_object(TP,"%^BOLD%^%^WHITE%^What did you want to "+
			"move?%^RESET%^");
		return 1;
	}
}

void reset(){
	::reset();
		remove_exit("coral_w2");
		tell_room(TO,"%^BOLD%^%^CYAN%^The current shifts, "+
			"resettling the curtains.%^RESET%^");
}