#include <std.h>
inherit WEAPONLESS;

void create() {
   ::create();
   set_name("steam mephit");
   set_id(({"mephit","imp","steam mephit"}));
   set_short("%^RESET%^%^RED%^a steam mephit%^RESET%^");
   set_long("%^RED%^This imp is small and cruel looking, and has "
"%^WHITE%^scalding steam %^RED%^rising from its translucent skin. "
"%^BOLD%^%^BLACK%^Hardened black claws %^RESET%^%^RED%^can be found on each "
"of its long fingers. It has a long, hooked nose and pointed ears, with a "
"large chin. Its wide face grins in a horrible %^CYAN%^parody %^RED%^of "
"amusement.%^RESET%^");
   set_gender("neuter");
   set_race("imp");
   set_body_type("humanoid");
   set_size(1);
   set_hd(8,4);
   set_level(4);
   set_class("thief");
   set_mlevel("thief",6);
   set_alignment(3);
   set_overall_ac(6);
   set_max_hp(random(15)+40);
   set_hp(query_max_hp());
   add_limb("right claw","right hand",0,0,0);
   add_limb("left claw","left hand",0,0,0);
   set_damage(1,4);
   set_attacks_num(2);
   set_base_damage_type("slashing");
   set_attack_limbs(({"mouth","left claw","right claw"}));
   set_hit_funcs((["mouth" : (:TO,"breath":) ]));
   set_property("swarm",1);
   set("aggressive",25);
   set_exp(400);
   set_funcs(({"cloud"}));
   set_func_chance(10);
}

void init() {
   ::init();
   if(avatarp(TP) && TP->query_invis()) return;
   if((string)TP->query_name() == "steam mephit") return;
   force_me("kill "+TPQCN+"");
}

int breath(object targ) {
   tell_object(targ,"%^BOLD%^%^WHITE%^The mephit breathes a cloud of scalding "
"steam at you!%^RESET%^");
   tell_room(ETO,"%^BOLD%^%^WHITE%^The mephit breathes a cloud of scalding "
"steam at "+targ->QCN+"!%^RESET%^",targ);
   if(!random(2)) {
     targ->set_paralyzed(4,"You're recovering from the steam!");
   }
   return 1;
}

void cloud(object targ) {
   int i, j;
   object *inven;

   inven = all_living(ETO);
   j = sizeof(inven);

   tell_room(ETO,"%^YELLOW%^The mephit creates a storm of boiling "
"steam!%^RESET%^");
   for(i=0;i<j;i++) {
      if(!objectp(inven[i])) continue;
      if(inven[i] == TO) continue;
      if(inven[i]->query_true_invis()) continue;
      if((string)inven[i]->query_name() == "steam mephit") continue;
      tell_object(inven[i],"%^YELLOW%^The steam scalds your flesh!%^RESET%^");
      inven[i]->do_damage("torso",random(3)+3);
      return;
   }
   return;
}
