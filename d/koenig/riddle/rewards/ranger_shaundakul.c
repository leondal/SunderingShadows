//ranger_shaundakul.c - reward for Riddle Quest. Cythera 8/05
#include <std.h>
#include "../../nereid.h"
inherit NHIDE;

void create(){
	::create();
	set_name("hide");
	set_id(({"hide","windghost hide","hazy purple hide","ghost hide","hide of the windghost"}));
	set_short("%^RESET%^%^MAGENTA%^Windghost %^BOLD%^%^BLACK%^Hide%^RESET%^");
	set_obvious_short("%^RESET%^%^MAGENTA%^A hazy purple hide%^RESET%^");
	set_long(
@CYTHERA
Shaped out of a %^MAGENTA%^hazy purple%^RESET%^ hide, this suit of armor is made for comfort and ease in movement in mind.  The soft leather breastplate, sleeves, and leggings of the hide still retain their supple and flexible nature.  Faint threads of %^BOLD%^%^WHITE%^silver%^RESET%^ seem to be ingrained with the leather hide pieces, adding strength and endurance to the armor.  Across the hide, rippling wavy %^CYAN%^lines%^RESET%^ have been branded into the armor, mirroring the ripples found in %^MAGENTA%^Shaundankul's%^RESET%^ holy symbol.  Lined with %^BOLD%^%^BLACK%^dusky gray%^RESET%^ leather on the inside, the armor looks quite comfortable to wear.%^RESET%^
CYTHERA
	);
	set_lore(
@CYTHERA
The Windghost Hide is fashioned after the air elemental servants of Shaundakul.  The hide is dyed a hazy purple shade, the same color as the sacred Windghosts, in an attempt to emulate them.  Rangers have long been drawn to Shaundakul's way of life of travel and exploration, wishing to seek out new lands and be the first to discover some hidden realms.  In a sign of reverence and respect the rangers of Shaundakul rangers adopted the name Windghosts for their sect of the faith.  The armor is seen as a tremendous blessing for any ranger to receive, some claiming that it is a sign of Shaundakul's favor for their actions.
CYTHERA
	);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^MAGENTA%^You start to feel heavy and grounded once again.");
	return 1;
}
