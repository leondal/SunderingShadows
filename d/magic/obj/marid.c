//marid.c

#include <std.h>
inherit WEAPONLESS;

void create(){
   ::create();
   set_name("marid");
   set_id(({"marid","Marid","genie"}));
   set_short("Marid");
   set_long(
@DESC
The marid is a creature of the elemental plane of water.
Born of the ocean, the marid has its power.
DESC
   );
   set_race("genie");
   set_body_type("humanoid");
   set_gender("male");
   set_class("fighter");
   set_mlevel("fighter",15);
   set_hd(15,1);
   set_hp(150);
   set_exp(1);
   set_overall_ac(-1);
   set_alignment(8);
   set_base_damage_type("bludgeoning");
   set_attack_limbs(({"right hand","left hand"}));
   set_damage(4,8);
   set_attacks_num(1);
   set_funcs(({"shoot_water"}));
   set_func_chance(15);
}

void shoot_water(){
   int i;
   object who, *attackers;

   attackers = query_attackers();
   i=random(sizeof(attackers));
   who = attackers[i];
   if(!objectp(who)) return;
   tell_object(who,"%^CYAN%^%^BOLD%^The marid shoots a stream of water directly toward you.");
   tell_room(ETO,"%^BOLD%^%^CYAN%^The marid shoots a stream of water toward "+who->query_cap_name()+".",who);
   who->do_damage("torso",roll_dice(1,6));
   if (!("daemon/saving_d"->saving_throw(who,"breath_weapon",0))) {
      tell_room(ETO,"%^BLUE%^"+who->query_cap_name()+" is knocked to the ground by the force of the water!",who);
      tell_object(who,"%^BLUE%^You are knocked to the ground by the water sprayed into your eyes!");
      who->set_paralyzed(8*(1+random(6)),"Your eyes are still stinging from the blast of water.");
   }
   return;
}

