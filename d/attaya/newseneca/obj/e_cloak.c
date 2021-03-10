#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   "/d/attaya/newseneca/obj/e_cloak_base.c"->create_cloak(TO);
   set_size(2);
}
