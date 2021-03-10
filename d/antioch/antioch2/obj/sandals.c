#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("sandals");
	set_short("%^RESET%^%^ORANGE%^A pair of sandals%^RESET%^");
	set_id(({"sandals","pair of sandals","leather sandals","brown sandals"}));
	set_long(
	"%^ORANGE%^These are a pair of leather sandals. The bottom has been cut from a strip"+
	" or harder leather, and there are criss-crossing straps that loop over"+
	" the foot and can be buckled around the ankle for a good fit.%^RESET%^"
	);
	set_weight(2);
	set_value(8);
	set_ac(0);
	set_type("clothing");
	set_limbs(({"right foot","left foot"}));
}
