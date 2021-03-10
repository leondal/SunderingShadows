//eldath_badge.c - Standard faith item for eldath
#include <std.h>
inherit ARMOUR;

void create() {
  ::create();
  set_name("eldath badge");                        
  set_id(({"badge","eldath badge","crystal badge","sphere badge","crystal sphere badge"}));
  set_short("A crystal sphere badge");   
  set_long(
@CIRCE
Crafted from clear crystal, a small sphere filled with water is supported by silk ribbons in a calm blue shade.  Floating in the water, inside the sphere, is a small fern leaf.
CIRCE
  );
  set_lore("This badge is granted to followers of Eldath who have "+
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
   if((string)ETO->query_diety() == "eldath"){
      tell_object(ETO,"You feel the blessings of Eldath as you wear the badge.");
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
