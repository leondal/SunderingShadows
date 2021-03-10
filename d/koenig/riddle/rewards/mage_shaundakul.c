//mage_shaundakul.c - reward for Riddle Quest. Cythera 8/05
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("wayfarer's robe");
	set_id(({ "robe","wayfarer's robe","cotton robe","dark black robe" }));
	set_obvious_short("%^BOLD%^%^BLACK%^A dark black cotton robe%^RESET%^");
	set_short("%^BOLD%^%^BLACK%^W%^RESET%^%^CYAN%^a%^MAGENTA%^y%^BOLD%^"+
		"%^BLACK%^f%^RESET%^%^CYAN%^a%^MAGENTA%^r%^CYAN%^e%^MAGENTA%^"+
		"r%^BOLD%^%^BLACK%^'%^RESET%^%^MAGENTA%^s %^CYAN%^Robe%^RESET%^");
	set_long(
@CYTHERA
%^BOLD%^%^BLACK%^Fashioned out of dark black cotton, this black robe is made for function more so than form.  The cotton fabric of the robe has been worn to a soft finish, making it very comfortable to wear.  The full cut robe has some extra volume, allowing it to whip around in the wind.  On each sleeve are a pair of %^BOLD%^%^WHITE%^silver%^BOLD%^%^BLACK%^ leather straps and %^BOLD%^%^WHITE%^silver%^BOLD%^%^BLACK%^ buckles, allowing the wearer to tighten and keep them in check.  Embroidered dots in %^RESET%^%^CYAN%^blue-gray%^BOLD%^%^BLACK%^ and %^RESET%^%^MAGENTA%^deep violet%^BOLD%^%^BLACK%^ create flowing wisps across the surface of the robe.  On either hip, a pair of pockets have been built into the robe, allowing some useful items to be kept close by.%^RESET%^
CYTHERA
	);
	set_lore(
@CYTHERA
The Wayfarer's Robe was once commonly used by the mages who worshiped Shaundakul.  Those few mages, usually young brash ones, who found more interest in exploration than spending their days in a tower,  found a need to create clothing that was comfortable and useful in their adventures.  One such mage, Telidan, came up with the design of the robes.  The pinpoint embroidery was taken from the holy symbol of The Helping Hand, so that the mages could help to spread the faith of Shaundakul.  Telidan found a need though to bind down the full sleeves of the robes, keeping them from interfering with a mage's castings.  The robes, like the Wayfarers of Shaundakul were all thought to have faded away when The Rider of the Winds seemed to have vanished from the lands.
CYTHERA
	);
	set_property("lore",12);
	set_remove("%^CYAN%^You slip out of the robe, already missing"+
		" the comfort of them.");
}
