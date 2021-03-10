//grumbar_badge.c - Standard faith item for grumbar
#include <std.h>
inherit ARMOUR;

void create() {
  ::create();
  set_name("grumbar badge");                        
  set_id(({"badge","grumbar badge","triangle badge","inverted triangle badge","steel badge"}));
  set_short("An inverted triangle steel badge");   
  set_long(
@CIRCE
Crafted from hammered steel, this badge is fashioned into an inverted triangle, looking like a mountain of sorts.  Imbedded into the steel are chips from every kind of gem imaginable. 
CIRCE
  );
  set_lore("This badge is granted to followers of Grumbar who have "+
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
   if((string)ETO->query_diety() == "grumbar"){
      tell_object(ETO,"You feel the blessings of Grumbar as you wear the badge.");
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
