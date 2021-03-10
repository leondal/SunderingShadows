//pocketrobes.c

#include <std.h>

inherit "/d/common/obj/clothing/magerobe.c";

void create(){
        ::create();
        set_name("white robes");
        set_id(({"robe","robes","white robes","mage robes"}));
        set_short("%^BOLD%^%^WHITE%^White mage robes%^RESET%^");
        set_long(
@OLI
        These robes are long and flowing. You notice that in along the
folds are small openings. These robes contain pockets of fair size.
Obviously you can store things in these!
OLI
        );
   set_property("enchantment",2);
        set_weight(5);
        set_value(500);
        set_type("clothing");
        set_limbs(({"torso"}));
        set_max_internal_encumbrance(21);
        set_wear((:TO,"wear_stuff":));
}

int wear_stuff(){
       if(!TP->is_class("bard") && !TP->is_class("mage")) {
		write("%^BOLD%^%^MAGENTA%^The magic within these robes prevents you from wearing them.");
		return 0;
	}
	return 1;
}
