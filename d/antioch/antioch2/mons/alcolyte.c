#include <std.h>
#include "../antioch.h"
inherit MONSTER;

void create() {
	::create();
	set_name("advanced acolyte");
	set_short("An advanced acolyte");
	set_id(({"advanced acolyte","priest","cleric","acolyte"}));
	set_long(
	"This man has earned the robes of an advanced acolyte of the church of"+
	" Jarmila, which he wears quite proudly. He is perhaps in his mid-twenties"+
	" and looks very content with his life and at peace with the world. His"+
	" robes are spotless, and he keeps himself well groomed. He seems like"+
	" a pleasant man, someone you just know you could trust."
	);
	set_gender("male");
	set_race("human");
	set_body_type("human");
	set_hd(15,20);
	set_class("cleric");
	set_mlevel("cleric",15);
	set_exp(20);
	set_spells(({
	"limb attack",
	"flame strike",
	"animate object",
	"cause critical wounds",
	}));
	set_spell_chance(100);
	set_emotes(5,({
	"The advanced acolyte seems lost in deep meditation.",
	"The advanced acolyte murmurs a prayer to Jarmila.",
	"The advanced acolyte straightens up the room.",
	}),0);
	command("speech speak with deep conviction");
}
