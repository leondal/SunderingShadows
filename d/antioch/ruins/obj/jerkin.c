#include <std.h>
#include "../ruins.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("leather jerkin");
	set_short("A leather jerkin");
	set_id(({"leather jerkin","jerkin"}));
	set_long(
	"%^RESET%^%^GREEN%^The jerkin is made out of a light piece of hide and"+
	" has been dyed an olive green shade. It is sleeveless and covers the"+
	" torso, with a few laces in the front that can be tied.%^RESET%^" 
	);
	set_type("clothing");
	set_weight(5);
	set_size(2);
	set_limbs(({"torso"}));
	set_value(5);
	if(!random(5)) {
                set_property("enchantment",2);
	}
}
