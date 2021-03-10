#include <std.h>
#include "../elf.h"
inherit MONSTER;

void create()
{
    ::create();
    set_name("Dire Crab");
    set_id(({"crab","dire crab","monster"}));
    set_short("Dire Crab");
    set_long("This is a dire crab.  It is around 12 feet high and"+
    " two giant pincers.  They wander the ocean floor looking for things to eat.");
    set_race("crab");
    set_hd(35,10);
    set_hp(750+random(1500));


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
    set_resistance_percent("bludgeoning", 70);
    set_hp(query_max_hp());
    set_property("swarm", 1);
    set_overall_ac(-35);
    set_body_type("arachnid");
    set_attack_limbs(({"right pincer","left pincer"}));
    add_attack_bonus(65);
    set_stats("strength",28);
    set_stats("dexterity",16);
    set_stats("intelligence",4);
    set_stats("wisdom",12);
    set_stats("constitution",30);
    set_stats("charisma",5);
    set_attacks_num(5);
    set_damage(4,9);
    set_property("swarm", 1);
    set("aggressive", 6);
    set_new_exp(level, "normal");
    set_size(3);
    add_attack_bonus(64); 
    set_alignment(4);
    set_property("full attacks",1);
    set_funcs(({"snip", "sweep"}));
    set_func_chance(75);
    set_skill("perception", 70);
    set_property("no knockdown", 1);
    set_property("water breather", 1);
    set_property("function and attack",1);
    set_skill("perception",50); 
    set("aggressive",25);
}

void sweep(object targ){
  object * critters;
  critters = query_attackers();
  if (sizeof(critters)<1) return;
  tell_room(ETO,"%^ORANGE%^Dire Crab sweeps a claw across the room!");
  foreach(object ob in critters){
      tell_object(ob, "%^ORANGE%^The crab sweeps a claw across the room hitting you hard." );
      ob->cause_typed_damwizage(ob, ob->return_target_limb(),random(200),"bludgeoning");
  }
  
}
void snip(object targ){
    if(userp(targ)){
        tell_room(ETO, "%^ORANGE%^Dire Crab snips at "+targ->query_cap_name()+" and catches them in the giant claw!");
        tell_object(targ,"%^ORANGE%^The Dire crab's claw snap shut with you in them!");
        if(!"/daemon/saving_throw_d.c"->reflex_save(targ,-30))
          targ->set_paralyzed(10 + random(10),"%^RED%^You are held by crab claw.");
        targ->cause_typed_damage(targ, targ->return_target_limb(),random(250)+50,"bludgeoning");
    }
    //insta ded for fodder
    else {
        tell_room(ETO,"%^ORANGE%^The crab slices "+targ->query_cap_name()+" in half!");
        targ->die();
    }

}