#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_wear((:TO,"wearme":));
	"/d/antioch/antioch2/obj/d_skirt"->create_skirt(TO);
}

int wearme(string str)
{
	if((string)TP->query_gender() != "female") {
		notify_fail("This skirt was made for a woman!\n");
		return 0;
	}
	return 1;
}
