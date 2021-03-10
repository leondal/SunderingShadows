#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	"/d/antioch/antioch2/obj/d_broach"->create_broach(TO);
}

int query_size()
{
   if(!objectp(ETO)) return 2;
   return ETO->query_size();
}
