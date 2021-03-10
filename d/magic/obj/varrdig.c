//eelemental.c

#include <std.h>

inherit WEAPONLESS;

void create(){
   ::create();
   set_name("varrdig");
   set_id(({"varrdig","Varrdig","elemental"}));
   set_short("Varrdig");
   set_long(
@DESC
The varrdig is basically a globular, jelly-like blob. It
is a type of elemental, from the Elemental Plane of Water.
It has two small hoses at its middle which are dripping
small amounts of water.
DESC
   );
   set_hd(12,1);
   set_hp(200);
   set_exp(1);
   set_stats("strength",18);
   set_stats("intelligence",7);
   set_stats("dexterity",4);
   set_race("elemental");
   add_limb("torso","torso",50,0,2);
   add_limb("right water tube","torso",50,0,2);
   add_limb("left water tube","torso",50,0,2);
   add_limb("base","torso",50,0,2);
   set_attack_limbs(({"left water tube", "right water tube"}));
   set_damage(1,4);
   set_attacks_num(2);
   set_base_damage_type("bludgeoning");
   set_funcs(({"shoot_water"}));
   set_func_chance(25);
   set_overall_ac(-3);
}

void shoot_water(){
   int i;
   object who, *attackers;

   attackers = query_attackers();
   i=random(sizeof(attackers));
   who = attackers[i];
   if(!objectp(who)) return;
   tell_object(who,"%^BLUE%^%^BOLD%^The varrdig points a water tube directly toward you.");
   tell_room(ETO,"%^BOLD%^%^BLUE%^The varrdig points a water tube toward "+who->query_cap_name()+".",who);
   tell_room(ETO,"%^BOLD%^A strong blast of water shoots out of the tube!");
   who->do_damage("torso",roll_dice(4,4));
   if (!random(6)) {
      tell_room(ETO,"%^BLUE%^"+who->query_cap_name()+" is knocked to the ground by the force of the water!",who);
      tell_object(who,"%^BLUE%^You are knocked to the ground by the water sprayed into your eyes!");
      who->set_paralyzed(8*(1+random(4)),"Your eyes are still stinging from the blast of water.");
   }
   return;
}
