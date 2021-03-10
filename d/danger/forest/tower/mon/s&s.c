#include <std.h>

inherit WEAPONLESS;

void create() {
   ::create();
   set_name("sword & shield");
   set_id(({"sword","shield","sword & shield","sword and shield"}));
   set_short("A Floating Sword & Shield");
   set_long("If this sword and shield was not floating, it would"+
   " be just another sword and shield.");
   set_class("fighter");
   set_mlevel("fighter", 50);
   set_guild_level("fighter", 50);
   set_max_hp(6000);
   set_hp(6000);
   set_exp(100000);
   set_overall_ac(-52);
   set_property("weapon resistance", 4);
   set_attack_limbs(({"bladed edge"}));
   set_base_damage_type("slashing");
   set_attacks_num(4);
   set_damage(3,8);
   set_gender("neuter");
   set_race("sword and shield");;
   set_property("swarm", 1);
   set_stats("strength", 25);
   set_stats("dexterity", 25);
   set_stats("constitution", 25);
   set_stats("wisdom", 1);
   set_stats("intelligence", 1);
   set_stats("charisma", 1);
   set_funcs(({"rush","bash"}));
   set_func_chance(65);
   set_monster_feats(({"shieldbash",
                       "counter",
                       "parry",
                       "deflection"}));
   set_property("spell penetration",100);
   set_property("spellturning",50);
   set_property("spellturning-mage",1);
}


void rush(object targ){
   tell_room(ETO, "The sword and shield gathers momentum and slams into "+targ->query_cap_name()+" at full force!", targ);
   tell_object(targ, "The sword and shield gathers momentum and slams into you with full force!");
   targ->do_damage("torso", random(200));
}

void bash(object targ){
   TO->force_me("shieldbash "+targ->query_name());
}

