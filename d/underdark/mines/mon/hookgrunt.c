//Octothorpe (8/24/08)
//Underdark Mining Caverns, Hook Horror

#include <std.h>
#include "../defs.h"
inherit WEAPONLESS;

void create(){
   ::create();
   set_name("hook horror");
   set_id(({"hook horror","hook","horror","aberration"}));
   set_short("%^BOLD%^%^BLACK%^m%^RESET%^o%^BOLD%^%^BLACK%^ttled "+
   "h%^RESET%^oo%^BOLD%^%^BLACK%^k h%^RESET%^o%^BOLD%^%^BLACK%^rr"+
      "%^RESET%^o%^BOLD%^%^BLACK%^r%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This creature is aptly named due to the "+
      "h%^RESET%^oo%^BOLD%^%^BLACK%^k found on each arm in lieu of "+
      "hands. It reaches to a height nearly twice that of an average "+
      "humanoid. The head is similar in appearance to the vulture that "+
      "is found on the surface, complete with a large beak that is "+
      "probably capable of rending through metal. It is protected by a "+
      "m%^RESET%^o%^BOLD%^%^BLACK%^ttled, %^RESET%^grey %^BOLD%^"+
      "%^BLACK%^cockroach-like exoskeleton that appears to more than "+
      "adequately protect the h%^RESET%^oo%^BOLD%^%^BLACK%^k h%^RESET%^"+
      "o%^BOLD%^%^BLACK%^rr%^RESET%^o%^BOLD%^%^BLACK%^r from attack. "+
      "Its legs, just like its arms, end in a trio of smaller razor-"+
      "sharp hooks resembling toes.");
   set_race("hook horror");
   set_alignment(5);
   set_gender("male");
   set_body_type("human");
   remove_limb("left hand");
   remove_limb("right hand");
   add_limb("right hook","right arm", 0, 0, 0);
   add_limb("left hook","left arm", 0, 0, 0);
   add_limb("beak","head", 0, 0, 0);
   set_hd(21,2);
   set_overall_ac(-12);
   set_size(3);
   set_moving(1);
   set_speed(70);
   set_max_level(20);
   set_max_hp(350);
   set_hp(query_max_hp());
   set_property("swarm",1);
   set("aggressive",25);
   set_attack_limbs(({"right hook","left hook","beak"}));
   set_attacks_num(3);
   set_base_damage_type("slashing");
   set_damage(2,8);
   set_stats("strength",17);
   set_stats("intelligence",6);
   set_stats("dexterity",13);
   set_stats("constitution",16);
   set_stats("wisdom",11);
   set_stats("charisma",6);
   set_new_exp(17,"normal");
   set_func_chance(60);
   set_funcs(({"bite","bite","bite","trip"}));
   set_achats(20,({"The %^BOLD%^%^BLACK%^h%^RESET%^oo%^BOLD%^%^BLACK%^k "+
      "h%^RESET%^o%^BOLD%^%^BLACK%^rr%^RESET%^o%^BOLD%^%^BLACK%^r "+
      "%^RESET%^snaps his beak meancingly."}));
}

void bite(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   tell_object(targ,"%^BOLD%^%^WHITE%^The snapping beak of the %^BOLD%^"+
      "%^BLACK%^h%^RESET%^oo%^BOLD%^%^BLACK%^k h%^RESET%^o%^BOLD%^"+
      "%^BLACK%^rr%^RESET%^o%^BOLD%^%^BLACK%^r %^BOLD%^%^WHITE%^finds "+
      "its target!");
   tell_room(ETO,"%^BOLD%^%^WHITE%^"+targ->QCN+" is bitten by the "+
      "snapping beak of the %^BOLD%^%^BLACK%^h%^RESET%^oo%^BOLD%^"+
      "%^BLACK%^k h%^RESET%^o%^BOLD%^%^BLACK%^rr%^RESET%^o%^BOLD%^"+
      "%^BLACK%^r%^BOLD%^%^WHITE%^!",targ);
   targ->do_damage(targ->return_target_limb(),random(20)+4);
   return;
}

void trip(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   tell_object(targ,"%^BOLD%^%^WHITE%^The %^BOLD%^%^BLACK%^h%^RESET%^"+
      "oo%^BOLD%^%^BLACK%^k h%^RESET%^o%^BOLD%^%^BLACK%^rr%^RESET%^o"+
      "%^BOLD%^%^BLACK%^r%^BOLD%^%^WHITE%^ reaches out with one of "+
      "its hooks and knocks you down!");
   tell_room(ETO,"%^BOLD%^%^WHITE%^"+targ->QCN+" is knocked down onto "+
      "the ground by one of the %^BOLD%^%^BLACK%^h%^RESET%^oo%^BOLD%^"+
      "%^BLACK%^k h%^RESET%^o%^BOLD%^%^BLACK%^rr%^RESET%^o%^BOLD%^"+
      "%^BLACK%^r's %^BOLD%^%^WHITE%^hooked appendages!",targ);
   targ->set_tripped(1,"%^YELLOW%^You are trying to scramble back to "+
      "your feet!");
   return(random(3)+1);
}

void init(){
   string mrace=TP->query_race();
   ::init();
   if(TP->query_invis() || mrace == "hook horror") return;
   command ("kill "+TPQN);
}
