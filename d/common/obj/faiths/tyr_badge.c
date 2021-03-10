//tyr_badge.c - Standard faith item for tyr
#include <std.h>
inherit ARMOUR;

void create() {
  ::create();
  set_name("tyr badge");                        
  set_id(({"badge","tyr badge","steel clasp","steel brooch","clasp","brooch"}));
  set_short("A steel brooch");   
  set_long("This flattened brooch is made of burnished steel "+
     "in the shape of a simple oval.  The oval has a slight curve "+
     "to it, but it is otherwise strangely unadorned.  A simple "+
     "power radiates from the brooch, making it feel heavier than "+
     "it actually is.  A sturdy metal pin is attached to the back, "+
     "or it may be worn as a cloak clasp.");
  set_lore("This brooch is granted to followers of Tyr who have "+
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
   if((string)ETO->query_diety() == "tyr"){
      tell_object(ETO,"You feel the blessings of Tyr as you wear the brooch.");
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
