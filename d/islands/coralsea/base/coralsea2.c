#include <std.h>
#include "../defs.h"
inherit BASE"coralfun";

// Coral Sea Area - Created January 2009 by Ari
// Is inherited by all coral_s11-s21.c files

void pick_mon();

void create(){
    pick_mon();
    set_repop(15);
	::create();
		set_property("light",1);
		set_property("indoors",0);
		set_terrain(DEEP_WATER);
		set_travel(FRESH_BLAZE);
	
		set_name("Under the Saakrune Sea");
		set_short("%^RESET%^%^CYAN%^Under the S%^WHITE%^a%^GREEN%^a"+
				"%^CYAN%^kr%^WHITE%^u%^GREEN%^n%^CYAN%^e S%^WHITE%^e"+
				"%^GREEN%^a%^RESET%^");
	
		set_long("%^RESET%^%^CYAN%^Swimming under the surface of the "+
			"Saakrune Sea, visibility is reduced to a deep b%^BLUE%^l"+
			"%^GREEN%^u%^BOLD%^e%^RESET%^%^BLUE%^-%^GREEN%^g%^BLUE%^r"+
			"%^CYAN%^e%^BOLD%^%^BLUE%^e%^RESET%^%^GREEN%^n %^CYAN%^shade "+
			"of ever moving swirls.  Small fish dart about in %^BOLD%^"+
			"%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^WHITE%^ve%^RESET%^"+
			"r%^BOLD%^%^WHITE%^y %^RESET%^%^CYAN%^schools, while flakes "+
			"of %^ORANGE%^coral %^CYAN%^drift in the faint light from "+
			"the surface.  Nearby, the mountainous structure of a "+
			"%^ORANGE%^coral shelf %^CYAN%^can be seen drifting lower "+
			"into the murky depths of the ocean. Extending from part "+
			"of the structure, where the coral gives way to stone, "+
			"there appears to be the remains of some part of a %^BOLD%^"+
			"%^BLACK%^ship%^RESET%^%^CYAN%^.%^RESET%^\n");
	
		set_smell("default","\nThere is nothing to smell under the water.");
		set_listen("default","You hear your air bubbling away.");
	
		set_items(([
			({"flakes","schools","fish"}):"%^BOLD%^%^WHITE%^Colorful "+
				"little %^BLUE%^f%^YELLOW%^i%^RESET%^%^BLUE%^s%^BOLD%^h "+
				"%^WHITE%^dart about, catching up the bits of mater "+
				"that float in the deep waters.  Their little forms "+
				"weaving back and forth in tight schools.%^RESET%^",
			
			({"structure","coral"}):"%^RESET%^%^ORANGE%^Coral and "+
				"other bits of mater float about in the water here, "+
				"making it a bit more murky then the deeper waters.  A "+
				"coral covered structure looms nearby, likely the "+
				"cause of this debris.%^RESET%^", 
			
			({"ship"}):"%^BOLD%^%^BLACK%^The strange coral covered "+
				"structure appears to have claimed more then one ship "+
				"over time.  Wood and metal bits can be seen caught in "+
				"several niches, though most has drifted to the bottom "+
				"of the ocean, including what appears to be a recent "+
				"ship wreck.%^RESET%^",
				
			({"water","ocean","sea","waters"}):"%^BOLD%^%^BLUE%^The water "+
				"stretches all around you, filing your vision with its "+
				"emptiness.  Maybe you should think about returning to "+
				"your boat before you're swept too far away.%^RESET%^",
		]));
		
	set_pre_exit_functions(({"north","south","east","west","northeast",
		"northwest","southeast","southwest"}),({"GoThroughDoor","GoThroughDoor",
		"GoThroughDoor","GoThroughDoor","GoThroughDoor","GoThroughDoor",
		"GoThroughDoor","GoThroughDoor"}));
	
}


