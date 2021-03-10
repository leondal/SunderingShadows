
#include <std.h>
#include <daemons.h>

inherit WEAPONLESS;

void create() {
   ::create();
   set_name("battle axe");
   set_id(({"battle axe","axe"}));
   set_short("A Floating Battleaxe");
   set_long("If this axe was not floating, it would"+
   " be just another two handed battle axe.");
   set_class("fighter");
   set_mlevel("fighter", 50);
   set_guild_level("fighter", 50);
   set_max_hp(4000);
   set_hp(4000);
   set_exp(100000);
   set_overall_ac(-45);
   set_gender("neuter");
   set_race("axe");
   set_property("weapon resistance", 4);
   set_attack_limbs(({"bladed edge"}));
   set_base_damage_type("slashing");
   set_attacks_num(6);
   set_damage(5,8);
   set_property("swarm", 1);
   set_stats("strength", 25);
   set_stats("dexterity", 25);
   set_stats("constitution", 25);
   set_stats("wisdom", 1);
   set_stats("intelligence", 1);
   set_stats("charisma", 1);
   set_funcs(({"rush","cleave","trip","daze"}));
   set_func_chance(65);
   set_monster_feats(({"daze"}));
}


void rush(object targ){
   tell_room(ETO, "In the blink of an eye the axe accelerates and slams into "+targ->query_cap_name()+" with teeth shattering force!", targ);
   tell_object(targ, "The axe breaks from combat and slams into you with teeth shattering force!");
   targ->do_damage("torso", random(50)*8);
}

void cleave(object targ){
   object *vars;
   int i,max_hp;
   max_hp = (int)targ->query_max_hp();
   if(!objectp(TO)) return;
   vars = all_living(ETO);
   vars = filter_array(vars,"is_non_immortal_player",FILTERS_D);
   for(i=0;i<sizeof(vars);i++){
   if(vars[i] == TO) continue;
   tell_object(vars[i],"The battle axe cleaves through the air with great force, cutting through everything in its path!");
   vars[i]->do_damage("torso", max_hp/2);
   }
}

void trip(object targ){
   tell_room(ETO, "The axe spins suddenly and drives its shaft into "+targ->query_cap_name()+"!", targ);
   tell_object(targ, "The axe spins suddenly and drives its shaft into your sternum, knocking the wind out of you!");
   targ->set_paralyzed(25, "You are trying to catch your breath!");
}

void daze(object targ){
   TO->force_me("daze "+targ->query_name());
}
