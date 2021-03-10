//kossuth_badge.c - Standard faith item for kossuth
#include <std.h>
inherit ARMOUR;

void create() {
  ::create();
  set_name("kossuth badge");                        
  set_id(({"badge","kossuth badge","copper badge","twisted copper badge","twisted badge"}));
  set_short("A twisted copper badge");   
  set_long(
@CIRCE
Crafted from copper, this badge was shaped to look like a burning flame.  The bottom of the flame though looks to have been melted, giving the flame a twisted, distorted image.
CIRCE
  );
  set_lore("This badge is granted to followers of Kossuth who have "+
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
   if((string)ETO->query_diety() == "kossuth"){
      tell_object(ETO,"You feel the blessings of Kossuth as you wear the badge.");
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
