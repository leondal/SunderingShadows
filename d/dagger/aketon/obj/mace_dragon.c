#include <std.h>

inherit WEAPON;

void create(){
   ::create();
   set_name("mace of oriental dragon");
   set_id( ({"mace","mace dragon","dragon mace"}) );
   set_short("%^RESET%^%^CYAN%^Mace of oriental dragon");
   set_long("%^CYAN%^This ornate mace is the favourite weapon used by "
      "her majesty Queen Teleris of Aketon. The whole mace is forged "
      "from finest elven metal. The spikes are small but abundant. It "
      "appears somewhat shiny with a cyan metallic luster. A fire "
      "breathing oriental dragon curves around the mace from the bottom "
      "towards the metal spiked head.");
   set_wc(1,6);
   set_size(2);
   set_large_wc(1,6);
   set_type("bludgeoning");
   set_prof_type("mace");
   set_prof_level(30);
   set_weight(10);
   set_value(700);
   set_property("enchantment",4);
   set_wield( (: TO,"wield_func" :) );
   set_unwield( (: TO,"unwield_func" :) );
   set_hit( (: TO,"hit_func" :) );
}

int wield_func() {
   if( !interactive(TP) || wizardp(TP) ) return 1;
   if( (int)TP->query_level() < 25 ) return notify_fail("You are not "
      "powerful enough to master the power of the dragon.\n");
   write("%^CYAN%^The dragon becomes alive and moves to fit your hand "
      "perfectly as you hold the mace tight.");
   return 1;
}

int unwield_func() {
   write("%^CYAN%^You sense the life force of the dragon diminish.");
   return 1;
}

int hit_func(object vic) {
   if(!random(10)) {
      tell_object(ETO,"%^CYAN%^The dragon on your mace flames at "+
         vic->query_cap_name()+"!");
      tell_object(vic,"%^CYAN%^The dragon on the mace wielded by "+
         ETO->query_cap_name()+" flames at you!");
      tell_room(environment(query_wielded()),"%^CYAN%^The dragon on the "
         "mace wielded by "+ETO->query_cap_name()+" flames at "+
         vic->query_cap_name()+"!",({vic,ETO}));
      return roll_dice(3,5);
   }
   if(!random(40)) {
      tell_object(ETO,"%^CYAN%^The dragon on your mace flames at "+
         vic->query_cap_name()+"'s hands!");
      tell_object(vic,"%^CYAN%^The dragon on the mace wielded by "+
         ETO->query_cap_name()+" flames at your hands!");
      tell_room(environment(query_wielded()),"%^CYAN%^The dragon on the "
         "mace wielded by "+ETO->query_cap_name()+" flames at "+
         vic->query_cap_name()+"'s hands!",({vic,ETO}));
      vic->query_wielded()->unequip();
      return roll_dice(3,4);
   }
   if(!random(70)) {
      tell_object(ETO,"%^CYAN%^The dragon on your mace flames at "+
         vic->query_cap_name()+"'s body!");
      tell_object(vic,"%^CYAN%^The dragon on the mace wielded by "+
         ETO->query_cap_name()+" flames at your body!");
      tell_room(environment(query_wielded()),"%^CYAN%^The dragon on the "
         "mace wielded by "+ETO->query_cap_name()+" flames at "+
         vic->query_cap_name()+"'s body!",({vic,ETO}));
      vic->all_armour()->unequip();
      return roll_dice(3,3);
   }
   return roll_dice(2,3);
}
