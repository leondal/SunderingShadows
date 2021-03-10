#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("moonstone pendant");
	set_short("%^BOLD%^%^WHITE%^A moonstone pendant%^RESET%^");
	set_id(({"pendant","moonstone pendant","a moonstone pendant"}));
	set_long(
	"%^BOLD%^%^WHITE%^This lovely moonstone pendant dangles from a chain made of braided"+
	" silver. The moonstone has been polished into a round sphere, in"+
	" the very center of which is a milky white crescent moon.%^RESET%^"
	);
	set_weight(2);
	set_type("ring");
	set_limbs(({"neck"}));
	set_value(920);
	set_ac(0);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
}

int wearme()
{
	if((string)TP->query_diety() == "selune") {
		tell_object(TP,"%^BOLD%^You feel a warmth wash over you as you"+
		" slip the pendant around your neck.");
		return 1;
	}
	return 1;
}

int removeme()
{
	if((string)TP->query_diety() == "selune") {
		tell_object(TP,"As you remove the moonstone pendant a slight"+
		" chill washes over you.");
		return 1;
	}
	return 1; 
}
