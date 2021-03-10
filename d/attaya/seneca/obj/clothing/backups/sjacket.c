#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
   ::create();
   "/d/attaya/seneca/obj/clothing/base_jacket.c"->create_doublet(TO);
   switch(random(7)){
      case 0..1: set_size(1);
              break;
      case 2: set_size(3);
              break;
      default: set_size(2);
               break;
   }
}