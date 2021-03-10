//fighter_istishia.c - reward for Riddle Quest. Circe 2/5/04
//Thanks to Torm for describing this item!
#include <std.h>
#include "../../nereid.h"
inherit NHIDE;

void create(){
	::create();
//	set_name("istishia hide");
	set_id(({"hide","armor","aqueous armor","water armor"}));
	set_short("%^RESET%^%^BLUE%^Aque%^BOLD%^%^WHITE%^ou%^RESET%^%^BLUE%^s "+
         "Ar%^BOLD%^%^WHITE%^mo%^RESET%^%^BLUE%^r%^RESET%^");
	set_obvious_short("%^RESET%^%^BLUE%^Aqueous armor%^RESET%^");
	set_long(
@CIRCE
%^BLUE%^As you look at the armor you can see a ripple spread out across the surface.  Whilst it appears to be made mostly of water you are unable to see through it.  As the armor moves around the wearer small crest%^BOLD%^%^WHITE%^in%^RESET%^%^BLUE%^g wa%^BOLD%^%^WHITE%^ve%^RESET%^%^BLUE%^s appear every now and then, and yet it feels solid to the touch.%^RESET%^
CIRCE
	);
	set_lore(
@CIRCE
%^BLUE%^There are few records surviving that detail the history of this armor, and what remains is as likely to be rumour and myth than fact.  The most commonly accepted account is that a small coastal temple of Istishia whose reputation for execellent ceramics had spread far and wide were asked to create a whole selection of fine pots, jars, plates and bowls.  The work that they did was exquisite, and part of the donation made to the temple in thanks was a suit of armor once worn by a water nymph.%^RESET%^
CIRCE
	);
   set_property("lore difficulty",12);
	set_remove("%^BLUE%^The armor pools together on the floor once you remove it.%^RESET%^");
}
