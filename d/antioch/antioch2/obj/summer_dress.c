#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("summer dress");
	set_short("%^YELLOW%^A summer dress%^RESET%^");
	set_id(({"dress","mina_clothing","summer dress","cotton dress","lemon dress","yellow dress","daisy dress"}));
	set_long(
	"%^YELLOW%^This is a cotton summer dress. It is good for wearing on hot"+
	" days, for it is quite cool. It is a pretty lemon shade and has a"+
	" daisy pattern in lighter yellow on it. The hem of the dress comes down"+
	" to just above the wearer's knees."
	);
	set_weight(4);
	set_value(16);
	set_ac(0);
	set_type("clothing");
	set_limbs(({"torso"}));
	set_size(2);
	set_wear((:TO,"wearme":));
}

int wearme(string str)
{
	if((string)ETO->query_gender() != "female") {
		notify_fail("This is a woman's dress.\n");
		return 0;
	}
	return 1;
}
