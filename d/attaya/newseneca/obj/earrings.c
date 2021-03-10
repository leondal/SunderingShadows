#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   "/d/attaya/newseneca/obj/base_earrings.c"->create_earrings(TO);
}

int query_size(){
   if(!objectp(ETO)) return 2;
   return ETO->query_size();
}
