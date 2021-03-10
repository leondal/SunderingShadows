#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("deerskin shirt");
	set_short("%^RESET%^%^ORANGE%^A deerskin shirt%^RESET%^");
	set_id(({"deerskin shirt","shirt","deerskin top","top"}));
	set_long(
   	"%^ORANGE%^This shirt is made from the tanned hide of a deer. It is a light brown"+
	" in color and incredibly soft. The front is cut in a scoop neck shape,"+
	" with a few little leather tassels hanging down in front. It laces up"+
	" the middle, but has a double flap on the inside so that you can't see"+
	" through the laces if they aren't tight enough. It is quite pretty and"+
	" obviously made for a woman.%^RESET%^"
	);
	set_weight(3);
	set_value(40);
	set_type("clothing");
	set_limbs(({"torso"}));
	set_ac(0);
	set_wear((:TO,"wearme":));
}

int wearme(string str)
{
	if((string)ETO->query_gender() != "female") {
		notify_fail("This shirt is meant for a woman, it does not fit your"+
		" figure at all!\n");
		return 0;
	}
	else {
      tell_object(ETO,"%^ORANGE%^You slip the deerskin shirt over your head"+
		" and lace up the front.");
		return 1;
	}
}
