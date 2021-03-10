#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("cloud cloak clasp");
	set_id(({ "clasp", "cloak clasp", "cloud clasp", "cloud cloak clasp" }));
	set_short("%^BOLD%^%^WHITE%^A cloud shaped cloak clasp%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A cloud shaped cloak clasp%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^
%^BOLD%^%^WHITE%^The elven clasps are elaborately engraved in silver. This one is in the shape of a cloud. The metal has been cut in alternate directions to give added depth and texture to the cloud. It almost seems as if shimmering drops of silver rain are coming from the cloud itself. Graceful curls of silver wire add to the elven beauty of this piece of jewelry.

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
	set_ac(0);
}


