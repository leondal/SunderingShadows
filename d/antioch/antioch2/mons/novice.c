#include <std.h>
#include "../antioch.h"
inherit MONSTER;

void create()
{
	::create();
	set_name("novice acolyte");
	set_short("A novice acolyte");
	set_id(({"novice","cleric","priest","acolyte","novice acolyte"}));
	set_long(
	"This is a novice acolyte of the church of Jarmila. He is dressed in robes"+
	" that mark his low rank, and will hopefully work his way up through the"+
	" church one day. His robes are white and are kept immaculately clean. He"+
	" is busy going about his duties to the church."
	);
	set_gender("male");
	set_race("human");
	set_body_type("human");
	set_hd(3,8);
	set_class("cleric");
	set_mlevel("cleric",5);
	set_spells(({"limb attack"}));
	set_spell_chance(100);
	set_exp(10);
	set_emotes(5,({
	"The acolyte lights a stick of incense.",
	"The acolyte whispers a prayer to his god.",
	"The acolyte takes a prayer book from his robes and reads through it.",
	"The acolyte straightens his robes.",
	}),0);
	command("speech say with conviction");
}
