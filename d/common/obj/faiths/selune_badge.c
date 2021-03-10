//selune_badge.c - Standard faith item for selune
#include <std.h>
inherit ARMOUR;

void create() {
  ::create();
  set_name("selune badge");                        
  set_id(({"badge","selune badge","white gold clasp","white gold brooch","clasp","brooch"}));
  set_short("A white gold brooch");   
  set_long("This square brooch is made of polished white gold and set with "+
     "a large emerald-cut quartz.  The white quartz has a light blue hue "+
     "that sparkles in the light, and the outter setting of white gold has "+
     "been studded with tiny moonstone fragments.  The brooch has been affixed "+
     "to a sturdy pin that would pierce the strongest materials, or it may be "+
     "worn as a cloak clasp.");
  set_lore("This brooch is granted to followers of Selune who have "+
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
   if((string)ETO->query_diety() == "selune"){
      tell_object(ETO,"You feel the blessings of Selune as you wear the brooch.");
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
