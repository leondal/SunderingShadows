#include <std.h>
#include "../defs.h"
inherit BASE"coralwreck";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
	
		set_long("%^RESET%^%^ORANGE%^The wide expanse of the "+
			"foredeck stretches out before you.  The once "+
			"highly polished wood of the deck is now %^BOLD%^"+
			"%^BLACK%^scarred %^RESET%^%^ORANGE%^and %^CYAN%^"+
			"warpped%^ORANGE%^.  The wood twisted in places "+
			"and broken in others, leaving little of the prior "+
			"splender.  A few pieces of the rails still display "+
			"their %^YELLOW%^brass fixtures%^RESET%^%^ORANGE%^, "+
			"though they've begun to %^BOLD%^%^BLACK%^blacken "+
			"%^RESET%^%^ORANGE%^and %^CYAN%^tarnish %^ORANGE%^"+
			"from exposure to the salt water.  The %^GREEN%^"+
			"emerald colored jibsail %^ORANGE%^hangs, torn and "+
			"tattered, from remaining rigging that extends down "+
			"from the foremast to the shattered bowspirit which "+
			"used to extend out over the knife like bow.  Every "+
			"so often a current catches them, furling the tatters "+
			"outward and giving a glimpse as to how majestic "+
			"this ship once was.%^RESET%^");
			
		add_item(({"rail","rails","fixtures","brass fixtures"}),""+
                        "This ship was clearly a fine vessel at one time, though "+
			"the sea doesn't appear to have cared, for it brough her "+
			"down like any other.  Here and there, the remains of a "+
			"few rails can be seen that once trimmed the outside edge "+
			"of the ship.  In other places, bits of oxidizing brass "+
			"catch your attention, coverings for more traditional "+
			"metals that peek through.");
		
		add_item(({"jibsail","sail","rigging","lines","tatters"}),""+
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
	
		set_exits(([
			"northeast":ROOMS"coral_w6",
			"west":ROOMS"coral_m21"
		]));
}
