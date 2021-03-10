//mask_badge.c - Standard faith item for mask
#include <std.h>
inherit ARMOUR;

void create() {
  ::create();
  set_name("mask badge");                        
  set_id(({"badge","mask badge","smokey quartz clasp","smokey quartz brooch","clasp","brooch"}));
  set_short("A smokey quartz brooch");   
  set_long("This multi-faceted brooch is made of deep, smokey gray quartz "+
     "that flickers in the light.  Shadows are hidden deep within, making it "+
     "impossible for any light to penetrate through to the other side.  The "+
     "quartz is set within a simple platinum setting.  The simplicity of the design "+
     "seems at odds with the high quality of the stone and metal.  The "+
     "brooch has a long pin attached to the back that would pierce the thickets "+
     "fabrics, or the gem may be used to fasten a cloak.");
  set_lore("This brooch is granted to followers of Mask who have "+
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
   if((string)ETO->query_diety() == "mask"){
      tell_object(ETO,"You feel the blessings of Mask as you wear the brooch.");
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
