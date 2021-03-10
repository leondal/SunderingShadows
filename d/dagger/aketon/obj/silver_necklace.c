#include "/d/dagger/aketon/short.h"

inherit ARMOUR;

create() {
   ::create();
   set_name("silver necklace");
   set_id( ({"necklace","silver","silver necklace"}) );
   set_short("%^RESET%^%^BOLD%^Silver necklace%^RESET%^");
   set_long("%^BOLD%^This is a beautiful necklace made of pure silver. "
       "It is a small chain made with the finest quality and craftsmanship. "
       "A slight arua emanates from it.");
   set_weight(5);
   set_value(5000);
   set_type("clothing");
   set_limbs( ({"neck"}) );
   set_ac(0);
   set_property("enchantment",4);
   set_wear( (: TO,"wear_func" :) );
   set_remove( (: TO,"remove_func" :) );
   set_heart_beat(0);
}

int wear_func() {
   int hold;
   if(!interactive(TP))
      return 1;
   set_name("silver necklace of strangulation");
   set_short("%^RESET%^%^BOLD%^Silver necklace of strangulation");
   set_long("%^BOLD%^This is a beautiful necklace made of pure silver. "
       "It is a small chain made with the finest quality and craftsmanship. "
       "A strong arua of evilness emanates from it. You wonder how to remove "
      "it.");
   set_value(0);
   if(query_property("enchantment") >= 0) {
      hold = (int)query_property("enchantment");
      set_property("enchantment",-(hold + 2));
   }
   set_heart_beat(1);
   return 1;
}

int remove_func() {
   int hold;
   if(!interactive(TP))
      return 1;
   set_name("silver necklace");
   set_short("%^RESET%^%^BOLD%^Silver necklace");
   set_long("%^BOLD%^This is a beautiful necklace made of pure silver. "
       "It is a small chain made with the finest quality and craftsmanship. "
       "A slight arua emanates from it.");
   set_value(5000);
   if(query_property("enchantment") < 0) {
      hold = -(int)query_property("enchantment");
      set_property("enchantment",hold + 4);
   }
   set_heart_beat(0);
   return 1;
}

void heart_beat() {
   if( !objectp(ETO) || !objectp(TO) )
      return;
   if(query_worn() == ETO) {
      set_property("magic",1);
       tell_object(ETO,"%^BOLD%^The necklace you're wearing constricts!");
      query_worn()->do_damage("neck",6);
      ETO->add_attacker(TO);
      ETO->continue_attack();
      ETO->remove_attacker(TO);
      remove_property("magic");
   }
   return;
}
