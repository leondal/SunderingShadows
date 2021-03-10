//pocketrobes.c

#include <std.h>

inherit PARMOUR;

void create(){
        ::create();
        set_name("ratty robe");
        set_id(({"robe","robes","ratty robes","ratty robe","mage robes"}));
        set_short("%^BOLD%^%^BLACK%^A ratty robe%^RESET%^");
        set_long(
@CIRCE
This robe was once long and flowing but now ends raggedly well above 
where the hem once was.  The sleeves have been cut off jaggedly, and 
it is difficult to tell what color the robe is supposed to be, though 
it seems to be a muted gray.  The fabric is coated with a thin layer 
of muck and dirt, and a musty smell has permeated it through.
CIRCE
        );
        set_ac(0);
        set_weight(5);
        set_value(25);
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
      tell_object(ETO,"You slip on the robes and find pockets "+
         "in the seams.");
	return 1;
}
