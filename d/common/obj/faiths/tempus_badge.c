//tempus_badge.c - Standard faith item for tempus
#include <std.h>
inherit ARMOUR;

void create() {
  ::create();
  set_name("tempus badge");                        
  set_id(({"badge","tempus badge","ruby clasp","ruby brooch","clasp","brooch"}));
  set_short("A ruby brooch");   
  set_long("This deep scarlet ruby is multi-faceted and set within a "+
     "braided frame of gold.  The ruby sparkles brightly in the light, "+
     "in places the color of fresh blood.  The thick frame has been "+
     "attached to a pin that would pierce any fabric, or the gem may "+
     "be worn as a cloak clasp.");
  set_lore("This brooch is granted to followers of Tempus who have "+
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
   if((string)ETO->query_diety() == "tempus"){
      tell_object(ETO,"You feel the blessings of Tempus as you wear the brooch.");
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
