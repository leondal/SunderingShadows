#include <std.h>
#include "../valley.h"
inherit DRUIDA;

void create()
{
	::create();
// set_property wasn't controlling them, needs to be set_unique.  *Styx* 6/2002
//	set_property("unique",1);
	set_unique(1);
	set_name("Gadrielia");
	set_id(({"druid","dragon","bear","wolf","drake","wolverine","great bear","grizzly bear","Gadrielia","gadrielia"}));
	set_short("Gadrielia, a druid of the Vale");
	set_long(
	"Gadrielia is a young druid, dedicated to restoring the balance of Moonstone Vale,"+
	" which has sorely been over-run by evil. She wears a robe of some rough looking"+
	" material, dyed a deep green. A rope belt is tied around her waist and she has a"+
	" pouch filled with herbs. Although bare handed, she is far from defenseless."+
	" She is also quite striking in her bold good looks. Auburn hair falls in ringlets"+
	" halfway down her back, almost seeming to be on fire as the light catches it."+
	" Her eyes are the depthless blue of the ocean, and her cautious smile warms"+
	" you deep inside. Her skin is a flawless creamy color, and any man would want"+
	" to take this woman into his arms. Despite the rough robe she is wearing, you"+
	" can tell she has a perfect figure beneath."
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
