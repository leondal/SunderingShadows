#include <std.h>
inherit "/std/armour";

void create()
{
	::create();
	set_name("red robes");
	set_short("%^BOLD%^%^RED%^Red Robes%^RESET%^");
	set_id(({"robes","red robes","Red Robes"}));
	set_long(
	"%^BOLD%^%^RED%^These red robes are worn by the royal guard of Antioch."+
	" They have been fashioned from quilted layers of cloth and batting, with"+
	" a layer of red silk over all of it.%^RESET%^"
	);
	set_weight(8);
        set_size(-1);
        set_value(35);
	set_type("clothing");
	set_limbs(({"torso"}));
	set_ac(1);
	if(!random(5)) {
		set_property("enchantment",1);
	}
}
