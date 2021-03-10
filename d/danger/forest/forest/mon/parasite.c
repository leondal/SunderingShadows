
#include <std.h>

inherit WEAPONLESS;

void create() {
   ::create();
   set_name("screamer");
   set_id(({"screamer","wide-mouth","wide mouth"}));
   set_short("Wide-Mouth Screamer");
   set_long("The first thing that catches your attention"+
   " about this four legged creature is the"+
   " obvious source of its name."+
   " Its mouth is composed of four different mandibles"+
   " allowing it to open in every direction. When open"+
   " the mouth is forms a square large enough to swallow"+
   " a man whole. With large canine teeth bordering its jaw in"+
   " every direction, sharp claws extending from its forepaws,"+
   " and the agility and speed of a much smaller creature"+
   " gives this creature a truly menacing apperance.");
   set_class("fighter");
   set_mlevel("fighter", 50);
   set_guild_level("fighter", 50);
   set_max_hp(600);
   set_hp(6000);
   set_exp(1000);
   set_overall_ac(-45);
   set_body_type("dog");
   set_gender("female");
   set_race("screamer");
   set_property("weapon resistance", 4);
   set_attacks_num(4);
   set_damage(3,4);
   set_attack_limbs(({"right claw","left claw","mouth"}));
   set_property("swarm", 1);
   set_stats("strength", 20);
   set_stats("dexterity", 20);
   set_stats("constitution", 18);
   set_stats("wisdom", 3);
   set_stats("intelligence", 8);
   set_stats("charisma", 1);
   set_funcs(({"scream","acid","claw","thrash"}));
   set_func_chance(65);
}


void thrash(object targ){
int max_hp;
   max_hp = (int)targ->query_max_hp();
   tell_room(ETO, "The screamer latches onto "+targ->query_cap_name()+" and thrashes whoever about, before letting go!", targ);
   tell_object(targ, "The screamer latches onto your arm with its large mouth and thrashes you about, before letting go!");
   targ->do_damage("torso", max_hp/5);
}

void claw(object targ){
int max_hp;
   max_hp = (int)targ->query_max_hp();
   tell_room(ETO, "The screamer rears itself up on its hind legs and tears into "+targ->query_cap_name()+"!", targ);
   tell_object(targ, "The screamer rears itself up on its hind legs and tears into you!");
   targ->do_damage("torso", max_hp/5);
}

void acid(object targ){
int max_hp;
   max_hp = (int)targ->query_max_hp();
   tell_room(ETO, "The screamer spits a vile acid all over "+targ->query_cap_name()+"!", targ);
   tell_object(targ, "The screamer spits a vile acid all over you and it burns through your protection rapidly!");
   set_property("magic",1);
   targ->do_damage("torso", max_hp/5);
   remove_property("magic");
}

void scream(object targ){
int max_hp;
   max_hp = (int)targ->query_max_hp();
   tell_room(ETO, "The creature lets loose a shriek in the direction of "+targ->query_cap_name()+"!", targ);
   tell_object(targ, "The screamer lets loose a shriek that tears at your brain!");
   set_property("magic",1);
   targ->do_damage("torso", max_hp/5);
   remove_property("magic");
}