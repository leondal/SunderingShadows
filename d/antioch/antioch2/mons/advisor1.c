#include <std.h>
#include "../antioch.h"
inherit TOWNSMAN;

void create()
{
	::create();
	set_name("Onaleron");
	set_short("Lord Onaleron, royal advisor to the king");
	set_id(({"Onaleron","onaleron","advisor","royal advisor","first advisor","lord onaleron","lord"}));
	set_long(
	"Onaleron is dressed in elegant purple robes. He is wearing soft boots"+
	" that have been dyed a matching dark purple, with a white frill on the"+
	" tops. Several fine rings adorn his fingers, he is obviously a man of"+
	" wealth. A purple fur cloak is draped around his shoulders and a belt of"+
	" gold chains loops about his slender waist. His red mustache is kept"+
	" elegantly trimmed, and his hair is kept in several long braids that"+
	" trail down his back. A purple fur cloak is draped around his shoulders"+
	" and a belt of gold chains loops about his slender waist. He looks as"+
	" though he's lost deep in thought."
	);
	set_gender("male");
	set_race("human");
	set_hd(30,4);
	set_alignment(1);
	set_class("mage");
	set_mlevel("mage",30);
	set_overall_ac(-10);
	set_max_hp(390);
	set_hp(query_max_hp());
	set_level(30);
	set_stats("intelligence",20);
	set_stats("wisdom",18);
	set_stats("strength",9);
	set_stats("consititution",12);
	set_stats("charisma",16);
	set_stats("dexterity",14);
	set_spells(({
	"meteor swarm",
	"monster summoning vii",
	"chain lightning",
	}));
	set_emotes(8,({
	"Onaleron shuffles through some papers.",
	"Onaleron sweeps his gaze across the room.",
	"Onaleron whispers something in the king's ear.",
	"Onaleron writes down a few notes.",
	}),0);
	set_spell_chance(100);
	set_exp(100);
	set("aggressive",0);
	set_property("swarm",1);
}
