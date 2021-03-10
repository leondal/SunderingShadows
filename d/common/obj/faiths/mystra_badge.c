//mystra_badge.c - Standard faith item for mystra
#include <std.h>
inherit ARMOUR;

void create() {
  ::create();
  set_name("mystra badge");                        
  set_id(({"badge","mystra badge","platinum clasp","platinum brooch","clasp","brooch"}));
  set_short("A platinum brooch");   
  set_long("This intricately-formed brooch is made of pure platinum "+
     "that is rather heavy.  The platinum strands have been woven into "+
     "an ever-twisting web that has a silvery-blue hue.  The web looks "+
     "to be a many-layered spider's web that is topped with a circle of "+
     "stars.  The brooch has been fitted with a pin to pierce the strongest "+
     "fabrics, or it may be used to fasten a cloak.");
  set_lore("This brooch is granted to followers of Mystra who have "+
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
   if((string)ETO->query_diety() == "mystra"){
      tell_object(ETO,"You feel the blessings of Mystra as you wear the brooch.");
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
