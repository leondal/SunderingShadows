#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   "/d/dagger/Torm/obj/d_necklace"->create_necklace(TO);
}

int query_size()
{
   if(!objectp(ETO)) return 2;
   return ETO->query_size();
}
