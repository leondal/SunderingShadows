#include <std.h>
#include "../defs.h"
inherit BASE"coralfun";

// Coral Sea Area - Created January 2009 by Ari
// Is inherited by all coral_m15-27.c files

int FLAG;
void pick_mon();

void init() {
	::init();
		add_action("peer_around","peer");
}

void create(){
    pick_mon();
    set_repop(10);
	::create();
		set_property("light",1);
		set_property("indoors",0);
		set_property("no teleport",1);
		set_terrain(DEEP_WATER);
		set_travel(FRESH_BLAZE);
	
		set_name("amongst the kelp");
		set_short("%^BOLD%^%^GREEN%^A%^RESET%^%^CYAN%^mo%^BOLD%^"+
				"%^GREEN%^ng%^RESET%^%^CYAN%^s%^BOLD%^%^GREEN%^t the "+
				"K%^RESET%^%^CYAN%^e%^BOLD%^%^GREEN%^lp%^RESET%^");
	
		set_long("%^RESET%^%^GREEN%^The stones that can still be seen "+
				"poking up from the drifts of sand suggest that once "+
				"there was a %^BOLD%^garden labyrinth %^RESET%^"+
				"%^GREEN%^here.  Now a much different maze surrounds "+
				"you, one of towering giant kelp thick with countless "+
				"%^BOLD%^green%^RESET%^%^GREEN%^, %^ORANGE%^orange "+
				"%^GREEN%^and %^RED%^red %^GREEN%^fronds.  Thick bulbs "+
				"of holdfast roots grow down through the piles of sand "+
				"and stone, keeping the tall underwater trees in place "+
				"despite what can be turbulent currents.  From within "+
				"the natural crevices these form, tiny %^WHITE%^fish "+
				"%^GREEN%^and other %^RESET%^sea creatures %^GREEN%^dart "+
				"and swim, coming out only to collect what they need "+
				"from the %^RESET%^cloudy %^GREEN%^waters before "+
				"vanishing back into the depths of their kelp "+
				"hideaways.%^RESET%^");
	
		set_smell("default","\nThere is nothing to smell under the water.");
		set_listen("default","You hear your air bubbling away.");
	
		set_items(([
	
			({"kelp","forest","kelp forest"}):"%^RESET%^%^GREEN%^The kelp "+
				"forest is vast and grows thickly here where the old "+
				"maze garden provides a foundation for the root like "+
				"holdfasts to cling.  Stalks as thick as a man's body "+
				"can be seen growing upward for over a hundred feet "+
				"toward the surface, lined with leafy fronds and studded "+
				"with the air filled floats that give it buoyancy."+
				"%^RESET%^",
			
			({"holdfast","holdfasts","roots"}):"%^RESET%^%^ORANGE%^You "+
				"look closely at the root ball shaped growths that "+
				"anchor these vast underwater trees and see their main "+
				"purpose is to cling to unground structures and provide "+
				"an anchor against the ever shifting currents.%^RESET%^",
			
			({"float","floats","frond","fronds"}):"%^RESET%^%^GREEN%^"+
				"Extending from the stripe, these fronds have two parts "+
				"to them.  The first, located close to the stock, is a "+
				"bulb of trapped air like gas that gives the plant "+
				"buoyancy.  The second part is a blade of kelp that can "+
				"grow several feet long and extends out like leaves upon "+
				"a tree, floating and waving in the water.%^RESET%^",
			
			({"water","grit","cloud"}):"%^RESET%^%^CYAN%^The water is "+
				"filled with a fine cloud of floating debris, cast off "+
				"from the kelp and small creatures that call the kelp "+
				"bed their home, as well as sand and grit from the "+
				"bottom, stirred up by your passing.%^RESET%^",
			
			({"fish","creatures","crustaceans"}):"%^CYAN%^Living within "+
				"the vast forest of kelp is a whole ecosystem of living "+
				"creatures.  Silvery fish, tiny crustaceans and a host "+
				"of other beings like star fish, octopus, jellyfish and "+
				"sea anemones.%^RESET%^",
		
		]));
	
	set_pre_exit_functions(({"rise","dive","north","south","east","west","northeast",
		"northwest","southeast","southwest"}),({"GoThroughDoor","GoThroughDoor",
		"GoThroughDoor","GoThroughDoor","GoThroughDoor","GoThroughDoor",
		"GoThroughDoor","GoThroughDoor","GoThroughDoor","GoThroughDoor"}));
	
		
	set_search("default","%^GREEN%^There might be something hiding "+
			"amongst those holdfasts at the base of the kelp.%^RESET%^");
		set_search("kelp",(:TO,"search_holdfast":));
		set_search("holdfast",(:TO,"search_holdfast":));
		set_search("roots",(:TO,"search_holdfast":));
	
}

int search_holdfast(string str){
	object ob;
	if(FLAG == 1){
		tell_object(TP,"%^GREEN%^Appears that this part of the seaweed "+
			"has already been searched.");
		return 1;
	}
	
	if(str == "holdfast" || str == "roots" || str == "kelp"){
		switch(random(20)){
		case 0..2:
			new("/realms/ari/projects/coralsea/obj/coral_prize")->move(TO);
			tell_object(TP,"%^RESET%^%^GREEN%^You search through the "+
					"seaweed and pull out something valuable looking."+
					"%^RESET%^");
			break;
		case 3..19:
			tell_object(TP,"%^RESET%^%^GREEN%^You search through the "+
					"seaweed but find nothing of interest.%^RESET%^");
			break;
		}
	FLAG = 1;
	}
		
return 1;
}

int peer_around(string str){
	tell_object(TP,"%^GREEN%^The kelp blocks your vision.%^RESET%^");
	return 1;
}

void reset(){
	::reset();
		FLAG = 0;
}