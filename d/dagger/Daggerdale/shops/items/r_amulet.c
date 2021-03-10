#include <std.h>
inherit ARMOUR;

void create()
{
   ::create();
   "/d/dagger/Daggerdale/shops/items/d_amulet"->create_amulet(TO);
}

int query_size()
{
   if(!objectp(ETO)) return 2;
   return ETO->query_size();
}
