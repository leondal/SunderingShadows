//For Creature of Darkness - Sharran Spell

#include <std.h>

inherit WEAPONLESS;

void create(){
   int num;
  
   ::create();
    set_name("creature of darkness");
    set_id(({"creature","elemental","darkness"}));
    set_short("%^BOLD%^%^BLACK%^Creature of Darkness%^RESET%^");
    set("long",
@CYTHERA
    %^BOLD%^%^BLACK%^Composed out of shadows and darkness, this bipedal creature has a vague human-like appearance. The shadowy smoke-like substance that makes up the creatures body is thick and opaque, not allowing any light to pierce the darkness of its form.  Two arm-like appendages extend outwards from the creature's body, each arm ending with five claws.  The lower waist of the creature ends in a hazy swirling mass of darkness, never allowing the creature to touch the ground.
CYTHERA
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
    set_stats("intelligence",10);
    set_stats("dexterity",22);
    set_race("creature");
    set_damage(2,10);
    set_attacks_num(1);
    set_base_damage_type("slashing");
    set_gender("sexless");
    set_overall_ac(0);
}
int isMagic() {return 5;}
