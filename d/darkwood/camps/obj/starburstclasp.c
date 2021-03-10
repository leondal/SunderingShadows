#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("starburst clasp");
        set_id(({ "starburst clasp", "cloak clasp", "starburst cloak clasp", "clasp" }));
	set_short("%^BOLD%^%^BLUE%^A starburst shaped cloak clasp%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^A starburst shaped cloak clasp%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^This elven cloak clasp is elaborately engraved in sterling silver and painted with layers of transparent blue resin. This one takes the shape of a chaotic sixpointed starburst. Graceful curls of silver wire further add to the elven beauty of this piece of jewelry.

AVATAR
	);
        set_weight(0);
	set_value(2000);
	set_lore(
@AVATAR
Made by the famed elven jewerler Elderthanal Silverspring

AVATAR
	);
	set_type("ring");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",0);
}


