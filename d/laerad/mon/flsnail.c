#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"snail","flail snail"}));
    set_name("Flail Snail");
    set_short("A Flail Snail");
    set_long("A very large snail protected by a huge shell. It has many flail like tentacles coming out of its shell.");
    set_body_type("snake");
    set_race("snail");
    set_gender("male");
    set_class("ranger");
    set_guild_level("ranger",8);
    set_size(2);
    set_hd(8,1);
    set_hp(85);
    set("aggressive",13);
    set_overall_ac(-2);
    set_exp(1200);
    set_mob_magic_resistance("average");
    set_property("swarm",1);
    add_limb("tentacle1","head",0,0,0);
    add_limb("tentacle2","head",0,0,0);
    add_limb("tentacle3","head",0,0,0);
    add_limb("tentacle4","head",0,0,0);
    add_limb("shell","torso",0,0,0);
    set_attack_limbs(({"tentacle1","tentacle2","tentacle3","tentacle4"}));
    set_attacks_num(4);
    set_base_damage_type("bludgeoning");
    set_damage(1,12);
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case

}
