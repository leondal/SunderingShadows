#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("earcuff");
	set_id(({ "earcuff" }));
	set_short("%^YELLOW%^E%^RESET%^%^ORANGE%^a%^YELLOW%^r%^RESET%^%^ORANGE%^c%^YELLOW%^u%^RESET%^%^ORANGE%^f%^YELLOW%^f%^RESET%^");
	set_obvious_short("%^YELLOW%^E%^RESET%^%^ORANGE%^a%^YELLOW%^r%^RESET%^%^ORANGE%^c%^YELLOW%^u%^RESET%^%^ORANGE%^f%^YELLOW%^f%^RESET%^");
	set_long(
@AVATAR
%^ORANGE%^Made up of braided pieces of copper and gold, this elaborate earcuff is without a doubt elven made.  The vine like pattern that the metal has been shaped into almost looks life like. It is not uncommon to see elves wearing one or more earcuffs.

AVATAR
	);
	set("read",
@AVATAR


AVATAR
	);
     set("langage","str");      set_weight(0);
	set_value(1500);
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


