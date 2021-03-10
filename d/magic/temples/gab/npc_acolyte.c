#include <std.h>
#include <daemons.h>
#include "../loviatar.h"
inherit MONSTER;

create() {
	::create();
   set_name("loviatar acolyte");
   set_id(({"monster","loviatar acolyte","acolyte"}));
    	set_short("loviatar acolyte");
    	set_long("This miserable, would-be cleric seems to be "+
    		"suffering badly.  His face is contorted in continual "+
    		"discomfort and you notice a number of his fingernails "+
    		"are missing.  There are scratches and bruises visible on his forearms."
    	);
    	set_body_type("human");
     	set_gender("male");
    	set_hd(4,4);
    	set_class("cleric");
    	set_mlevel("cleric", 4);
  		set_size(2);
    	add_search_path("/cmds/cleric");
    	set_diety("loviatar");
      set_wielding_limbs(({"right hand","left hand"}));
    	set_stats("intelligence",14);
    	set_stats("wisdom",16);
    	set_stats("strength",14);
    	set_stats("charisma",9);
    	set_stats("dexterity",10);
    	set_stats("constitution",12);
    	set_alignment(3);
    	set_race("human");
    	set_overall_ac(9);
    	set_exp(100);
    	set_max_hp(random(10)+60);
    	set_hp(70);
    	set_emotes(1,({
			"%^CYAN%^The acolyte mumbles a chant to Loviatar.",
        	"%^CYAN%^The acolyte shuffles across the room.",
        	"%^CYAN%^The acolyte screams and hops about as a splinter finds his foot.",
			"%^CYAN%^The acolyte intones: %^RESET%^Loviatar is wonderous in her cruelty.",
			"%^CYAN%^The acolyte intones: %^RESET%^We must be cruel to be kind, "+
				"the velvet glove o'er the mailed fist.",
			"%^CYAN%^The acolyte intones: %^RESET%^Without gain, how "+
				"may one know loss?",
			"%^CYAN%^The takes down a whip from the rack and walks "+
				"over to the shrine.\nThe acolyte kneels suddenly and "+
				"starts to loudly chant prayers to Loviatar while "+
				"striking himself across the back with the whip.\nThe "+
				"acolyte grits his teeth in an effort not to cry out in pain."
    	}),0);
    	set_max_level(10);
   	new("/d/magic/symbols/loviatar_symbol");
     	set_spell_chance(15);
   	set_spells( ({
    		"cause light wounds",
    		"hold person",
    		"cause serious wounds",
    		"limb attack"
    		}));

    	command("speak common");
    	command("speech intone");
   add_money("gold",random(10));
   add_money("silver",random(50));
   add_money("copper",random(200));
}