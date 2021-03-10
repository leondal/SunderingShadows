#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("colorful scarf");
	set_short("%^BOLD%^%^WHITE%^A %^RED%^c%^YELLOW%^o%^MAGENTA%^l%^YELLOW%^o%^GREEN%^r%^CYAN%^f%^YELLOW%^u%^MAGENTA%^l%^WHITE%^ scarf%^RESET%^");
	set_id(({"scarf","colorful scarf","silk scarf","mina_clothing","colorful silk scarf"}));
	set_long(
	"%^BOLD%^%^WHITE%^This %^RED%^c%^YELLOW%^o%^MAGENTA%^l%^YELLOW%^o%^GREEN%^r%^CYAN%^f%^YELLOW%^u%^MAGENTA%^l%^WHITE%^"+
	" scarf is made from silk. It has been dyed in a series of beautiful"+
	" colors, one leading into the next. It is soft and smooth to the touch,"+
	" feeling absolutely wonderful against your skin."
	);
	set_weight(1);
	set_value(24);
	set_ac(0);
	set_type("ring");
	set_limbs(({"neck"}));
	set_size(2);
    set_property("repairtype",({ "tailor" }));
}
