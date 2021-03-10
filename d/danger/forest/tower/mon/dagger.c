#include <std.h>

inherit WEAPONLESS;

void create() {
   ::create();
   set_name("dagger");
   set_id(({"dagger"}));
   set_short("A Floating Dagger");
   set_long("If this dagger was not floating, it would"+
   " be just another dagger.");
   set_class("thief");
   set_mlevel("thief", 50);
   set_guild_level("thief", 50);
   set_max_hp(2000);
   set_hp(2000);
   set_exp(100000);
   set_overall_ac(-20);
   set_property("weapon resistance", 4);
   set_attack_limbs(({"bladed edge"}));
   set_base_damage_type("slashing");
   set_attacks_num(4);
   set_damage(3,8);
   set_gender("neuter");
   set_race("dagger");;
   set_property("swarm", 1);
   set_stats("strength", 25);
   set_stats("dexterity", 25);
   set_stats("constitution", 25);
   set_stats("wisdom", 1);
   set_stats("intelligence", 1);
   set_stats("charisma", 1);
   set_funcs(({"stab"}));
   set_invis();
   set_property("magic",1);
   set_func_chance(10);
   set_monster_feats(({"parry"}));
}


void stab(object targ){
int max_hp;
   max_hp = (int)targ->query_max_hp();
   tell_room(ETO, "The dagger finds its way behind "+targ->query_cap_name()+" and plants itself into "+targ->query_possessive()+" back!", targ);
   tell_object(targ, "The dagger finds itself behind you and plants itself into your back!");
   targ->do_damage("torso", max_hp-100);
}


