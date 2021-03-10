#include <std.h>
inherit "/std/armour";

void create()
{
	::create();
	set_name("cyan tunic");
	set_short("%^CYAN%^Cyan Tunic%^RESET%^");
	set_id(({"tunic","cyan tunic","Cyan Tunic"}));
	set_long(
         "This tunic has been crafted from a cyan cotton blend "+
         "and has been woven with thread created from the hair of "+
         "slaves.  The symbol of the guard of Tonovi has been sewn "+
         "onto the front of the tunic."
	);
	set_weight(8);
      set_value(30);
 	set_type("clothing");
	set_limbs(({"torso"}));
	set_ac(1);
	if(!random(5)) {
		set_property("enchantment",1);
	}
}
