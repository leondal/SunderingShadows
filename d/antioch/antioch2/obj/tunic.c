#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("leather tunic");
	set_short("%^RESET%^%^ORANGE%^A leather tunic%^RESET%^");
	set_id(({"tunic","leather tunic","brown leather tunic"}));
	set_long(
	"%^ORANGE%^This tunic has been cut from brown leather. It is finely crafted from"+
	" high quality leather. It gives a little bit of protection to the"+
	" wearer.%^RESET%^"
	);
	set_weight(5);
	set_value(10);
	set_ac(1);
	set_type("clothing");
	set_limbs(({"torso"}));
}
