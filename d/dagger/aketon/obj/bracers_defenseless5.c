#include "/d/dagger/aketon/short.h"

inherit ARMOUR;

int luck_count,flag;

void create() {
   ::create();
   set_id( ({"bracers"}) );
   set_name("Bracers of Defense");
   set_short("Bracers of Defense");
   set_long("A set of high quality bracers. They feel magically light "
      "and provide a great protection.");
   set_type("bracer");
   set_limbs( ({"torso"}) );
   set_weight(5);
   set_value(2500);
   set_ac(3);
   set_property("enchantment",2);
   while(query_property("enchantment") < 0) {
      remove_property("enchantment");
      set_property("enchantment",2);
   }
   set_property("no remove",1);
   set_wear( (: TO,"wear_func" :) );
   set_remove( (: TO,"remove_func" :) );
   set_heart_beat(0);
   luck_count = roll_dice(5,6) + 60;
   flag = 1;
}

int wear_func() {
   if(!interactive(TP))
      return 1;
   if(!TP->is_class("mage") && !TP->is_class("bard") &&
   !TP->is_class("thief") && !TP->is_class("assassin") && !TP->is_class("ranger")) {
       write("Your class doesn't allow you to use this.");
      return 0;
   }
   set_heart_beat(1);
   return 1;
}

int remove_func() {
   set_heart_beat(0);
   return 1;
}

void heart_beat() {
   int dex_bonus;
   if( !objectp(ETO) || !objectp(TO) )
      return;
   if(sizeof(ETO->query_attackers()) <= 0)
      return;
   if(sizeof(ETO->query_attackers()) > 0 && luck_count > 0) {
      luck_count--;
      return;
   }
   if(sizeof(ETO->query_attackers()) > 0 && luck_count < 1 && flag) {
      add_id( ({"defenselessness","defenseless"}) );
      set_name("Bracers of Defenselessness");
      set_short("Bracers of Defenselessness");
      set_long("A set of cursed bracers of defenselessness. They feel real "
         "heavy and lay a real bad curse on the wearer. The only way to "
         "remove them is DEATH!");
      set_weight(30);
      ETO->add_encumbrance(25);
      set_value(0);
      set_property("enchantment",-4);
      while(query_property("enchantment") > 0) {
         remove_property("enchantment");
         set_property("enchantment",-2);
      }
       tell_object(ETO,"%^RED%^You sense the magic arua radiating from "
          "your Bracers of Defense alter!\n"
         "%^BOLD%^%^BLUE%^You feel an awfully deep curse on you...");
      flag = 0;
   }
   if(query_property("enchantment") < 0) {
      ETO->set_overall_ac(10);
      if( dex_bonus = ((int)ETO->query_stats("dexterity") - (int)ETO
      ->query_base_stats("dexterity")) > 0 ) {
         ETO->remove_stat_bonuses();
         ETO->add_stat_bonus("dexterity",-dex_bonus);
      }
      if(ETO->query_stoneSkinned())
         ETO->set_stoneSkinned(0);
   }
}
