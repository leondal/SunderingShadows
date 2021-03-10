//bane_badge.c - Standard faith item for bane
#include <std.h>
inherit ARMOUR;

void create() {
  ::create();
  set_name("bane badge");                        
  set_id(({"badge","bane badge","emerald clasp","emerald","clasp"}));
  set_short("An emerald clasp");   
  set_long("This fashionable clasp has been made of a "+
     "round-cut emerald fitted within prongs of nearly "+
     "black steel.  The prongs are rarely long, making "+
     "it seem as though the sparkling emerald is being "+
     "squeezed out of them.  The clasp has been affixed "+
     "to a sturdy pin that would pierce the strongest "+
     "materials, or it may be "+
     "worn as a cloak clasp.");
  set_lore("This clasp is granted to followers of Bane who have "+
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
   if((string)ETO->query_diety() == "bane"){
      tell_object(ETO,"You feel the blessings of Bane as you wear the clasp.");
      return 1;
   }
   else{
      tell_object(ETO,"The clasp stings your chest as you try to take what is not meant for you!");
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
   tell_object(ETO,"You feel a pang of regret as you remove the clasp.");
   return 1;
}
