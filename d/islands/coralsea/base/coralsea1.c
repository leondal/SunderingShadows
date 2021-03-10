#include <std.h>
#include "../defs.h"
inherit CROOM;

// Coral Sea Area - Created January 2009 by Ari
// Is inherited by all coral_s1-s10.c files


void create(){
	::create();
		set_property("light",2);
		set_property("indoors",0);
		set_terrain(DEEP_WATER);
		set_travel(FRESH_BLAZE);
			
		set_name("Swimming upon the Saakrune Sea");
		set_short("%^RESET%^%^CYAN%^Swimming upon the S%^WHITE%^a%^GREEN%^a"+
				"%^CYAN%^kr%^WHITE%^u%^GREEN%^n%^CYAN%^e S%^WHITE%^e"+
				"%^GREEN%^a%^RESET%^");
	
		set_long("%^BOLD%^%^CYAN%^You find yourself drifting on the vast "+
			"open %^BLUE%^sea%^CYAN%^. The rise and drop of each swell "+
			"reminding you just how small a being you truly are.  "+
			"The dark %^RESET%^%^CYAN%^ b%^BLUE%^l%^GREEN%^u%^BOLD%^e"+
			"%^RESET%^%^BLUE%^-%^GREEN%^g%^BLUE%^r%^CYAN%^e%^BOLD%^"+
			"%^BLUE%^e%^RESET%^%^GREEN%^n %^BOLD%^%^CYAN%^waters prevent "+
			"you from seeing much more then your feet feebly kicking "+
			"back and forth as you fight to stay afloat.%^RESET%^");
	
		set_smell("default","\nThe air is filled with the salty tang of "+
			"the sea.");
		set_listen("default","You hear the lapping of water nearby.");
	
		set_items(([
			({"structure","shape"}):"%^BOLD%^%^BLACK%^It's hard to tell "+
				"what it is exactly, as covered in %^RESET%^%^ORANGE%^"+
				"coral %^BOLD%^%^BLACK%^as it is, but you think it might "+
				"be part of an underwater mountain system.  Maybe there "+
				"is a cave further down, though diving so close to the "+
				"reef would probably be suicide. Maybe you should swim "+
				"further out.%^RESET%^",

			({"coral"}):"%^RESET%^%^ORANGE%^The shelf seems well "+
				"developed and healthy, you imagine that the underwater "+
				"structure that it has grown up upon is very old indeed."+
				"%^RESET%^",
			
			({"water","ocean","sea","waters"}):"%^BOLD%^%^BLUE%^The water "+
				"stretches all around you, filing your vision with its "+
				"emptiness.  Maybe you should think about returning to "+
				"your boat before you're swept too far away.%^RESET%^",
		]));
	
}