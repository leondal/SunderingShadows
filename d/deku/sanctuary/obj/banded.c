//Updated to bring in line with area difficulty - Octothorpe 4/15/10

#include <std.h>
inherit "/d/common/obj/armour/banded.c";
void create(){
	::create();
	set_name("banded armor");
	set_id(({ "banded", "banded armor", "armor", "oak banded", "oak", "oak armor", "oak banded armor" }));
	set_short("%^RESET%^%^ORANGE%^Banded Armor of the Oak%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A suit of banded oak armor%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This banded armor has been made with the combination of hardy oak and copper. The oak plates have been carefully warped so they might provide plenty of room for one to slip into it. Copper plates have been attached to the oak, adding to the rich color of the wood.

AVATAR
	);
        set_value(9000);
	set_lore(
@AVATAR
Banded Armor of the Oak's existance is unknown. Some claim it was first crafted by priests of Malar, utilizing the home of a dryad, in honor of their god and as a slight to Mielikki, who is the protector of dryads. Others claim that The Lady of the Forest herself whispered the secrets to her faithful of how to craft such armor. Either way it is seen both as a holy relic to both faiths.

AVATAR
	);
        set_property("enchantment",3+random(2));
	  set_property("lore",11);
}


