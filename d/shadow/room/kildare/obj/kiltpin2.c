//many thanks to Shar for creating this item :)
#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("kilt pin");
	set_id(({"kilt pin","pin","dragon pin"}));
	set_short("A kilt pin in the shape of a dragon");
	set_long(
@AVATAR
Fashioned out of silver, this kilt pin is in the image of a dragon raised up in flight.  An open weave geometical braid travels across the body of the dragon.  Though the image of the dragon is a bit crude, the effect is still the same.  A sharp pin backs the dragon image.  Kilt pins are common among the men of Kildare Glen to avoid any embarassing moments.

AVATAR
	);
	set_weight(1);
	set_value(75);
	set_lore(
@AVATAR
An artifact from the Kildare Glen, these pieces of jewelry reflect the resident's deeply rooted connection to nature.  It is not uncommon for the residents of Kildare Glen to have passed down such items from generation to generation.

AVATAR
	);
      set_property("lore difficulty",5);
 	set_type("ring");
	set_limbs(({ "right leg" }));
	set_size(2);
	set_property("enchantment",0);
}


