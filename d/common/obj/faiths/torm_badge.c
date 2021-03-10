//torm_badge.c - Standard faith item for torm
#include <std.h>
inherit ARMOUR;

void create() {
  ::create();
  set_name("torm badge");                        
  set_id(({"badge","torm badge","diamond clasp","diamond brooch","clasp","brooch"}));
  set_short("A diamond brooch");   
  set_long("A large diamond has been hewn into a smooth triangle that "+
     "sparkles mutli-colored in the light.  The gem is strangely flat "+
     "and magically carved with an image inside.  No scratch mars the surface, "+
     "but deep within is the image of a gauntleted hand, palm forward.  The "+
     "elegant piece of jewelry is affixed to a sturdy pin cleverly hidden, "+
     "or it may be used to fasten a cloak.");
  set_lore("This brooch is granted to followers of Torm who have "+
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
   if((string)ETO->query_diety() == "torm"){
      tell_object(ETO,"You feel the blessings of Torm as you wear the brooch.");
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
