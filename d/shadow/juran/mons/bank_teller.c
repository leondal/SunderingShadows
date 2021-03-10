#include <std.h>
#include "../juran.h"
inherit TOWNSMAN;

void create(){
	::create();
	set_name("Grubtake");
	set_short("Grubtake, the bank teller");
	set_id(({"monster","Grubtake","bank teller","teller","grubtake"}));
	set_long(
		"Grubtake is a greedy orc. He has sparse hair on his head. "+
		"His red beady eyes glitter as he counts the money and "+
		"occassionally he has to wipe drool off his chin and the coins.\n"
	);
	set_gender("male");
	set_race("orc");
	set_hd(10,5);
	set_max_hp(100+random(25));
	set_hp(query_max_hp());
	set_alignment(3);
  	set_size(2);
	set_overall_ac(-10);
	set_class("mage");
	set_mlevel("mage",10);
	set_level(10);
	set_stats("intelligence",20);
	set_stats("charisma",16);
	set_stats("wisdom",14);
	set_stats("strength",8);
	set_stats("dexterity",10);
	set_stats("constitution",12);
	set_emotes(1,({
		"Grubtake happily counts and recounts the money.",
		"Grubtake scratches down some figures on a piece of paper.",
		"Grubtake tosses a counted bag of gold over his shoulder into the vault.",
		"Grubtake smiles at the ogre bank guard.",
	}),0);
	set_exp(1000);
	set_property("swarm",1);
	set("aggressive",0);
	set_spells(({
		"fireball",
		"web",
		"scorcher",
		"magic missile",
		"burning hands",
	}));
	set_spell_chance(100);
     	set_spoken("wizish");
}
