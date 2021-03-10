#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("leaf clasp");
	set_id(({ "clasp", "cloak clasp", "leaf", "leaf clasp" }));
	set_short("%^RESET%^%^GREEN%^A cloak clasp in the shape of a leaf%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^GREEN%^This elven clasp is elaborately engraved in silver. This one is in the shape of a leaf. Green resin has been layered on top of the silver to give added depth to the leaf. The silver veins of the leaf can be clearly seen. Graceful curls of silver wire add to the elven beauty of this piece of jewelry.

AVATAR
	);
        set_weight(0);
	set_value(1000);
	set_lore(
@AVATAR
Made by the famed elven jeweler, Silversprings.

AVATAR
	);
	set_type("ring");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",0);
}


