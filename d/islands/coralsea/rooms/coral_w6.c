#include <std.h>
#include "../defs.h"
inherit BASE"coralwreck";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
	
		set_long("%^RESET%^%^ORANGE%^Little remains of the sails "+
			"that once drove this ship, scraps of %^GREEN%^emerald "+
			"cloth %^ORANGE%^flutter in the current, ghostly "+
			"reminders of a bygone splender.  Held aloft by the "+
			"still intact foremast, %^RESET%^rigging %^ORANGE%^drapes "+
			"down to what is left of the bowspirit and the railing. "+
			"Though not even these lines are enough to prevent "+
			"the mast from beginning to tilt to the side, collapsing "+
			"under the pressure of the water.  Like the rest of the "+
			"ship, the foremast was once polished and well tended "+
			"but now it has begun to warp and break.  Tarnished "+
			"%^YELLOW%^brass fixtures %^RESET%^%^ORANGE%^hide away "+
			"the rougher %^BOLD%^%^BLACK%^metals %^RESET%^%^ORANGE%^"+
			"that keep the ship together and would have at one "+
			"time provide a warm counterbalance to the mild wooden "+
			"shades.  High above, you can see a %^YELLOW%^crowsnest "+
			"%^RESET%^%^ORANGE%^still crowns the top of the "+
			"foremast, looking mostly intact.%^RESET%^");
		
		add_item(({"rail","rails","fixtures","brass fixtures"}),""+
			"This ship was clearly a fine vessle at one time, though "+
			"the sea doesn't appear to have cared, for it brough her "+
			"down like any other.  Here and there, the remains of a "+
			"few rails can be seen that once trimmed the outside edge "+
			"of the ship.  In other places, bits of oxidizing brass "+
			"catch your attention, coverings for more traditional "+
			"metals that peek through.");
		
		add_item(({"cloth","sail","rigging","emerald cloth"}),"%^RESET%^"+
			"%^GREEN%^The once green sails are now tattered and bleached "+
			"by the sea water, though you can make out the color in "+
			"emerald splotches here and there.  Usually close to the "+
			"rigging lines where the ropes and pullies have provided a "+
			"small degree of protection.  That which is loose and "+
			"unfurled drifts limply in the water, hinting of the "+
			"ship's former glory.%^RESET%^");
		
		add_item(({"foremast"}),"%^RESET%^%^ORANGE%^This ship appears "+
			"to have been a large two master with a slightly shorter "+
			"foremast before the large mainmast at middeck.  Though "+
			"only a little bit shorter, it would see that this mast "+
			"was able to take the brunt of what the sea through at "+
			"it without caving in.  It still stands tall, rising "+
			"upward through the kelp toward the remains of the crowsnet "+
			"above. %^RESET%^");
		
		add_item(({"bowspirit"}),"%^RESET%^%^ORANGE%^It's hard to say "+
			"how the bowspirit was designed, though a few bits of "+
			"carved wood suggest there might have been a masthead "+
			"rather then a singular pole that extended outward from "+
			"the front of the ship.  Traditionally, such mastheads "+
			"would be of a figure, often a woman, said to be the "+
			"eyes of the ship, especially during times when visibility "+
			"was reduced greatly, like in the fog.  At these times, "+
			"a crew member might climb out over the bowspirit and hold "+
			"a lantern outward, gazing through the fog to watch for "+
			"trouble lying ahead in the water.  It would seem that "+
			"this ship did not see the coral reef in time.%^RESET%^");
		
		add_item(({"crowsnest","nest"}),"%^YELLOW%^High above, located "+
			"toward the top of the foremast is a crowsnest.  Little "+
			"more then a round platform affixed to the mast's top, "+
			"with a bit of rope or wood railing around it, the crows"+
			"nest was a place to keep watch on the horizon for "+
			"trouble or land or any other interest a ship might take "+
			"in their surroundings.%^RESET%^");

	
		set_exits(([
			"southwest":ROOMS"coral_w5",
			"crowsnest":ROOMS"coral_w7"
		]));
}