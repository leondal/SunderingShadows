#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   "/d/shadow/room/meadows/obj/d_comb"->create_comb(TO);
}

int query_size()
{
   if(!objectp(ETO)) return 2;
   return ETO->query_size();
}
