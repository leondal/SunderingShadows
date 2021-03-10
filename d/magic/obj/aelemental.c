//aelemental.c

#include <std.h>

inherit WEAPONLESS;

void create(){
   int num;
  
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
	num = random(100);
	switch(num){
	    case 0..59: set_hd(12,1);
	                break;
	    case 60..94: set_hd(16,1);
	                 break;
	    case 95..99: set_hd(21+random(4),1);
	                 break;
        default: set_hd(12,1);
                 break;
	}
    set_hp(query_hd()*8);
   set_exp(1);
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
    set_overall_ac(0);
}
int isMagic() {return 5;}
