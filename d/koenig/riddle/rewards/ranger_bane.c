//ranger_bane.c - Reward for Riddle Quest. Cythera 4.05
#include <std.h>
#include "../../nereid.h"

inherit NBOW;

void create(){
   ::create();
//   set_name("bane bow");
   set_id(({"bow","longbow","long bow","tyrant's piercing gaze","green bow","tyrant bow"}));
   set_obvious_short("%^BOLD%^%^GREEN%^A %^BLACK%^spiked%^GREEN%^ green wood longbow%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Tyr%^GREEN%^a%^BLACK%^nt's "+
		"%^BLACK%^Pi%^GREEN%^e%^BLACK%^rc%^GREEN%^i%^BLACK%^ng %^GREEN%^"+
		"Gaze%^RESET%^");
   set_long("%^BOLD%^%^GREEN%^Crafted from supple green wood, this bow has"+
		" a wicked appearance.  The long bow has been stained an "+
		"emerald shade of green and lacquered to preserve the color."+
		"  Drilled into the wood are a series of %^BLACK%^black steel"+
		" %^GREEN%^spikes that run up and down the outer face of the bow.  "+
		"%^BLACK%^Black scaled leather%^GREEN%^ has been wrapped around"+
		" the center of the bow, to create a hand hold.  A thin string of"+
		" %^BLACK%^blackened steel%^GREEN%^ keeps the bow taunt and ready "+
		"to use in the conquests of Bane.");
   set_lore("The Order of the Green Bow is relatively new in the Tyrant's Faith."+
		"  Composed of rangers who have pledged themselves to spread the "+
		"fear and tyranny of Bane in the wilderness, the rangers have "+
		"quickly come to clashes with other rangers.  Those of Malar, "+
		"Talos, and Auril find the presence of Bane in the forests an "+
		"unwelcome invasion and often hunt them as savagely as they would"+
		" a ranger of Mielikki.");
   set_property("lore difficulty",12);
	set_unwield("%^BOLD%^%^BLACK%^You scratch your fingers lightly on the"+
			" spikes, feeling the power that is Bane.");
}