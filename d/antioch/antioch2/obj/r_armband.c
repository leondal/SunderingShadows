#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	"/d/antioch/antioch2/obj/d_armband"->create_armband(TO);
}
