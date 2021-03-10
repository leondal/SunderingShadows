//Updated to bring in line with area difficulty - Octothorpe 4/15/10
//pocketrobes.c

#include <std.h>

inherit "/d/common/obj/clothing/magerobe.c";

void create(){
        ::create();
        set_name("red robes");
        set_id(({"robe","robes","black robes","mage robes"}));
        set_short("%^BOLD%^%^RED%^Red mage robes%^RESET%^");
		set_long("%^BOLD%^%^RED%^These robes are made from an elegant "+
		   "yet unknown fabric.  They are long and flowing and are lined "+
		   "with a metallic %^RESET%^s%^BOLD%^i%^RESET%^lv%^BOLD%^e"+
		   "%^RESET%^r %^BOLD%^%^RED%^thread.  There are various "+
		   "pockets found within the folds of the robe, no doubt "+
		   "allowing one to secret away various object of import.%^RESET%^");   		
        /*set_long(
@OLI
        These robes are long and flowing. You notice that in along the
folds are small openings. These robes contain pockets of fair size.
Obviously you can store things in these!
OLI
        );*/
//        set_ac(2);
        set_property("enchantment",3);
        set_weight(5);
        set_value(500);
        set_type("clothing");
        set_limbs(({"torso"}));
        set_max_internal_encumbrance(21);
        set_wear((:TO,"wear_stuff":));
}
