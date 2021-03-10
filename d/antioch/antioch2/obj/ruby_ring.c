#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("ruby ring");
	set_short("%^BOLD%^%^WHITE%^A %^RED%^heart-shaped ruby%^WHITE%^ ring%^RESET%^");
	set_id(({"ruby ring","ring","a ruby ring","heart-shaped ring","heart-shaped ruby ring"}));
	set_long(
	"%^WHITE%^%^BOLD%^This is a lovely %^YELLOW%^gold%^WHITE%^ ring"+
	" with a large, heart-shaped %^RED%^ruby%^WHITE%^ set into the center of it.%^RESET%^"
	);
	set_type("ring");
	set_limbs(({"left hand","right hand"}));
	set_ac(0);
	set_value(2500);
	set_weight(1);
}
