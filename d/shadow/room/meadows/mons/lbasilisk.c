#include <std.h>
inherit WEAPONLESS;

void create()
{
   ::create();
   set_name("lesser basilisk");
   set_short("A scaly brown lizard");
   set_id(({"lizard","basilisk","monster","lesser basilisk","brown lizard","scaly brown lizard","scaly lizard"}));
   set_long(
   "As you gaze upon the scaly creature you realize that this is no ordinary"+
   " lizard, but a lesser basilisk! Its scales are are a dull brown color"+
   " and the underbelly is %^YELLOW%^yellow%^RESET%^%^CYAN%^. It is rather"+
   " large for a lizard, but still slow. It doesn't really matter how fast"+
   " the creature is, however, for it can merely look at someone with its"+
   " %^BOLD%^%^GREEN%^glowing green%^RESET%^%^CYAN%^ eyes and turn them to"+
   " stone."
   );
   set_gender("neuter");
   set_race("lizard");
   set_size(2);
   set_body_type("snake");
   set_alignment(5);
   set_hd(15,8);
   //set_level(15);
   //set_class("fighter");
   //set_mlevel("fighter",15);
   set_hp(random(30)+110);
   set_stats("intelligence",4);
   set_stats("strength",16);
   set_overall_ac(4);
   add_limb("right foreleg","torso",0,0,0);
   add_limb("left foreleg","torso",0,0,0);
   add_limb("right rear leg","torso",0,0,0);
   add_limb("left rear leg","torso",0,0,0);
   add_limb("right claw","right foreleg",0,0,0);
   add_limb("left claw","left foreleg",0,0,0);
   set_damage(1,5);
   set_attacks_num(2);
   set_base_damage_type("slashing");
   set_attack_limbs(({"right claw","left claw"}));
   set_exp(1500);
   set("aggressive",10);
   set_property("swarm",1);
   if(!random(10)) add_money("silver",random(500)+500);
   if(!random(4)) add_money("gold",random(200)+200);
   set_funcs(({"stone"}));
   set_func_chance(10);
   set_max_level(12);
}

void reset()
{
   ::reset();
   if(!random(8)) {
      new("/d/antioch/valley/obj/gem")->move(TO);
   }
}

void stone(object targ)
{
   if(!"/daemon/saving_throw_d.c"->fort_save(targ,-10)){
      tell_object(targ,"%^ORANGE%^The basilisk stares into your eyes and turns you to stone!");
      tell_room(ETO,"%^ORANGE%^You watch in horror as the basilisk stares"+
      " at "+targ->query_cap_name()+" and turns "+targ->query_objective()+""+
      " to stone!",targ);
      targ->set_hp(-1);
      return 1;
   }
   else {
      tell_object(targ,"%^GREEN%^The basilisk begins to stare at you but"+
      " you break away your gaze and manage to resist the spell!");
      tell_room(ETO,"%^GREEN%^"+targ->query_cap_name()+" breaks "+targ->query_possessive()+""+
      " gaze away from the basilisk.",targ);
      return 1;
   }
}
