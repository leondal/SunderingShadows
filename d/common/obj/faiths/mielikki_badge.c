//mielikki_badge.c - Standard faith item for mielikki
#include <std.h>
inherit ARMOUR;

void create() {
  ::create();
  set_name("mielikki badge");                        
  set_id(({"badge","mielikki badge","emerald clasp","emerald brooch","clasp","brooch"}));
  set_short("An emerald brooch");   
  set_long("A large, clear emerald the size of a grown human's thumb has been "+
     "formed into a smooth oval and set within a frame of burnished gold.  Not a "+
     "single impurity mars the gem's radiance, but as you look closer, you can see "+
     "that a simple image has been somehow placed inside.  It seems almost carved, "+
     "although not so much as a scratch can be found on the outside.  The image is that "+
     "of a graceful unicorn's head, steadfast and strong.");
  set_lore("This brooch is granted to followers of Mielikki who have "+
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
   if((string)ETO->query_diety() == "mielikki"){
      tell_object(ETO,"You feel the blessings of Mielikki as you wear the brooch.");
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
