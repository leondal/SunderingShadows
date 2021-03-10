#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("glittering diadem");
	set_short("%^BOLD%^%^WHITE%^A glittering r%^RESET%^h%^BOLD%^"+
		"i%^RESET%^n%^BOLD%^e%^RESET%^s%^BOLD%^t%^RESET%^o%^BOLD%^"+
		"n%^RESET%^e diadem%^RESET%^");
	set_id(({"diadem","rhinestone diadem","glittering diadem","glittering rhinestone diadem"}));
	set_long(
	"%^BOLD%^%^WHITE%^This diadem is made out of silver. The front part is set with"+
	" rows of glittering rhinestones, with a large oval shaped one"+
	" in the center of the diadem. It is a bit gaudy, but might be"+
	" worn for a fancy, festive occasion."
	);
	set_weight(2);
	set_ac(0);
	set_value(1250);
	set_type("ring");
	set_limbs(({"head"}));
}
