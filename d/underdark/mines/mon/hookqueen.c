//Octothorpe (8/24/08)
//Underdark Mining Caverns, Hook Horror Queen

#include <std.h>
#include "../defs.h"
inherit WEAPONLESS;

void create(){
   ::create();
   set_name("hook horror queen");
   set_id(({"hook horror","hook","horror","queen","hook horror queen"}));
   set_short("%^BOLD%^%^BLACK%^m%^RESET%^o%^BOLD%^%^BLACK%^ttled "+
      "h%^RESET%^oo%^BOLD%^%^BLACK%^k h%^RESET%^o%^BOLD%^%^BLACK%^rr"+
      "%^RESET%^o%^BOLD%^%^BLACK%^r queen%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This creature is aptly named due to the "+
      "h%^RESET%^oo%^BOLD%^%^BLACK%^k found on each arm in lieu of "+
      "hands. It reaches to a height nearly twice that of an average "+
      "humanoid. The head is similar in appearance to the vulture that "+
      "is found on the surface, complete with a large beak that is "+
      "probably capable of rending through metal. It is protected by a "+
      "m%^RESET%^o%^BOLD%^%^BLACK%^ttled, %^RESET%^grey %^BOLD%^"+
      "%^BLACK%^cockroach-like exoskeleton that appears to more than "+
      "adequately protect the h%^RESET%^oo%^BOLD%^%^BLACK%^k h%^RESET%^o"+
      "%^BOLD%^%^BLACK%^rr%^RESET%^o%^BOLD%^%^BLACK%^r from attack. "+
	  "The exoskeleton is covered in a multitude of %^GREEN%^gr%^RESET%^"+
	  "%^GREEN%^ee%^BOLD%^n %^BOLD%^%^BLACK%^and %^MAGENTA%^p%^RESET%^"+
	  "%^MAGENTA%^u%^BOLD%^rpl%^RESET%^%^MAGENTA%^e %^BOLD%^"+
	  "%^BLACK%^crystals that pulse with energy. Its legs, just like "+
	  "its arms, end in a trio of smaller razor-sharp hooks resembling "+
	  "toes. This h%^RESET%^oo%^BOLD%^%^BLACK%^k h%^RESET%^o%^BOLD%^"+
	  "%^BLACK%^rr%^RESET%^o%^BOLD%^%^BLACK%^r is of a smaller stature "+
	  "than the other ones in the area, perhaps this is the queen of "+
	  "this warren.");
   set_race("hook horror");
   set_alignment(5);
   set_gender("female");
   set_body_type("human");
   remove_limb("left hand");
   remove_limb("right hand");
   add_limb("right hook","right arm", 0, 0, 0);
   add_limb("left hook","left arm", 0, 0, 0);
   add_limb("beak","head", 0, 0, 0);
   set_hd(30,2);
   set_class("psion");
   set_guild_level("psion",30);
   set_mlevel("psion",30);
   set_max_level(20);
   set_overall_ac(-12);
   set_size(3);
   set_max_hp(400);
   set_hp(query_max_hp());
   set_property("swarm",1);
   set("aggressive",25);
   set_attack_limbs(({"right hook","left hook","beak"}));
   set_attacks_num(3);
   set_base_damage_type("slashing");
   set_damage(2,20);
   set_stats("strength",25);
   set_stats("intelligence",19);
   set_stats("dexterity",13);
   set_stats("constitution",16);
   set_stats("wisdom",11);
   set_stats("charisma",6);
   set_new_exp(17,"boss");
   set_spells(({
      "swarm of crystals",
	  "catapsi",
	  "ultrablast"
   }));
   set_spell_chance(80);
   set_func_chance(80);
   set_funcs(({"bite","bite","bite","trip","heal","heal"}));
   set_achats(20,({"The %^BOLD%^%^BLACK%^h%^RESET%^oo%^BOLD%^%^BLACK%^k "+
   "h%^RESET%^o%^BOLD%^%^BLACK%^rr%^RESET%^o%^BOLD%^%^BLACK%^r%^RESET%^ "+
   "snaps her beak meancingly."}));
   set_monster_feats(({
      "toughness",
	  "improved toughness",
	  "damage resistance",
	  "improved damage resistance"
   }));
}

void heal(object ob){
   if(TO->query_hp() < query_max_hp()){
      tell_room(ETO,"%^BOLD%^%^WHITE%^The crystals embedded into the "+
         "%^BOLD%^%^BLACK%^H%^RESET%^oo%^BOLD%^%^BLACK%^k H%^RESET%^o"+
         "%^BOLD%^%^BLACK%^rr%^RESET%^o%^BOLD%^%^BLACK%^r queen's "+
         "%^BOLD%^%^WHITE%^exoskeleton begin to %^GREEN%^g%^RESET%^"+
         "%^MAGENTA%^l%^BOLD%^o%^RESET%^%^GREEN%^w%^BOLD%^%^WHITE%^, "+
         "causing her wounds to heal.");
      TO->add_hp(random(100));
      return;
   }
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
