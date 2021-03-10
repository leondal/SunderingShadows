#include <std.h>
inherit "/d/common/obj/armour/leather.c";

void create() {
    	::create();
    	set_name("drow leather");
	set_id(({ "leather","leather armor", "armor", "armour","drow leather" }));
        set_short("%^BLUE%^%^BOLD%^drow leather armor%^RESET%^");
        set_obvious_short("%^BLACK%^%^BOLD%^darkened leather armor%^RESET%^");
    	set_long(
		"%^BOLD%^%^BLUE%^"+
		"This is black leather armor made for drow by drow.  This armor is made "+
		"of black leather of an unknown animal , hardened in boiling oil and then "+
		"shaped into breastplate and shoulder protectors. The rest of the "+
    		"suit is made of softer, more flexible materials.\n"+
    		"%^RESET%^"
       );
      set_lore("Made by a drow craftsman, this leather armor "+
         "is often worn by drow scouts in the underdark.  The "+
         "leather is said to be hardened roethe hide.  Roethe are "+
         "the cattle of the underdark, and drow often keep large "+
         "numbers of them in the larger caverns.");
      set_property("lore difficulty",3);
    	set_weight(15);
    	set("value", 5);
    	set_type("leather");
    	set_limbs( ({ "torso" }) );
    	set_ac(2);
}
