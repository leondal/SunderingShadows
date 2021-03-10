//mage_cyric.c - reward for Riddle Quest.
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("robe of illusion");
	set_id(({ "robe", "robe of illusion" }));
	set_short("%^RESET%^%^MAGENTA%^Robe of %^BOLD%^%^WHITE%^I"+
         "%^BLACK%^l%^WHITE%^l%^BLACK%^u%^WHITE%^s%^BLACK%^i"+
         "%^WHITE%^o%^BLACK%^n%^RESET%^");
	set_obvious_short("A silvery purple robe");
	set_long(
@AVATAR
%^MAGENTA%^Purple silk woven with %^BOLD%^%^WHITE%^silver threads%^RESET%^%^MAGENTA%^ give this robe a silvery sheen.  The robes are cut to be close to the body, perhaps to aid in ease of movement.  The slim-fitting robe features three buckles along the right side, under the arms.  A trio of straps on the left side of the robe seems to confirm that you can draw them close to get the right fit.  The flowing robe ripples as the wearer moves, revealing an underside of chaotic %^BOLD%^%^BLACK%^black swirls %^RESET%^%^MAGENTA%^that add a sense of mystery to the garment.%^RESET%^

AVATAR
	);
	set_lore(
@AVATAR
The origins of the Robe of Illusion has been lost over time.  Stories of its creation range from an Archmage of Illusion to a cleric of Cyric.  None can know the truth, however, and thus far, no solid evidence has been found to support any of the stories.  In any event, the robes seem able to assist even the most novice mage in creating outstanding illusions.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^MAGENTA%^You slip the robes off.");
	return 1;
}
