#include <std.h>
#include "../valley.h"
inherit DRUIDA;

void create()
{
	::create();
	set_unique(1);
//	set_property("unique",1);
	set_name("Elalonna");
	set_id(({"druid","dragon","bear","wolf","drake","wolverine","great bear","grizzly bear","Elalonna","elalonna"}));
	set_short("Elalonna, a druid of the Vale");
	set_long(
	"Elalonna is a young druid, dedicated to restoring the balance of Moonstone Vale,"+
	" which has sorely been over-run by evil. She wears a robe of some rough looking"+
	" material, dyed a deep green. A rope belt is tied around her waist and she has a"+
	" pouch filled with herbs. Although bare handed, she is far from defenseless."+
	" This woman is the picture of beauty, with pitch black hair that falls in waves"+
	" down to her knees and curves in all the right places. Her skin is a pale white,"+
	" perfect in complexion, and offsets her startling green eyes. Her features"+
	" are delicate, and although her ears are slightly pointed, it doesn't detract"+
	" from her exquisite beauty."
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
