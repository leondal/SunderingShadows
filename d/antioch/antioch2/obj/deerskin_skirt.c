#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("deerskin skirt");
	set_short("%^RESET%^%^ORANGE%^A deerskin skirt%^RESET%^");
	set_id(({"deerskin skirt","skirt","leather skirt"}));
	set_long(
	"%^ORANGE%^This skirt has been made from soft deerskin that was carefully tanned."+
	" It is a light brown shade, and very soft to the touch. It laces up"+
	" on either side and comes to just above the knees. It is quite lovely"+
	" and would be flattering on a pretty figure.%^RESET%^"
	);
	set_weight(3);
	set_type("ring");
	set_limbs(({"waist"}));
	set_value(60);
	set_ac(0);
	set_wear((:TO,"wearme":));
    set_property("repairtype",({ "armorsmith" }));
}

int wearme(string str)
{
	if((string)ETO->query_gender() != "female") {
		notify_fail("This skirt is meant for a woman, it does not fit your"+
		" figure at all!\n");
		return 0;
	}
	else {
      tell_object(ETO,"%^ORANGE%^You slip into the deerskin skirt and lace"+
		" up the sides.");
		return 1;
	}
}
