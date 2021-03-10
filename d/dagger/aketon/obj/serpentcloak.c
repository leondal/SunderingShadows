#include <std.h>

inherit ARMOUR;

void create() {
   ::create();
   set_name("cloak of serpent");
   set_id( ({"cloak","serpent","serpent cloak"}) );
   set("short","%^BOLD%^%^BLUE%^serpent cloak");
   set("long","%^BOLD%^%^BLUE%^The cloak is sewed from many large serpent "
       "scales. It feels hard to the touch. When you move, it gives out some "
      "clinky sound.");
   set_weight(6);
   set_type("clothing");
   set_limbs( ({"neck"}) );
   set_ac(0);
   set_value(2000);
   set_property("enchantment",random(2)+2);
   set_wear( (: TO,"wear_func" :) );
   set_remove( (: TO,"remove_func" :) );
}

int wear_func() {
   write("%^BOLD%^%^BLUE%^The serpent scales clink against each other.");
   return 1;
}

int remove_func() {
   write("%^BOLD%^%^BLUE%^The serpent scales clink against each other.");
   return 1;
}
