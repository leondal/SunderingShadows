#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("heart locket");
	set_short("%^YELLOW%^A heart locket%^RESET%^");
	set_id(({"locket","heart locket","a heart locket","gold locket"}));
	set_long(
	"%^YELLOW%^This is a beautiful gold necklace that has a heart locket attached"+
	" to the chain. The chain itself is made out of delicate strands of"+
	" gold that have been carefully woven together. The locket is of"+
   " the finest quality, and has a diagonal row of hearts etched into"+
	" the front of it.%^RESET%^"
	);
	set_weight(1);
	set_ac(0);
	set_type("ring");
	set_limbs(({"neck"}));
	set_value(1750);
}
