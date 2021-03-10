#include <std.h>

inherit "/d/common/obj/weapon/dagger.c";

void create(){
   ::create();
   set_property("enchantment", 4);
}
