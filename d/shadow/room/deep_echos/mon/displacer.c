//displacer beast

#include <std.h>
inherit WEAPONLESS;

void create()
{
   ::create();
   set_name("displacer beast");
   set_short("A tentacled dark Leopard");
   set_id(({"beast","displacer beast","monster","leopard","displacer"}));
   set_long(
   "This dark cat resembles a puma.  It has two powerful "+
   "black tentacles growing from its shoulders.  "+
   "These tentacles are tipped with rough horny edges.  "+
   "Unlike a natural cat, this creature has six legs.  "+
   "It's eyes glow bright green." 
   );
   set_hd(12,5);
   set_race("displacer beast");
   set_gender("female");
   set_body_type("quadruped");
   set_overall_ac(2);
   set("aggressive",15);
  set_property("swarm",1);
  set_level(15);
  set_class("fighter");
  set_mlevel("fighter",15);
  set_hp(random(300)+80);
  //set_exp(9000);
  set_new_exp(15,"normal");
  set_damage(2,8);
  set_stats("strength",20);
  set_stats("intelligence",6);
  set_stats("dexterity",22);
  set_stats("constitution",16);
  set_stats("wisdom",3);
  set_stats("charisma",10);
  set_base_damage_type("slashing");
  set_attacks_num(5);
  set_base_damage_type("slashing");
  add_limb("left paw","left hand",0,0,0);
  add_limb("right paw","right hand",0,0,0);
  add_limb("mouth","head",0,0,0);
  add_limb("left tentacle","left tentacle",0,0,0);
  add_limb("right tentacle","right tentacle",0,0,0);
  set_attack_limbs(({"left paw","right paw","mouth","left tentacle","right tentacle"}));
  set_hit_funcs((["mouth" : (:TO,"bite":) ]));
  set_overall_ac(4);
  set_alignment(5);
  set_emotes(4,({
  "The beast crouches low to the ground, ready to pounce.",
  "The beast shimmers and reappears in another location.",
  "The beast whips it tentacles around.",
  "The beast licks its whiskers.",
  }),0);
  set_emotes(1,({
  "The beast's eyes glow green focused on you.",
  "The beast's tentacles lash out for you!",
  "The beast shimmers out of existence only to reapear elseware."
  }),1);
  set_funcs(({"dash"}));
  set_func_chance(5);
  set_max_level(15);
  set_missChance(75);
  set_base_damage_type("slashing");
}



void dash(object targ)
{
   tell_object(targ,"A tentacle pulls at your foot, from out of nowhere,"+
   " knocking you over!");
   tell_room(ETO,"The displacer beast wraps a tentacle around"+
   " "+targ->query_cap_name()+"knocking them over!",targ);
   targ->do_damage(targ->return_target_limb(),random(10)+1);
   targ->cause_typed_damage(targ,0,roll_dice(1,10),"slashing");

   targ->set_tripped(2,"You're still recovering from being knocked down.");
   return 1;
}
