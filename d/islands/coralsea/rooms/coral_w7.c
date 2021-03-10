#include <std.h>
#include "../defs.h"
inherit BASE"coralwreck";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
	
		set_long("%^YELLOW%^High above the ship, located toward "+
			"the top of the foremast is this crowsnest.  Little "+
			"more then a round %^BLACK%^platform %^YELLOW%^affixed "+
			"to the mast's top, the broken remains of a %^RESET%^"+
			"wooden railing %^YELLOW%^encircle it. With little room, "+
			"it is likely that only one or two crewmen, at the most, "+
			"would ever be found here when this ship sailed the "+
			"open seas. Tangles of %^RESET%^%^CYAN%^seaweed %^YELLOW%^"+
			"curl about the remains of the railing, hiding from view "+
			"what else surrounds the nest.  The foremast of the "+
			"ship heads down through these tangles, indicating a safe "+
			"way to retreat if needed.%^RESET%^");

		add_item(({"foremast"}),"%^RESET%^%^ORANGE%^This ship appears "+
			"to have been a large two master with a slightly shorter "+
			"foremast before the large mainmast at middeck.  Though "+
			"only a little bit shorter, it would see that this mast "+
			"was able to take the brunt of what the sea through at "+
			"it without caving in.  It still stands tall, rising "+
			"upward through the kelp toward the remains of the crowsnet "+
			"above. %^RESET%^");
		
			
		add_item(({"kelp","forest","kelp forest"}),"%^RESET%^%^GREEN%^"+ 
			"The kelp forest is vast and grows thickly here where the "+
			"old maze garden provides a foundation for the root like "+
			"holdfasts to cling.  Stalks as thick as a man's body "+
			"can be seen growing upward for over a hundred feet "+
			"toward the surface, lined with leafy fronds and studded "+
			"with the air filled floats that give it buoyancy.%^RESET%^");
			
		add_item(({"rail","rails","fixtures","brass fixtures"}),""+
			"This ship was clearly a fine vessle at one time, though "+
			"the sea doesn't appear to have cared, for it brough her "+
			"down like any other.  Here and there, the remains of a "+
			"few rails can be seen that once trimmed the outside edge "+
			"of the ship.  In other places, bits of oxidizing brass "+
			"catch your attention, coverings for more traditional "+
			"metals that peek through.");
	
		set_exits(([
			"north":ROOMS"coral_m4",
			"southwest":ROOMS"coral_m9",
			"deck":ROOMS"coral_w6"
		]));
		
}

void reset(){
    ::reset();
    if(!present("zeralquin")){new(MON"coral_captain.c")->move(TO);}
}