//kelemvor_badge.c - Standard faith item for kelemvor
#include <std.h>
inherit ARMOUR;

void create() {
  ::create();
  set_name("kelemvor badge");                        
  set_id(({"badge","kelemvor badge","linen badge","gray badge","gray linen badge"}));
  set_short("A gray linen badge");   
  set_long(
@CIRCE
Crafted from linen, often used as funeral shrouds, this simple gray badge lacks any adornment.  On a closer inspection one can find the faded image of The Lord of the Dead's symbol woven into the linen.
CIRCE
  );
  set_lore("This badge is granted to followers of Kelemvor who have "+
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
   if((string)ETO->query_diety() == "kelemvor"){
      tell_object(ETO,"You feel the blessings of Kelemvor as you wear the badge.");
      return 1;
   }
   else{
      tell_object(ETO,"The badge stings your chest as you try to take what is not meant for you!");
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
   tell_object(ETO,"You feel a pang of regret as you remove the badge.");
   return 1;
}
