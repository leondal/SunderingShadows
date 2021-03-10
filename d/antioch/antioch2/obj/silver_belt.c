#include <std.h>
inherit "/std/armour";

void create()
{
	::create();
	set_name("silver belt");
	set_short("%^BOLD%^%^WHITE%^Silver Belt%^RESET%^");
	set_id(({"belt","silver belt","Silver Belt"}));
	set_long(
	"%^BOLD%^%^WHITE%^This belt has been dyed a gray color and polished with a silver powder"+
	" to give it a high shine. The buckle does seem to be made out of silver"+
	" and the image of a pegasus is etched onto it.%^RESET%^"
	);
	set_weight(3);
	set_value(1);
	set_type("ring");
	set_limbs(({"waist"}));
	set_ac(0);
    set_property("repairtype",({ "tailor" }));
}
