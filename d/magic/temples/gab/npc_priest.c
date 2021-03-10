#include <std.h>
#include <daemons.h>
#include "../loviatar.h"
inherit MONSTER;

int rlevel;

create() {
	::create();
   set_name("loviatar priest");
   set_id(({"monster","loviatar priest","priest"}));
    	set_short("loviatar priest");
    	set_long("The priest looks to be in good health, but "+
    		"you can see fresh, healing wounds intermixed with "+
    		"new and old scars.  The priest look to be lost in "+
    		"thought as he wanders about the room muttering to himself."
    	);
    	rlevel = random(11) + 10;
    	set_body_type("human");
     	set_gender("male");
 		set_level(rlevel);
   	set_hd(rlevel,8);
    	set_class("cleric");
    	set_mlevel("cleric", rlevel);
  		set_size(2);
    	add_search_path("/cmds/cleric");
    	set_diety("loviatar");
      set_wielding_limbs(({"right hand","left hand"}));
    	set_stats("intelligence",14+random(5));
    	set_stats("wisdom",16+random(3));
    	set_stats("strength",14+random(5));
    	set_stats("charisma",9+random(10));
    	set_stats("dexterity",10+random(9));
    	set_stats("constitution",12+random(7));
    	set_alignment(6);
    	set_race("human");
    	set_overall_ac(9);
    	set_exp(100+random(400));
    	set_max_hp(random(100)+8*rlevel);
    	set_hp(query_max_hp());
    	set_emotes(1,({
			"%^CYAN%^The priest chants to Loviatar.",
        	"%^CYAN%^The priest moves about the room without purpose.",
        	"%^CYAN%^The priest straightens out one of the red rugs.",
			"%^CYAN%^The priest chants: %^RESET%^Her love is like a razor blade.",
			"%^CYAN%^The priest chants: %^RESET%^Adore the gain, treasure the pain.",
			"%^CYAN%^The priest chants: %^RESET%^Without gain, how "+
				"may one know loss?",
			"%^CYAN%^The priest places a branding iron in the hottest of the coals.",
			"%^CYAN%^The priest busies himself straightening the room up a bit.",
			"%^CYAN%^The priest chants: %^RESET%^Ahhhhh, the exquisite lash!"
    	}),0);
    	set_max_level(20);
        new("/d/magic/symbols/loviatar_symbol")->move(TO);
     	set_spell_chance(30);
   	set_spells( ({
    		"cause light wounds",
    		"hold person",
    		"cause serious wounds",
    		"limb attack",
    		"kiss of torment",
    		"flame strike"
    		}));

    	command("speak common");
    	command("speech chant");
   add_money("gold",random(40));
   add_money("silver",random(800));
   add_money("copper",random(400));
}
