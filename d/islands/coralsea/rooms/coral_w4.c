#include <std.h>
#include "../defs.h"
inherit BASE"coralwreck";

// Coral Sea Area - Created January 2009 by Ari

int FLAG;

void create(){
	::create();
		set_long("%^RESET%^%^ORANGE%^Large support beams jut and "+
			"curve up through the large hold, helping to reinforce "+
			"the main deck as well as divide up the hull's "+
			"interior space into several sections.  Designed as "+
			"a hold for cargo, the hull is open with a number of "+
			"%^RESET%^ropes%^ORANGE%^, %^BOLD%^%^BLACK%^pulleys "+
			"%^RESET%^%^ORANGE%^and other %^CYAN%^devices %^ORANGE%^"+
			"for securing cargo to the many support beams. Now "+
			"though, most of what this hold once carried lays in "+
			"%^BOLD%^%^BLACK%^rotting remains %^RESET%^%^ORANGE%^"+
			"upon the floor.  Rubble and trash for the most part, "+
			"there might be a few things of value still left if "+
			"you searched through it all.");
			
		add_item(({"beams","supports","support beams"}),"%^RESET%^"+
			"%^ORANGE%^The thick beams make up the ribs of the ship "+
			"giving it both structure and support.  Most curve "+
			"upward from the thick bottom beam with cross supports "+
			"where needed to reinforce and make the ship sound. "+
			"A few others appear to be placed in stratigic "+
			"locations to ensure that larger pieces of cargo "+
			"stay put and don't move around.%^RESET%^");
		
		add_item(({"ropes","pulleys","devices"}),"%^BOLD%^%^WHITE%^"+
			"The ropes and pulleys are pretty much destroyed "+
			"though you still see a few that are mostly intact. "+
			"Even so, you wouldn't dare risk putting any weight "+
			"upon them, though once upon a time they were used "+
			"mainly to shift large pieces of cargo about without "+
			"risking injury to the crew.%^RESET%^");
		
		add_item(({"cargo","remains","rubble","trash"}),"%^BOLD%^"+
			"%^BLACK%^There isn't much left of the cargo.  Broken "+
			"boxes and crates have rotted away, and its clear a few "+
			"scavengers or treasure seekers helped themselves to "+
			"whatever was left of the undamaged cargo.  Still, "+
			"there might be a few things of value somewhere in the "+
			"rubble, if you search around in it.%^RESET%^");
		

		
		set_exits(([
			"out":ROOMS"coral_m27"
		]));
		
		set_search("default","%^BOLD%^%^BLACK%^Maybe something still "+
			"remains within the rubble below.%^RESET%^");
		set_search("rubble",(:TO,"search_rubble":));
		set_search("cargo",(:TO,"search_rubble":));
		set_search("remains",(:TO,"search_rubble":));
		set_search("trash",(:TO,"search_rubble":));
}


int search_rubble(string str){
	object ob;
   if(FLAG == 1){
		tell_object(TP,"%^BOLD%^%^BLACK%^Appears that this "+
			"part of the rubble has already been searched.");
		return 1;
	}
	
	if(str == "rubble" || str == "cargo" || str == "remains" 
		|| str == "trash"){
        tell_room(TO,"%^BOLD%^%^BLACK%^Disturbed by your searching "+
		"a giant %^YELLOW%^electric eel %^BLACK%^darts out from "+
		"the pile!%^RESET%^");
    if(!present("cyrserox")){new(MON"coral_eel.c")->move(TO);}
	}
	
FLAG = 1;
return 1;
}

void reset(){
	::reset();
		FLAG = 0;
}
