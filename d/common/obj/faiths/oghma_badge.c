//oghma_badge.c - Standard faith item for oghma
#include <std.h>
inherit ARMOUR;

void create() {
  ::create();
  set_name("oghma badge");                        
  set_id(({"badge","oghma badge","sapphire brooch","blue-green sapphire brooch","brooch"}));
  set_short("A blue-green sapphire brooch");   
  set_long("This sparkling brooch is made of an unusual "+
     "sapphire that seems to sparkle with a blue-green "+
     "fire.  The gem has been cut in a multi-faceted "+
     "design that reflects light in beautiful prisms.  "+
     "The brooch has been affixed to a sturdy pin that "+
     "would pierce the strongest materials, or it may be "+
     "worn as a cloak clasp.");
  set_lore("This brooch is granted to followers of Oghma who have "+
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
   if((string)ETO->query_diety() == "oghma"){
      tell_object(ETO,"You feel the blessings of Oghma as you wear the brooch.");
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
