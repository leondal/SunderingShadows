#include <std.h>
#include "../defs.h"
inherit BASE"coralsea3";

// Coral Sea Area - Created January 2009 by Ari

int count;

void init(){
	::init();
		add_action("break_wood","break");
}

void create(){
	::create();
		set_exits(([
			"north":ROOMS"coral_s24"
		]));
		
		set_search("default","%^BOLD%^%^BLACK%^Maybe something still "+
			"remains within the rubble below.%^RESET%^");
		set_search("rubble",(:TO,"search_rubble":));
}

int search_rubble(string str){
	object ob;
	if(str == "rubble"){
		tell_object(TP,"%^BOLD%^%^BLACK%^You become aware that there "+
			"is wood, not stone along this piece of the structure. "+
			"It feels thick, but you might be able to %^BLUE%^break "+
			"%^BLACK%^it open if you tried.%^RESET%^");
		return 1;
	}
}

void break_wood(string str){
	int roll, might;
	object obj;
	
	roll = random(20);
	might = TP->query_stats("strength");
	
	if(str != "wood"){
		tell_object(TP,"%^BOLD%^%^BLACK%^Break what?%^RESET%^");
		return 1;
	}
	if(count > 5){
		tell_object(TP,"%^BOLD%^%^BLACK%^The wood has been broken "+
			"clear and made a passage already.");
		return 1;
	}
	if(roll > might){
		tell_object(TP,"%^BOLD%^%^BLACK%^You're thrown backwards as "+
			"your strike against the wood fails to break anything."+
			"%^RESET%^");
		TP->set_paralyzed(5,"%^BLUE%^You're swimming back into "+
			"position!%^RESET%^");
		tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+" is pushed backwards "+
			"as their attempt to break the wall fails.%^RESET%^",TP);
		return 1;
	}
	if(count > 4){
		tell_object(TP,"%^BOLD%^%^CYAN%^With a flood of bubbles you "+
			"finally smash open the wooden planks and reveal a "+
			"passage through the wall.%^RESET%^");
		tell_room(ETP,"%^BOLD%^%^CYAN%^A flood of bubbles explodes "+
			"from the hole "+TP->QCN+" has created in the wall.%^RESET%^",TP);
		add_exit(ROOMS"coral_w1","hole");
		count = count+1;
		return 1;
	}
	else{
		tell_object(TP,"%^BOLD%^%^BLACK%^You struggle to break a small "+
			"piece of wood away from the structure.%^RESET%^");
		tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+" struggles to break "+
			"some of the structure's wall free.%^RESET%^",TP);
		TP->set_paralyzed(5,"%^BOLD%^%^BLUE%^You're searching for a "+
			"weak spot in the wall.%^RESET%^");
		count = count+1;
		return 1;
	}
}

void reset(){
	::reset();
		remove_exit("coral_w1");
		
}
