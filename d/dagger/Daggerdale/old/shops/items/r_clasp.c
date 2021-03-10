#include <std.h>
inherit ARMOUR;

void create()
{
	::create();
	"/d/dagger/Daggerdale/shops/items/d_clasp.c"->create_clasp(TO);
}
