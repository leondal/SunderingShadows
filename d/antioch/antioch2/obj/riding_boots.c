#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("riding boots");
	set_short("%^RESET%^%^ORANGE%^Leather riding boots%^RESET%^");
	set_id(({"boots","riding boots","leather riding boots","pair of boots"}));
	set_long(
	"%^ORANGE%^These are a pair of riding boots. They have been dyed dark brown and"+
	" have high sides to protect the rider's legs. The outsides are stiff"+
	" to keep from wearing down, but the insides have been cushioned to be"+
	" soft and comfortable.%^RESET%^"
	);
	set_weight(4);
	set_value(25);
	set_type("clothing");
	set_limbs(({"right foot","left foot"}));
	set_ac(0);
}
