//many thanks to shar for creating this item :)
#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("torque");
	set_id(({ "torque","copper torque"}));
	set_short("A copper torque");
	set_long(
@AVATAR
This torque, a thick heavy neck ring, is crafted out of copper.  The copper has been aged to a soft silvery green color in most spots.  A vine of ivy fashioned out of the metal wraps around the neck ring.  Detailed leaves have been carved with loving care.  At each end of the torque, two rounded pieces of moss agate are sercured in place.

AVATAR
	);
	set_weight(3);
	set_value(175);
	set_lore(
@AVATAR
An artifact from the Kildare Glen, these pieces of jewelry reflect the resident's deeply rooted connection to nature.  It is not uncommon for the residents of Kildare Glen to have passed down such items from generation to generation.

AVATAR
	);
      set_property("lore difficulty",6);
	set_type("ring");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",0);
}


