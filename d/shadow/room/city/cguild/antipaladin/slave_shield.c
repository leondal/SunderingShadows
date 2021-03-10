#include <std.h>
inherit "/d/common/obj/armour/shield.c";

void create()
{
	::create();
	set_name("slave shield");
	set_short("%^BOLD%^%^WHITE%^Slave Shield%^RESET%^");
	set_id(({"shield","slave shield","Slave Shield"}));
	set_long(
         "This is a shield made from the bones of dead slaves "+
         "of all races.  Crafted into the center is the skull "+
         "of a child, race unknown.  Encircling the skull is the "+
         "symbol of the guard of Tonovi."
	);
	set_weight(15);
      set_value(50);
	set_type("shield");
	set_limbs(({"right hand"}));
	set_ac(1);
	if(!random(5)) {
		set_property("enchantment",1);
	}
}
