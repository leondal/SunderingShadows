#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("leather jacket");
	set_short("%^RESET%^%^ORANGE%^A leather jacket%^RESET%^");
	set_id(({"jacket","leather jacket"}));
	set_long(
	"%^ORANGE%^This is a jacket carefully made from the best leather.  It is flexible"+
	" as well as durable and has been slightly waterproofed.  The jacket"+
	" is a rich brown color and is of the finest quality.%^RESET%^"
	);
	set_weight(7);
	set_value(100);
	set_ac(0);
	set_type("clothing");
	set_limbs(({"torso"}));
}
