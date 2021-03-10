//talos_badge.c - Standard faith item for talos
#include <std.h>
inherit ARMOUR;

void create() {
  ::create();
  set_name("talos badge");                        
  set_id(({"badge","talos badge","tiger's-eye clasp","tiger's-eye brooch","clasp","brooch"}));
  set_short("A tiger's-eye brooch");   
  set_long("This perfectly spherical tiger's-eye has been highly "+
     "polished and seems to stare eerily.  The bright yellow edges "+
     "contrast strongly with the deep brown, almost black pupil-like "+
     "center.  A strange storm seems to rage within the gem, making it "+
     "feel as though it has an energy all its own.  The back of the brooch "+
     "has been planed smooth and fitted with a strong pin, or the gem may "+
     "be worn as a cloak clasp.");
  set_lore("This brooch is granted to followers of Talos who have "+
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
   if((string)ETO->query_diety() == "talos"){
      tell_object(ETO,"You feel the blessings of Talos as you wear the brooch.");
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
