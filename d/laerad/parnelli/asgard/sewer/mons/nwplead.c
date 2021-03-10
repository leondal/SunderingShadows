inherit "/std/monster";
#include "../lizard.h"

void create() {
  	::create();
  	set_name("subleader");
  	set_id(({"subleader","lizard","lizardman"}));
  	set("race","lizardman");
  	set_gender("male");
  	set_short("%^BOLD%^%^GREEN%^Lizardman Subleader%^RESET%^");
  	set_long("Standing over 6' tall this reptile walks on 2 legs like a man.  "+
        	"His hide is green with mottled brown markings.  He appears to handle "+
        	"his weapons well.");
  	set_overall_ac(-2);
  	set_body_type("human");
    	set_class("ranger");
    	set_mlevel("ranger", 18);
    	set_property("full attacks",1);
  	set("aggressive",18);
  	set_alignment(9);
  	set_size(2);
  	set_hd(18,1);
  	set_stats("strength",random(6)+13);
  	set_stats("charisma", 6);
  	set_stats("dexterity",random(6)+12);
  	set_stats("constitution",10);
  	set_stats("wisdom",9);
  	set_stats("intelligence",9);
  	set_hp(85);
  	set_exp(2500);
  	set_wielding_limbs(({"right hand","left hand"}));
  	new(SHWEAP+"longsword")->move(this_object());
  		command("wield sword");
  	new(SHWEAP+"shortsword")->move(this_object());
  		command("wield sword");
  	add_money("silver",random(1500));
  	add_money("gold",random(750));
  	new(LOBJ+"mushroom")->move(this_object());
  	new("/d/common/obj/misc/pouch.c")->move(this_object());
  		command("wear pouch");
  		command("put mushroom in pouch");
      add_search_path("/cmds/ranger");
    	set_emotes(3,({
		"The lizardman claws at your face.",
		"The subleader licks the blood from his blade!",
		"%^BOLD%^%^GREEN%^Lizardman hisses: %^RESET%^Yousss diesss nowsss!",
		"The lizardman hisses loudly for reinforcements.",
		"The lizardman swings his tail around to hit you.",
		"The subleader hisses.",
		"The subleader tests the air with his forked tongue.",
		"The subleader twitches his tail angrily.",
		"%^BOLD%^%^GREEN%^Lizardman hisses: %^RESET%^Sssssoon wesss goessss.",
		"%^BOLD%^%^GREEN%^Lizardman hisses: %^RESET%^Sssssomeonesss issss "+
			"closesss...i can tassste them.",
		"The subleader flickers his forked tongue in and out.",
		"The subleader narrows his reptilian eyes at you.",
    	}),0);
}
