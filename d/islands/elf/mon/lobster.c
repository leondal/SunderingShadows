#include <std.h>
#include "../elf.h"
inherit MONSTER;

void create()
{
    ::create();
    set_name("Dire Lobster");
    set_id(({"lobster","dire lobster","monster","animal"}));
    set_short("Dire lobster");
    set_long("This is a dire lobster.  It is about 6 feet"+
    " high and 15 feet long.  It has two large claws and a "+
    "really big tail that looks like it could push a lot of water.");
    set_race("lobster");
    set_class("barbarian");
    set_mlevel("barbarian",46);
    level = 46;
    set_guild_level("barbarian",46);
    set_max_level(47);
    set_property("swarm",1);
    set_body_type("arachnid");
    set_attack_limbs(({"tail","right pincer","left pincer"}));
    set_monster_feats(({
        "scramble",
        "unarmed parry",
      })); 
    set_resistance_percent("slashing", 50);
    set_resistance_percent("bludgeoning", 70);
    set_hd(35,10);
    set_hp(750+random(1500));
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
    set_damage(4,10);
    set_property("swarm", 1);
    set_new_exp(level, "normal");
    set_size(3);
    add_attack_bonus(64); 
    set_alignment(4);
    set_property("full attacks",1);
    set_property("no knockdown", 1);
    set_funcs(({"snip", "sweep"}));
    set_func_chance(75);
    set_skill("perception", 70);
    set_property("no knockdown", 1);
    set_property("water breather", 1);
    set_skill("perception",50); 
    set("aggressive",25);
    set_hp(query_max_hp());
    set_property("function and attack",1);
}

void sweep(object targ){
  object * critters;
  critters = query_attackers();
  if (sizeof(critters)<1) return;
  tell_room(ETO,"%^ORANGE%^Dire lobster sweeps a %^RED%^claw%^ORANGE%^ across the room!");
  foreach(object ob in critters){
      tell_object(ob, "%^ORANGE%^The lobster sweeps a %^RED%^claw%^ORANGE%^ across the room hitting you hard." );
      ob->cause_typed_damwizage(ob, ob->return_target_limb(),random(200),"bludgeoning");
  }
  
}
void snip(object targ){
    if(userp(targ)){
        tell_room(ETO, "%^ORANGE%^Dire lobster snips at "+targ->query_cap_name()+" and catches them in the giant claw!");
        tell_object(targ,"%^ORANGE%^The Dire lobster's claw snap shut with you in them!");
        if(!"/daemon/saving_throw_d.c"->reflex_save(targ,-30))
          targ->set_paralyzed(10 + random(10),"%^RED%^You are held by lobster claw.");
        targ->cause_typed_damage(targ, targ->return_target_limb(),random(250)+50,"slashing");
    }
    //insta ded for fodder
    else {
        tell_room(ETO,"%^ORANGE%^The lobster slices "+targ->query_cap_name()+" in half!");
        targ->die();
    }

}