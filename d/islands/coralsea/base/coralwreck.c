#include <std.h>
#include "../defs.h"
inherit BASE"coralfun";

// Coral Sea Area - Created January 2009 by Ari
// Is inherited by all coral_w1-w7.c files

void init() {
	::init();
		add_action("say_function","say");
		add_action("say_function","whisper");
		add_action("say_function","yell");
}

void create(){
	::create();
		set_property("light",1);
		set_property("indoors",0);
		set_property("no teleport",1);
		set_terrain(DEEP_WATER);
		set_travel(FRESH_BLAZE);
	
		set_name("a seawreck");
		set_short("%^YELLOW%^A S%^RESET%^%^ORANGE%^e%^RESET%^"+
			"a%^YELLOW%^w%^BLACK%^r%^RESET%^%^ORANGE%^e"+
			"%^YELLOW%^ck%^RESET%^");
	
		set_long("%^RESET%^%^ORANGE%^The ruined remains of a ship "+
			"wreck lay here.  The wood %^BOLD%^%^BLACK%^warped"+
			"%^RESET%^%^ORANGE%^ and %^CYAN%^twisted%^ORANGE%^, "+
			"splintering away here and there where it struck the "+
			"coral lined structure above.%^RESET%^");
	
		set_smell("default","\nThere is nothing to smell under "+
			"the water.");
		set_listen("default","You hear your air bubbling away.");
	
		set_items(([
			({"structure","coral"}):"%^RESET%^%^ORANGE%^Coral and "+
				"other bits of mater float about in the water here, "+
				"making it a bit more murky then the deeper waters. "+
				"A coral covered structure looms nearby, likely the "+
				"cause of this debris.%^RESET%^", 
				
			({"water","ocean","sea","waters"}):"%^BOLD%^%^BLUE%^The "+
				"water stretches all around you, filing your vision "+
				"with its emptiness.  Maybe you should think about "+
				"returning to your boat before you're swept too far "+
				"away.%^RESET%^",
			
			({"ship","wreck"}):"%^BOLD%^%^BLACK%^The strange coral "+
				"covered structure appears to have claimed more then "+
				"one ship over time.  Wood and metal bits can be "+
				"seen caught in several niches, though most has "+
				"drifted to the bottom of the ocean, including what "+
				"appears to be a recent ship wreck.%^RESET%^",
				
			({"wood","splinters"}):"%^RESET%^%^ORANGE%^Large planks "+
				"of what must have once been well tended wood now "+
				"lay twisted and broken after being dashed against "+
				"the coral lined rocky structure.  Some parts still "+
				"look pristine but the majority has begun to rot "+
				"away under the influence of water and time."+
				"%^RESET%^",
		]));
}
