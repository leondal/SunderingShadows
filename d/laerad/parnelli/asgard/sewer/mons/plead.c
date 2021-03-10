#include <std.h>
#include "../lizard.h"

inherit MONSTER;

void create() {
	object obj; 
  	::create();
  	set_name("subleader");
  	set_id(({"subleader","lizard","lizardman"}));
  	set("race","lizardman");
  	set_property("water breather",1);
  	set_gender("male");
  	set_short("%^BOLD%^%^GREEN%^Lizardman Subleader%^RESET%^");
  	set_long("Standing over 6' tall this reptile walks on 2 legs like a man.  "+
        	"His hide is green with mottled brown markings.  He appears to handle "+
        	"his weapons well.");
	set_speed(25);
  	set_overall_ac(2);
  	set_body_type("human");
    	set_class("fighter");
    	set_mlevel("fighter", 18);
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
  	new(SHWEAP+"longsword")->move(TO);
  		command("wield sword");
  	new(SHWEAP+"shortsword")->move(TO);
  		command("wield sword");
  	add_money("silver",random(1500));
  	add_money("gold",random(750));
	obj=new("/d/common/obj/rand/rand_leath_head.c");
	obj->remove_property("enchantment");
	obj->set_property("enchantment",1);
		if(random(5)){
	obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	obj=new("/d/common/obj/rand/s_curiass.c");
	obj->set_property("enchantment",1);
		if(random(4)){
	obj->set_property("monsterweapon",1);
		}
	obj->move(TO);
	command("wearall");
  	new(LOBJ+"mushroom")->move(TO);
  	new("/d/common/obj/misc/pouch.c")->move(TO);
  		command("wear pouch");
  		command("put mushroom in pouch");
    	set_emotes(3,({
		"The subleader licks the blood from his blade!",
		"%^BOLD%^%^GREEN%^Lizardman hisses: %^RESET%^Yousss diesss nowsss!",
		"The lizardman hisses loudly for reinforcements.",
		"The lizardman swing his tail around to hit you.",
		"The lizardman claws at your face.",
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

