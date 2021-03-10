//Many thanks to Shar for creating this item :)
#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("kilt pin");
	set_id(({ "kiltpin","horn","kilt pin","horn pin"}));
	set_short("A %^RESET%^%^ORANGE%^horn%^RESET%^-shaped kilt pin");
	set_long(
@AVATAR
%^ORANGE%^Carved from the horn of a stag, this kilt pin is rather simple in design.  Etched into the horn is an image of a hunter, wielding two hand-axes.  Bronze wire has been used to secure the horn carving onto a long sharp pin.  Kilt pins are common among the people of Kildare Glen, to aid in keeping their kilts closed and avoid any embarassment.

AVATAR
	);
	set_weight(1);
	set_value(75);
	set_lore(
@AVATAR
An artifact from the Kildare Glen, these pieces of jewelry reflect the residents' deeply rooted connection to nature.  It is not uncommon for the residents of Kildare Glen to have passed down such items from generation to generation.

AVATAR
	);
      set_property("lore difficulty",5);
	set_type("ring");
	set_limbs(({ "right leg" }));
	set_size(2);
	set_property("enchantment",0);
}


