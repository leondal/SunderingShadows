#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("leather gloves");
	set_short("%^BOLD%^%^BLACK%^Black leather gloves%^RESET%^");
	set_id(({"glove","leather gloves","black gloves","black leather gloves","gloves"}));
	set_long(
	"%^BOLD%^%^BLACK%^These fine leather gloves are very soft. They have been made from high"+
	" quality leather and dyed a deep black. They fit snugly and reach up"+
	" to just beyond the elbow.%^RESET%^"
	);
	set_weight(2);
	set_value(16);
	set_type("clothing");
	set_limbs(({"right arm","left arm"}));
	set_ac(0);
}
