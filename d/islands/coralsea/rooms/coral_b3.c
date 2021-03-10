#include <std.h>
#include "../defs.h"
inherit BASE"coraltower";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
	
		set_long("%^BOLD%^%^BLACK%^Long since submerged by the forces "+
			"of nature, this ancient structure has been overrun by "+
			"%^RESET%^%^CYAN%^se%^GREEN%^a %^CYAN%^l%^BLUE%^i%^CYAN%^"+
			"fe%^BLACK%^%^BOLD%^.  Unlike the exterior, the interior of "+
			"this structure contains no coral, but is instead covered "+
			"in various clusters of underwater %^RESET%^%^GREEN%^a"+
			"%^BOLD%^l%^RESET%^%^CYAN%^g%^GREEN%^a%^CYAN%^e %^BOLD%^"+
			"%^BLACK%^and %^RESET%^%^CYAN%^se%^BLUE%^a%^GREEN%^w"+
			"%^CYAN%^e%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^d%^BOLD%^"+
			"%^BLACK%^.  The thick clumps grow heavily upon the stone "+
			"walls, clinging to the mortar lines and crumbling away at "+
			"the wooden supports.  More then one piece of the %^RESET%^"+
			"floor %^BOLD%^%^BLACK%^has given away and left a passage "+
			"going down.  Likewise, %^RESET%^%^ORANGE%^doors %^BOLD%^"+
			"%^BLACK%^that once led to other parts of this tower have "+
			"rotted away giving access to the rooms beyond.%^RESET%^");

		add_item(({"doors","door"}),"%^RESET%^%^ORANGE%^They appear "+
			"to all but have rotted away.%^RESET%^");
		
		add_item(({"wood","walls","stone"}),"%^RESET%^%^ORANGE%^Long "+
			"submerged, this building has begun to give way under the "+
			"pressure of the water and the sea life which grows upon "+
			"it.  The stones that make up the majority of the building "+
			"still seem strong, but the wood has all but rotted away, "+
			"giving easy access to most of the rooms and floors of "+
			"this ancient tower.%^RESET%^");
		
		add_item(({"algae","seaweed","sea weed","weed"}),"%^GREEN%^"+
			"Thick clumps of algae and seaweed grow through out the "+
			"interior of this building.  Their heavy presence "+
			"providing ample food and hideaways for the myriad tiny "+
			"fish and crustaceans that make their home here.");
		
		set_exits(([

			"north":ROOMS"coral_b2",
			"east":ROOMS"coral_b4",
			"south":ROOMS"coral_b5",
			"dive":ROOMS"coral_b8"
		]));
}