#include <std.h>
#include "../defs.h"
inherit CVAULT;

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_property("light",0);
		set_property("indoors",1);
	
		set_short("%^YELLOW%^Captain's Quarters%^RESET%^");
		set_long("%^RESET%^%^ORANGE%^Clearly the captain's quarters "+
			"of a large sailing vessel, this wooden chamber is wedged "+
			"between the towering coral covered structure and the "+
			"earth.  Thus pinned, it waits for %^BLUE%^water"+
			"%^ORANGE%^, %^RESET%^pressure %^ORANGE%^and %^CYAN%^time "+
			"%^ORANGE%^to finish what some storm began.  The wood is "+
			"swollen and thick with water.  Cracks and holes reveal "+
			"themselves here and there, though only the one passage "+
			"seems big enough to fit through.  A %^RESET%^pocket of "+
			"air %^ORANGE%^is trapped at the ceiling, not much, but "+
			"perhaps enough to catch one's breath after diving so "+
			"far below the surface.  A bit of %^BOLD%^%^BLACK%^"+
			"rubbish %^RESET%^%^ORANGE%^and %^CYAN%^debris %^ORANGE%^"+
                        "litter the floor but it looks mostly like ruined "+
			"furniture.  Little of value appears to remain.%^RESET%^");
	
		set_smell("default","\nThere is nothing to smell under the water.");
		set_listen("default","You hear your air bubbling away.");
		
		set_items(([
			({"structure","coral"}):"%^RESET%^%^ORANGE%^Coral and "+
				"other bits of mater float about in the water here, "+
				"making it a bit more murky then the deeper waters.  A "+
				"coral covered structure looms nearby, likely the "+
				"cause of this debris.%^RESET%^", 
			
			({"ship","wreck"}):"%^BOLD%^%^BLACK%^The strange coral covered "+
				"structure appears to have claimed more then one ship "+
				"over time.  Wood and metal bits can be seen caught in "+
				"several niches, though most has drifted to the bottom "+
				"of the ocean, including what appears to be a recent "+
				"ship wreck.%^RESET%^",
				
			({"wood","splinters"}):"%^RESET%^%^ORANGE%^Large planks of "+
				"what must have once been well tended wood now lay "+
				"twisted and broken after being dashed against the "+
				"coral lined rocky structure.  Some parts still look "+
				"pristine but the majority has begun to rot away under "+
				"the influence of water and time.%^RESET%^",
			]));
			
		set_exits(([
			"out":ROOMS"coral_s25",
			"west":ROOMS"coral_w2"
		]));
		
		set_door("door",ROOMS"coral_w2","west","cskeyriin");
		set_door_description("door","%^RESET%^%^CYAN%^The door is heavily "+
                "made and is reinforced with iron bands.  You're sure this "+
				"is why it is still whole and functioning despite the "+
				"wrecked state of the ship.%^RESET%^");
		set_locked("door",1);
		lock_difficulty("door",-70,"lock");          
		set_string("door","open","%^BLUE%^The door opens and several %^WHITE%^"+
			"bubbles %^BLUE%^rush out!%^RESET%^\n");
}
