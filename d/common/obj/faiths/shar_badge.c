//shar_badge.c - Standard faith item for shar
#include <std.h>
inherit ARMOUR;

void create() {
  ::create();
  set_name("shar badge");                        
  set_id(({"badge","shar badge","darksteel clasp","darksteel brooch","clasp","brooch"}));
  set_short("A darksteel brooch");   
  set_long("This lozenge-shaped brooch is made of nearly-black darksteel "+
     "that reflects no light whatsoever.  The flat brooch is simple, yet "+
     "elegant, but devoid of any decoration whatsoever.  Darkness itself "+
     "gathers around the brooch, which is fastened to a strong pin that "+
     "can be attached to any fabric, or it may be used as a cloak clasp.");
  set_lore("This brooch is granted to followers of Shar who have "+
     "proven their faith and dedication to their goddess.");
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
   if((string)ETO->query_diety() == "shar"){
      tell_object(ETO,"You feel the blessings of Shar as you wear the brooch.");
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
