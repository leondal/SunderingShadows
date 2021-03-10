#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
   ::create();
   "/d/attaya/newseneca/obj/base_pcloak.c"->create_cloak(TO);
   switch(random(5)){
      case 0: set_size(1);
              break;
      case 1: set_size(3);
              break;
      default: set_size(2);
               break;
   }
}