//adapted from Antioch gear, descriptions by Lusell.  Circe 3/23/04
#include <std.h>
inherit "/std/armour";

void create()
{
	::create();
	set_name("cyan robes");
	set_short("%^CYAN%^Dark Cyan Robes%^RESET%^");
	set_id(({"robes","cyan robes","Cyan Robes"}));
	set_long(
	"%^CYAN%^These robes are worn by the appointed guard of "+
      "Tonovi. They are fashioned from the finest silk and lined "+
      "with the softest cotton.%^RESET%^"
	);
	set_weight(8);
      set_value(35);
	set_type("clothing");
	set_limbs(({"torso"}));
	set_ac(1);
	if(!random(5)) {
		set_property("enchantment",1);
	}
}
