//by Circe 6/1/04 for Tabor jeweler
#include <std.h>
inherit "/std/armour";

void create()
{
	::create();
	"/d/darkwood/tabor/obj/d_cufflinks"->create_cufflinks(TO);
}
