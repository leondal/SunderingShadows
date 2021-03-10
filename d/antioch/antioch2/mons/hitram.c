#include <std.h>
#include "../antioch.h"
inherit TOWNSMAN;

int talking;
void night_emotes();
void day_emotes();

void create()
{
	::create();
	set_name("Hitram");
	set_short("Hitram, owner of the White Dragon Inn");
	set_id(({ "hitram", "Hitram", "owner", "inn owner" }));
	set_long(
		"Hitram is the kindly owner of the White Dragon Inn. He is dressed in a" +
		" fine outfit, green velvet tunic with a black leather belt and black" +
		" cotton pants. Low cut soft leather boots cover his feet, and add a" +
		" little bit to his height. He is slightly on the short side, only about" +
		" five foot two inches tall. He is well built, though getting a little up there in age." +
		" He is in his late forties, but already has white streaks running through" +
		" his long black hair. His eyes are a steel gray, and his face is" +
		" chisled and rather attractive. He seems stern, but caring and friendly."
		);
	set_gender("male");
	set_race("human");
	set_alignment(4);
	set_hd(30, 10);
	set_overall_ac(-12);
	set_max_hp(270 + random(50));
	set_hp(query_max_hp());
	set_class("fighter");
	set_class("mage");
	set_mlevel("mage", 30);
	set_mlevel("fighter", 30);
	set("aggressive", 0);
	set_stats("intelligence", 20);
	set_stats("strength", 18);
	set_stats("charisma", 16);
	set_stats("wisdom", 13);
	set_stats("dexterity", 10);
	set_stats("constitution", 15);
	set_mob_magic_resistance("high");
	set_exp(100);
	set_spells(({
		"meteor swarm",
		"monster summoning vii",
		"chain lightning",
	}));
	set_spell_chance(90);
	command("speech say in a conversational tone");
}

void heart_beat()
{
	::heart_beat();
	if (!objectp(TO)) return;
	if (sizeof(query_attackers())) return;

	if (talking) return;
	if (query_night() == 1) {
		if (!random(200)) {
			night_emotes();
			return;
		}
	}else  {
		if (!random(200)) {
			day_emotes();
			return;
		}
	}
}

void night_emotes()
{
	talking = 1;
	switch (random(5)) {
	case 0:
		force_me("emote nods pleasantly to you.");
		break;
	case 1:
		force_me("say It's getting late, bout time to turn in.");
		break;
	case 2:
		force_me("emote snores softly.");
		break;
	case 3:
		force_me("emote yawns and leans back in his chair.");
		break;
	case 4:
		force_me("rubs his sleepy eyes.");
		break;
	}
	talking = 0;
}

void day_emotes()
{
	talking = 1;
	switch (random(7)) {
	case 0:
		force_me("say Thiliwan makes the most delicious apple pie, you" +
			 " should ask Kedaria to get you a piece.");
		break;
	case 1:
		force_me("say The mint tea is brewed from fresh mint leaves, it" +
			 " has that sweet minty tang.");
		break;
	case 2:
		force_me("say Lovely day, isn't it?");
		break;
	case 3:
		force_me("say Welcome to the White Dragon Inn.");
		break;
	case 4:
		force_me("say I hope you're having a pleasant stay here in the" +
			 " city of Antioch.");
		break;
	case 5:
		force_me("say Make sure to stop by all the shops, they've got some" +
			 " great things around here.");
		break;
	case 6:
		force_me("say Better not plan any trips to the ruins, that place" +
			 " is still haunted.");
		force_me("emote shivers.");
		break;
	}
	talking = 0;
}
