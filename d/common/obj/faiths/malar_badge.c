//malar_badge.c - Standard faith item for Malar
#include <std.h>
inherit ARMOUR;

void create() {
  ::create();
  set_name("malar badge");                        
  set_id(({"badge","malar badge","horn clasp","horn brooch","clasp","brooch"}));
  set_short("A horn brooch");   
  set_long("This small brooch has been carved from pure horn and "+
     "stained a light shade of tan.  The brooch is circular and depicts "+
     "a detailed hunting scene despite its small size.  A strange clawed "+
     "beast much like a jaguar chases down a hind who is fleeing in terror.  "+
     "The brooch has been made so that it may be used as a cloak clasp or "+
     "attached to a shirt using the long pin across its back.");
  set_lore("This brooch is granted to followers of Malar who have "+
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
   if((string)ETO->query_diety() == "malar"){
      tell_object(ETO,"You feel the blessings of Malar as you wear the brooch.");
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
