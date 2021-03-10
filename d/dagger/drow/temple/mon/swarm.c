#include <std.h>
#include "/d/dagger/drow/temple/short.h"
inherit MONSTER;
void create() {
    :: create();
    set_name("swarm");
    set_id(({
      "swarm","swarm of spiders","spiders","spider swarm"
      }));
    set_short("%^RESET%^%^RED%^Swarm of spiders%^RESET%^");
    set_long(
        "%^RESET%^%^RED%^You are staring at a massive swarm "
	"of flying stinging spiders. There are many various "
	"sizes and shapes and types of spiders, all highly "
	"aggitated and aggressive.%^RESET%^"
    );
    set_gender("female");
    set_hd(20,4);
    set_size(3);
    set_wielding_limbs(({"right hand","left hand"}));
    set_overall_ac(-5);
    set_hp(200);
    set_property("no bump",1);
    set_mob_magic_resistance("average");
    set_property("swarm",1);
    set_max_hp(200);
    set_exp(12000);
    set_body_type("humanoid");
    set_race("arachnid");
    set_class("cleric");
    set_stats("strength",19);
    set_stats("constitution",19);
    set_stats("dexterity",20);
    set_stats("wisdom",20);
    set_stats("intelligence",20);
    set_stats("charisma",17);
    set_alignment(9);
    set("aggressive",22);
    set_funcs(({"moves"}));
    set_func_chance(100);
}
int moves() {
    object ob = this_object();
    object targ = ob->query_current_attacker();
    int i,x;
    i = random(TO->query_hp());
    i = i + (int)targ->query_level();
    i = i/2;
    if(i < 5 ) i = 5;
    for(x=0;x<i;x++) {
	if(random(6) < 3) {
	    tell_object(targ,
	        "%^RED%^A small flying stinging spider bites you!%^RESET%^"
            );
            tell_room(environment(targ),
	        "%^RED%^A small flying stinging spider bites "
		+targ->query_cap_name()+
		"!%^RESET%^"
    	    ,targ);
                targ->do_damage("torso",(((int)targ->query_max_hp()/100)+1));
            targ->add_poisoning(1);
	} else {
	    tell_object(targ,
		"%^GREEN%^A small flying stinging spider misses you!"
		"%^RESET%^"
	    );
	    tell_room(environment(targ),
		"%^GREEN%^A small flying stinging spider misses "
		+targ->query_cap_name()+
		"!%^RESET%^"
	    ,targ);   
	}
    }
    return 1;
}	

