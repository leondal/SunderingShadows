#include <std.h>
#include "../valley.h"
inherit DRUIDA;

void create()
{
	::create();
// set_property wasn't controlling them, needs to be set_unique.  *Styx* 6/2002
//	set_property("unique",1);
	set_unique(1);
	set_name("Celania");
	set_id(({"druid","dragon","bear","wolf","drake","wolverine","great bear","grizzly bear","celania","Celania"}));
	set_short("Celania, a druid of the Vale");
	set_long(
	"Celania is a young druid, dedicated to restoring the balance of Moonstone Vale,"+
	" which has sorely been over-run by evil. She wears a robe of some rough looking"+
	" material, dyed a deep green. A rope belt is tied around her waist and she has a"+
	" pouch filled with herbs. Although bare handed, she is far from defenseless."+
	" This girl seems even younger than most of the other druids, and yet it is clear"+
	" she commands awesome powers even at such an early age. Her sky blue eyes"+
	" sparkle with life, and there is the hint of a smile tugging at her pink lips."+
	" She looks more human than elven, but with delicate features. Her straw blonde"+
	" hair has been separated into two braids that fall to her sides."
	);
	set_speed(20);
	set_race("half-elf");
	set_body_type("humanoid");
	set_max_hp(random(100)+150);
	set_hp(query_max_hp());
	set_size(2);
	set_overall_ac(-3);
	set_attack_limbs(({"left hand","right hand"}));
	set_attacks_num(2);
	set_base_damage_type("slashing");
	set_damage(1,6);
	set_spells(({
		"call lightning",
		"hold person",
		"cause blindness",
		"limb attack",
		"cause serious wounds",
	}));
	set_spell_chance(80);
	if(!present("pouch")) {
		new(OBJ+"belt_pouch")->move(TO);
	}
	if(!present("belt")) {
		new(OBJ+"rope_belt")->move(TO);
		command("wear belt");
	}
	switch(random(2)) {
		case 0:
			new(OBJ+"herb")->move(TO);
			break;
		case 1:
			new(OBJ+"herb2")->move(TO);
			break;
	}
}
