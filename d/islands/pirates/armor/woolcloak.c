#include <std.h>

inherit ARMOUR;

void create() {
   ::create();
   set_name("fine woolen cloak");
   set_id( ({"cloak","woolen cloak"}) );
   set("short","%^RESET%^%^ORANGE%^A woolen cloak%^RESET%^");
   set("long","%^ORANGE%^This cloak is very tightly woven of delicate woolen "
      "fibers and dyed a soft brown.  It is warm in winter because the wool "
      "doesn't feel cold to the touch and yet is thin enough to breathe "
      "and be comfortable in summer also.  The tailoring is outstanding and "
      "it appears to be treated to resist water and other elements." );
   set_weight(3);
   set_type("clothing");
   set_limbs( ({"neck"}) );
   set_ac(0);
   set_property("enchantment",2);
   set_value(500+random(2)*750);
   set_wear( (: TO,"wear_func" :) );
   set_remove( (: TO,"remove_func" :) );
}

int wear_func() {
   write("%^ORANGE%^The cloak fits itself to your shoulders and feels wonderful.");
   TP->set_property("magic resistance",10);
   return 1;
}

int remove_func() {
   write("%^ORANGE%^You miss the feel of the soft wool.");
   ETO->set_property("magic resistance",-10);
   return 1;
}
