//water_weird.c - Guardian for nereid in the Riddle Quest.  Circe 12/11/03
#include <std.h>
inherit WEAPONLESS;

void create()
{
   ::create();
   set_name("water weird");
   set_short("A viscious water weird");
   set_id(({"elemental","monster","water weird","weird","water elemental"}));
   set_long(
      "The serpentine body of the water weird is difficult to spot, "+
      "even in the calm waters of a pool.  It has formed its "+
      "fluid mass into the shape of a large eel, with an eerie head "+
      "devoid of eyes.  Clearly, though, it can sense its pray, and "+
      "there is little doubt it could be quiet dangerous."
   );
   set_gender("neuter");
   set_race("elemental");
   set_body_type("snake");
   set_size(1);
   set_hd(20,6);
   set_level(20);
   set_class("fighter");
   set_mlevel("fighter",20);
   set_alignment(9);
   set_overall_ac(-10);
   set_hp(random(150)+75);
   set_damage(1,8);
   set_attacks_num(2);
   set_base_damage_type("bludgeoning");
   set_property("swarm",1);
   set("aggressive",25);
   set_exp(300);
   set_funcs(({"drown"}));
   set_func_chance(30);
}

void drown(object targ)
{
   if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) {
      tell_object(targ,"%^BOLD%^%^BLUE%^The water weird pulls you into the "+
         "water!");
      tell_room(ETO,"%^BOLD%^%^BLUE%^The water weird pulls "+targ->query_cap_name()+" "+
         "into the water!",targ);
      tell_object(targ,"%^BOLD%^%^CYAN%^The water weird wraps its body around you "+
         "and squeezes, drowning you!");
      targ->set_hp(-1);
      return;
   }
   tell_object(targ,"%^BLUE%^The water weird tries to pull you into the pool, but "+
      "you stand your ground!");
   tell_room(ETO,"%^BLUE%^"+targ->query_cap_name()+" struggles with the water weird, "+
      "but keeps "+targ->query_possessive()+" footing!",targ);
   return;
}
