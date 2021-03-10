
#include <std.h>
inherit WEAPONLESS;

create (){
::create ();
set_name("marmaset");
set_id( ({"marmaset"}) );
set("short", "A marmaset");
set("long", "This is a Canuck 6 legged Marmaset, one of the smallest,
fiercest carnivores to ever walk the realms!
Known for it's super speed and a large mouth with razor sharp teeth.
A Marmaset has been known to try to swallow creatures 2 times it's size.");
set_gender("male");
set("race", "marmaset");
set_body_type("bear");
set_hd(12,2);
set_overall_ac(5);
set_size(1);
set_stats("strength", 15);
set_stats("intelligence", 1);
set_stats("dexterity", 18);
set_stats("charisma", 1);
set_stats("wisdom", 1);
set_class("fighter");
set("aggressive", 5);
set_base_damage_type("slash");
set_damage(1,8);
set_attack_limbs(({"right claw","left claw","mouth","right middle
claw","left middle claw"}));
set_attacks_num(3);
add_limb("left middle claw","left middle leg",0,0,0);
add_limb("right middle claw","right middle leg",0,0,0);
add_limb("left middle leg","torso",0,0,0);
add_limb("right middle leg","torso",0,0,0);
add_limb("tail","torso",0,0,0);
set_max_hp(85);
set_hp(85);
set_exp(1400);
set_alignment(5);
set_emotes(20,({"The Marmaset bites you and attempts to swallow your leg!",
"The Marmaset snarls and foams at the mouth!"}),1);
  set_funcs( ({"bite"}) );
  set_func_chance(50);
}


void bite(object targ)
{
  if(!targ) return 0;
  tell_room(environment(targ), "%^RED%^The Marmaset tears into "+targ->query_cap_name()+" biting and gnawing like mad at his neck!",targ);
  tell_object(targ, "%^RED%^The Marmaset tears into you biting and gnawing like mad at your neck!");
      targ->do_damage(targ->return_target_limb(), random(8)+5);
  return 1;
}

