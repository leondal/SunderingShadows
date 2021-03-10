//changed to type ring like other circlets so that it can be worn with coifs.  Circe 10/21/03
#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("water lily circlet");
	set_id(({ "circlet", "water lily", "water lily circlet" }));
	set_short("%^BOLD%^%^WHITE%^Water Lily Circlet%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^Water Lily Circlet%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^Finely woven from silver and platinum, the crown is delicate and wreath-like, with its complex lines that flow together. Images of still ponds and water lilys have been etched into the metal. It is easy to tell it is of elven make due to the flowing lines that echo nature.

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
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",0);
}


