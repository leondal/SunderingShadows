//mage_talos.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("robe of the violent storm");
	set_id(({ "robe", "robe of the violent storm" }));
	set_short("%^BOLD%^%^BLACK%^Robe of the %^WHITE%^Violent %^BLUE%^St%^CYAN%^o%^BLUE%^rm%^RESET%^");
	set_obvious_short("A jagged robe");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^Black cotton was used in the creation of this robe.  The robe is unlike most other robes, as it looks like one slips into it like a shirt.  The robe's edges are cut in a jagged angular fashion, in the manner of a lightning bolt.  The length of the sleeves and hem of the robe vary from short to long and bear no order to their design, looking very chaotic.  The edges are trimmed with %^WHITE%^silver%^BLACK%^ metallic threads to give a flashing apperance to the lighting edges.  A cluster of %^BLUE%^blue%^BLACK%^ glass beads hangs from cords in a tear drop shape, flowing however they wish.

AVATAR
	);
	set_lore(
@AVATAR
The Robe of the Violent Storm was first crafted by Mad Marigold, a Talosian half-elf wizardly priestess.  Mad Marigold delighted in nothing more than conjuring up violent storms to spread the destruction of her Lord.  Mad Marigold had a successful, but brief career in Talos' faith.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^BOLD%^%^BLACK%^You slip out of the robe");
	return 1;
}
