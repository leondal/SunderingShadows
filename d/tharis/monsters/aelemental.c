//aelemental.c

#include <std.h>

inherit WEAPONLESS;

void create(){
  ::create();
    
    set_name("air elemental");
    set_id(({"elemental","air elemental","aelemental"}));
    
    set("short","Air Elemental");
    set("long",
@PEG
    %^BOLD%^%^CYAN%^This appears to be a large hazy cloud. However
you think you can make out the outline of a face in the mist. You
have heard the stories of the battle skills of air elementals. There 
ability to do massive damage to their enemies.
PEG
	);
    set_hd(4 + (4 *(random(3)+1)),1);
    set_hp(query_hd()*8);
    set_exp((query_hd()-6)* 1000 + 1000);
    set_stats("strength",18);
    set_stats("intelligence",7);
    set_stats("dexterity",25);
    set_race("elemental");
    add_limb("torso","torso",50,0,2);
    add_limb("right spindal","torso",50,0,2);
    add_limb("left spindal","torso",50,0,2);
    add_limb("base","torso",50,0,2);
    set_attack_limbs(({"base"}));
    set_damage(2,10);
    set_attacks_num(1);
    set_base_damage_type("bludgeoning");
    set_gender("sexless");
    set_overall_ac(4);
  }


