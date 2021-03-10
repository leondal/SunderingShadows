//felemental.c

#include <std.h>

inherit WEAPONLESS;

void create(){
  ::create();
    
    set_name("fire elemental");
    set_id(({"fire","fire elemental","elemental","felemental"}));
    
    set("short","fire Elemental");
    set("long",
@PEG
    %^BOLD%^%^YELLOW%^You look into this inferno. It has almost what 
look like arms, maybe even a face. You haistly look for water or 
anything to hide in. This creature is truly fearsome you think of the 
pain that could be caused by all this fire.
PEG
	);
    set_hd(4 + (4 *(random(3)+1)),1);
    set_hp(query_hd()*8);
    set_exp((query_hd()-6)* 1000);
    set_stats("strength",18);
    set_stats("intelligence",7);
    set_stats("dexterity",4);
    set_race("elemental");
    add_limb("torso","torso",50,0,2);
    add_limb("right flame","torso",50,0,2);
    add_limb("left flame","torso",50,0,2);
    add_limb("base","torso",50,0,2);
    set_attack_limbs(({"left flame", "right flame"}));
    set_damage(4,8);
    set_attacks_num(1);
    set_base_damage_type("bludgeoning");
    set_gender("sexless");
    set_overall_ac(4);
  }


