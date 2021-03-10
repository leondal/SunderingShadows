#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	"/d/antioch/antioch2/obj/d_scarf"->create_scarf(TO);
}
