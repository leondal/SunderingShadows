//by Circe 6/1/04 for Tabor tailor, desc by Shar
#include <std.h>
inherit "/std/armour";

void create()
{
	::create();
	"/d/darkwood/tabor/obj/d_vest"->create_vest(TO);
}
