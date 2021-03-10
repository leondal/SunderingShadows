#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_wear((:TO,"wearme":));
	"/d/antioch/antioch2/obj/d_shirt"->create_shirt(TO);
}

int wearme(string str)
{
	if((string)TP->query_gender() != "male") {
		notify_fail("This shirt was made for a man!\n");
		return 0;
	}
	return 1;
}
