#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("tall boots");
	set_short("%^BOLD%^%^BLACK%^Tall black boots%^RESET%^");
	set_id(({"boots","black boots","high boots","tall boots","tall black boots"}));
	set_long(
	"%^BOLD%^%^BLACK%^These tall boots reach up to knee height. They have been dyed black"+
	" and hardened. There are laces on the sides to tighten them. They are"+
	" very protective, good for walking through brambled areas, and waterproofed"+
	" to better withstand rivers and swamps.%^RESET%^"
	);
	set_weight(4);
	set_value(30);
	set_type("clothing");
	set_limbs(({"right foot","left foot"}));
	set_wear("You lace up the tall boots as you put them on.");
	set_remove("You unlace the boots and remove them.");
	set_ac(0);
}
