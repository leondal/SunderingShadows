#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("short boots");
	set_short("%^BOLD%^%^BLACK%^Short gray boots%^RESET%^");
	set_id(({"boots","short boots","gray boots","short gray boots"}));
	set_long(
	"%^BOLD%^%^BLACK%^These are a pair of short boots. They reach just above the ankle"+
	" and are rather soft. They are of a suede material and have been"+
	" dyed charcoal gray. They are quite comfortable, if not very good"+
	" for adventuring.%^RESET%^"
	);
	set_weight(2);
	set_value(20);
	set_type("clothing");
	set_limbs(({"right foot","left foot"}));
	set_ac(0);
}
