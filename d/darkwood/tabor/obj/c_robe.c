//by Circe 6/7/04 for Tabor tailor, desc by Shar
#include <std.h>
inherit "/std/armour";

void create()
{
	::create();
	"/d/darkwood/tabor/obj/d_robe"->create_robe(TO);
}
