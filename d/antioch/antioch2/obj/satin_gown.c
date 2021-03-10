#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("satin gown");
	set_short("%^BOLD%^%^BLUE%^Long satin gown%^RESET%^");
	set_id(({"gown","mina_clothing","clothing","satin gown","long satin gown","long gown","blue gown","blue satin gown","long blue gown"}));
	set_long(
	"%^BOLD%^%^BLUE%^This beautiful satin gown has been dyed a deep sapphire"+
	" shade. It is absolutely gorgeous, curving in all the right places and"+
	" tends to cling to the wearer's body. It has thin shoulder straps and is"+
	" cut in a scooped neck. The gown flows elegantly to the floor. This is"+
	" something meant for a night out, or special occassion.%^RESET%^" 
	);
	set_weight(6);
	set_value(50);
	set_ac(0);
	set_type("clothing");
	set_limbs(({"torso"}));
	set_size(2);
	set_wear((:TO,"wearme":));
}

int wearme(string str)
{
	if((string)ETO->query_gender() != "female") {
		notify_fail("This dress is for a woman.\n");
		return 0;
	}
	return 1;
}
