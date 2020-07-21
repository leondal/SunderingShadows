#include <std.h>
#include <daemons.h>
#include "../elf.h"
inherit MONSTER;
#define PDIR "/d/common/obj/poisons/base/"

void create()
{
    ::create();
    set_name("stingray");
    set_id(({"stingray","dire stingray","monster","animal"}));
    set_short("Dire Stingray");
    set_long("This is a dire stingray.  It is 12 feet long,"+
    " has a flat body and a pointy tail with a stinger on the end.");
    set_race("stingray");



    set_class("barbarian");
    set_mlevel("barbarian",46);
    level = 46;
    set_guild_level("barbarian",46);
    set_max_level(47);
    set_property("swarm",1);
    set_monster_feats(({
        "regeneration",
        "damage resistance",
      })); 
    set_resistance_percent("slashing", 50);
    set_resistance_percent("bludgeoning", 50);
    set_hp(query_max_hp());
    set_property("swarm", 1);
    set_overall_ac(-35);
    set_size(3);
    add_attack_bonus(65);
    set_stats("strength",28);
    set_stats("dexterity",16);
    set_stats("intelligence",4);
    set_stats("wisdom",12);
    set_stats("constitution",30);
    set_stats("charisma",5);
    set_attacks_num(5);
    set_damage(3,9);
    set_property("swarm", 1);
    set_new_exp(level, "normal");
    set_size(3);
    add_attack_bonus(64); 
    set_alignment(4);
    set_property("full attacks",1);
    set_funcs(({"sting"}));
    set_func_chance(75);
    set_skill("perception", 70);
    set_property("no knockdown", 1);
    set_property("water breather", 1);
    set_skill("perception",50); 
    set("aggressive",25);
}
void snip(object targ){
    string poisonf;
    poisonf = PDIR+POISONS[random(sizeof(POISONS))];
    if(userp(targ)){
        tell_room(ETO, "%^ORANGE%^Dire stingray's tail stabs "+targ->query_cap_name()+
        ".");
        tell_object(targ,"%^ORANGE%^Stingray's tail stabs you!");
        if(!"/daemon/saving_throw_d.c"->fort_save(targ,-30))
           POISON_D->ApplyPoison(targ,"large_scorpion_venom",TO,"injury");
        targ->cause_typed_damage(targ, targ->return_target_limb(),random(250),"bludgeoning");
    }
    //insta ded for fodder
    else {
        tell_room(ETO,"%^ORANGE%^Stingray's tail stabs "+
        targ->query_cap_name()+" and they fall to the ground dead.");
        targ->die();
    }

}