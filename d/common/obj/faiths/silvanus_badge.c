//silvanus_badge.c - Standard faith item for silvanus
#include <std.h>
inherit ARMOUR;

void create() {
  ::create();
  set_name("silvanus badge");                        
  set_id(({"badge","silvanus badge","copper clasp","copper brooch","clasp","brooch"}));
  set_short("A copper brooch");   
  set_long("This green-tinged copper brooch is made in the form of a "+
     "small oak leaf.  The outter edges are a vibrant green that contrasts "+
     "pleasantly with the deep, woody brown shade of the stem in the middle.  "+
     "The brooch has been fitted with a strong pin that would pierce any fabric, "+
     "or it may be used as a cloak clasp.");
  set_lore("This brooch is granted to followers of Silvanus who have "+
     "proven their faith and dedication to their god.");
  set_property("lore difficulty",10);
  set_type("ring");
  set_ac(0);  
  set_weight(1);
  set_value(125);
  set_limbs(({"torso"}));
  set_property("enchantment",1);
  set_wear((:TO,"wearme":));      
  set_remove((:TO,"unwearme":));
}

int wearme(){
   if((string)ETO->query_diety() == "silvanus"){
      tell_object(ETO,"You feel the blessings of Silvanus as you wear the brooch.");
      return 1;
   }
   else{
      tell_object(ETO,"The brooch stings your chest as you try to take what is not meant for you!");
      set_property("magic",1);
      ETO->do_damage("torso",random(10)+10);
      ETO->add_attacker(TO);
      ETO->continue_attack();
      ETO->remove_attacker(TO);
      remove_property("magic");
      return 0;
   }
}

int unwearme(){
   tell_object(ETO,"You feel a pang of regret as you remove the brooch.");
   return 1;
}
