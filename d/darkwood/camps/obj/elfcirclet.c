//changed to type ring like other circlets so that it can be worn with coifs.  Circe 10/21/03
#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("circlet");
	set_id(({ "circlet", "elf circlet", "golden flower circlet" }));
	set_short("%^YELLOW%^Golden Flower Circlet%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^Finely woven from copper and plated in pure silver and gold, the crown is delicate and wreath like, with its complex lines referring to flowers and vines.  It is easy to tell it is of elven make due to the flowing lines that echo nature.

AVATAR
	);
        set_weight(0);
	set_value(2500);
	set_lore(
@AVATAR
The golden flower circlet is made by Elestreialna Silversprings, a jeweler and seamstress.

AVATAR
	);
	set_type("ring");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",0);
}


