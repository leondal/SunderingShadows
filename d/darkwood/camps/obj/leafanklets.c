#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("leaf anklets");
	set_id(({ "anklets", "leaf anklets", "anklets of leaves" }));
        set_short("%^RESET%^%^GREEN%^Anklets of Leaves%^RESET%^");
	set_long(
@AVATAR
%^GREEN%^A wide variety of leaves, ranging from oak, to mulberry, to cherry, and countless others have been woven together in a narrow band. The bands of leaves have been fashioned into a pair of dainty anklets, that would be the pride of any elven female.  A hidden clasp allows the anklets to look as if they are naturally resting on one's ankles.

AVATAR
	);
	set("read",
@AVATAR


AVATAR
	);
     set("langage","str");      set_weight(0);
	set_value(3200);
	set_lore(
@AVATAR
Made by the famed elven jeweler Elderthanal Silverspring

AVATAR
	);
	set_type("ring");
	set_limbs(({ "left leg", "right leg" }));
	set_size(2);
	set_property("enchantment",0);
}


