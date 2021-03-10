#include <std.h>
#include "../defs.h"
inherit BASE"coralfun";

// Coral Sea Area - Created January 2009 by Ari
// Aysu's Lair - The big sea monster that drags highbies off for lunch!

void pick_mon();

void create(){
	::create();
		set_property("light",1);
		set_property("indoors",0);
		set_property("no teleport",1);
		set_terrain(DEEP_WATER);
		set_travel(FRESH_BLAZE);
	
		set_name("underground tunnel");
		set_short("%^RESET%^%^ORANGE%^An Underground Tunnel%^RESET%^");
	
		set_long("%^BOLD%^%^BLACK%^Filled with water, this "+
			"underground tunnel makes a steep descent downward into "+
			"the sea floor.  %^RESET%^%^ORANGE%^Sandy walls "+
			"%^BOLD%^%^BLACK%^give way quickly to harder, glossy "+
			"%^BLUE%^stone %^BLACK%^that reminds you of a lava tube "+
			"or other such natural funnel.  The tunnel's sides are "+
			"smooth and free of jagged edges, which makes the need "+
			"to walk hunched over a little easier, as there is very "+
			"little room height wise.  Littering the floor of this "+
			"underground pathway are the remains of several "+
			"creatures.  Broken, jagged %^WHITE%^bones %^BLACK%^that "+
			"appear to have been snapped in half, look far too large "+
			"to be from any fish you've seen.  Now and again, a "+
			"spill of %^CYAN%^bubbles %^BLACK%^from a natural gas "+
			"vent escapes upward along the tunnel you find yourself "+
			"in.%^RESET%^");
	
		set_smell("default","\nThere is nothing to smell under the water.");
		set_listen("default","You hear your air bubbling away.");
	
		set_items(([
		
		({"bubbles","gas","natural gas"}):"%^BOLD%^%^CYAN%^"+
			"As the bubbles trickle by, you realize that you are "+
			"traveling in a natural gas vent.  Further on, the "+
			"earth is releasing some sort of gas into the water "+
			"and this is one of the pathways it takes to escape."+
			"Thankfully, it would appear to be a cold gas vent as "+
			"you're not being boiled alive.%^RESET%^",

		({"floor","sea floor","sand"}):"%^RESET%^%^ORANGE%^"+
			"The floor of the ocean is a mixture of fine sand, "+
			"grit, rock and shell.  Compacted by the pressure of "+
			"the water upon its surface it seems mostly hard and "+
			"stable after the first inch of new deposit or so."+
			"%^RESET%^",
		
		({"walls"}):"%^BOLD%^%^BLACK%^The sand gives way quickly "+
			"to the slick surface of an old lava tube or other such "+
			"natural funnel.  They don't quiet look like obsidian "+
			"glass, but they are smooth enough to be.  Regardless "+
			"the tunnel winds its way deeper and deeper into the "+
			"sea floor.%^RESET%^",
		
		({"stone","glossy stone"}):"%^BOLD%^%^BLACK%^It doesn't "+
			"quiet look like obsidian, making you wonder what could "+
			"have created such a slick, smooth surface as this."+
			"%^RESET%^",
		
		({"bones","remains"}):"%^BOLD%^%^WHITE%^Is that a human "+
			"skull?  Why does that curved bone look like a rib? "+
			"What could be down here that eats people?  Do you "+
			"really want to find out?%^RESET%^",
		
		]));
}

