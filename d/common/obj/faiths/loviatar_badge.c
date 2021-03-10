//loviatar_badge.c - Standard faith item for loviatar
#include <std.h>
inherit ARMOUR;

void create() {
  ::create();
  set_name("loviatar badge");                        
  set_id(({"badge","loviatar badge","leather badge","black badge","black leather badge"}));
  set_short("A black leather badge");   
  set_long(
@CIRCE
Crafted from braided black leather into a thick line, this badge looks rather plain and nondescript.  The badge seems to attach by the way of mithril barbs that adorn each of the nine strands that trail off the main part of the badge.
CIRCE
  );
  set_lore("This badge is granted to followers of Loviatar who have "+
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
   if((string)ETO->query_diety() == "loviatar"){
      tell_object(ETO,"You feel the blessings of Loviatar as you wear the badge.");
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
