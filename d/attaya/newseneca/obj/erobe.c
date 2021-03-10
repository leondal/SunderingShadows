#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
   ::create();
   "/d/attaya/newseneca/obj/base_erobe.c"->create_robe(TO);
   switch(random(7)){
      case 0..1: set_size(1);
              break;
      case 2: set_size(3);
              break;
      default: set_size(2);
               break;
   }
}