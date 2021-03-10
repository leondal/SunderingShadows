#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("breeches");
	set_short("%^RESET%^%^ORANGE%^Brown leather breeches%^RESET%^");
	set_id(({"breeches","leather breeches","brown leather breeches","brown breeches"}));
	set_long(
	"%^ORANGE%^These leather breeches have been carefully tanned. The outside has been"+
	" allowed to harden, while the inside has been kept soft. This allows"+
	" the wearer to be partially protected while also comfortable.%^RESET%^"
	);
	set_weight(4);
	set_value(8);
	set_ac(0);
	set_type("clothing");
	set_limbs(({"right leg","left leg"}));
}
