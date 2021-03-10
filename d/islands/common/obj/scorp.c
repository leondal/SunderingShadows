#include <std.h>
inherit WEAPONLESS;
void create(){
  ::create();
   set_name("%^BOLD%^%^BLACK%^A shiny black scorpion%^RESET%^");
  setenv("MIN", "$N creeps in.");
  setenv("MOUT", "$N creeps $D.");
   set_id(({"scorpion","black scorpion","prscorpion"}));
   set_short("%^BOLD%^%^BLACK%^A shiny black scorpion%^RESET%^");;
   set_long("%^BOLD%^%^BLACK%^This is a shiny black scorpion.  It's body is flat and elongated, slightly rounded"
" in the middle.  A small, barely perceptible head sits at the front of it, with large, claw-like pincers"
" held on either side.  At the rear of the scorpion, a shiny black tail curves over its body, with a"
" large, bulbous stinger held at the end.");
  set_hd(20,2);
  set_max_hp(50);
  set_hp(50);
  set_race("spider");
  set_gender("male");
  set_body_type("arachnid");
  set_ac(0);
  set_exp(1);
  set_property("magic",1);
  set_attacks_num(1);
  set_damage(1,3);
  set_attack_limbs(({"right pincer","left pincer","mouth"}));
  set_base_damage_type("slashing");
  set_property("knock unconscious",1);
  set_func_chance(5);
  set_funcs(({"bite"}));
}
void bite(object target){
   if(!"daemon/saving_d"->saving_throw(target,"paralyzation_poison_death")) {
      tell_room(ETO,"%^BOLD%^%^BLACK%^The scorpion lunges forward and sinks its stinger deep into "+target->query_cap_name()+"'s flesh.",target);
      tell_object(target, "%^BOLD%^%^BLACK%^The scorpion lunges forward and sinks its stinger deep into your flesh!");
      target->do_damage("torso",roll_dice(1,6));
      target->add_poisoning(15);
   }
   tell_room(ETO,"%^BOLD%^%^BLACK%^The scorpion lunges forward with its stinger but misses "+target->query_cap_name()+"!",target);
   tell_object(target, "%^BOLD%^%^BLACK%^The scorpion lunges forward with its stinger but misses you!");
}
