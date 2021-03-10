#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   "realms/lujke/tecqumin/circe/yuan-ti_flavor.c"->create_jewelry(TO);
}

int query_size(){
   if(!objectp(ETO)) return 2;
   return ETO->query_size();
}
