#include <std.h>
#include "../antioch.h"
inherit NPC;

int CALL;

void create()
{
	::create();
	CALL = 0;
	set_name("Jelip");
	set_short("Jelip, the local healer");
	set_id(({ "healer", "jelip", "Jelip" }));
	set_nwp("healing", 10, 500);
	set_long(
		"Jelip is an elderly healer, it has been his life long practice. He has" +
		" a warm smile and a kind heart, always ready to help those in need. He" +
		" is wearing a green shirt and brown trousers with high cut boots. Even" +
		" though he must be getting up there in age, he still has a healthy glow" +
		" about him. Being an herbalist he probably knows what to take to help" +
		" keep him healthy. Brown hair falls down to his shoulders, and his brown" +
		" eyes seem filled with infinite wisdom and kindness."
		);
	set_race("human");
	set_body_type("human");
	set_gender("male");
	set_hd(30, 5);
	set_alignment(1);
//	set_diety("helm");
	set_max_hp(200 + random(75));
	set_hp(query_max_hp());
	set_class("cleric");
	set_mlevel("cleric", 25);
	set_level(30);
	set_overall_ac(-15);
	set_stats("wisdom", 20);
	set_stats("charisma", 15);
	set_stats("strength", 15);
	set_stats("constitution", 18);
	set_stats("dexterity", 17);
	set_stats("intelligence", 18);
	set("aggressive", 0);
	set_mob_magic_resistance("high");
	set_exp(100);
//	new("/d/magic/symbols/helm_symbol.c")->move(TO);
	set_spells(({
		"limb attack",
		"flame strike",
		"mystic bolt",
		"cause critical wounds",
	}));
	set_spell_chance(100);
	force_me("speech say in a kind voice");
}

//chat, call guards, preach about good health

void heart_beat()
{
	object ob, *atkrs;
	int x, CALL;
	if (!objectp(TO)) return;
	atkrs = TO->query_attackers();
	::heart_beat();
	if (atkrs != ({ }) && CALL != 1) {
		call_out("summon_guards", 5);
		force_me("yell Help, I'm being attacked! Someone call the guards!");
		CALL = 1;
	}
}

int summon_guards()
{
	object ob;
	tell_room(ETO, "%^BOLD%^Several guards burst into the room.");
	new(MONS + "guard")->move(ETO);
	if (sizeof(TO->query_attackers()) > 1) {
		new(MONS + "guard")->move(ETO);
	}
	if (sizeof(TO->query_attackers()) > 2) {
		new(MONS + "guard")->move(ETO);
	}
	if (sizeof(TO->query_attackers()) > 3) {
		new(MONS + "guard")->move(ETO);
	}
	if (sizeof(TO->query_attackers()) > 4) {
		new(MONS + "guard")->move(ETO);
	}
	if (sizeof(TO->query_attackers()) > 5) {
		new(MONS + "guard")->move(ETO);
	}
	return 1;
}
