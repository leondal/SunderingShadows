#include <std.h>
#include "../antioch.h"
inherit "/std/comp_vend.c";

int CALL;

void create()
{
	::create();
	CALL = 0;
	remove_std_db();
	remove_dbs(({ "alchemist" }));
	remove_random_act_dbs(({ "alchemistrandom" }));
	set_name("Helirin");
	set_short("Helirin, the local alchemist");
	set_id(({ "Helirin", "helirin", "mage", "alchemist" }));
	set_long(
		"Helirin is obviously a wizard of some power. He is wearing a discreet" +
		" brown robe and is rather scrawny. He has a hawk like face with a long" +
		" nose and gaunt features. Long, black curls tumble freely down his back" +
		" and his cold blue eyes watch your every movement. An aura of power" +
		" surrounds him, you are sure he has mastered magecraft quite well."
		);
	set_gender("male");
	set_race("human");
	set_body_type("human");
	set_hd(30, 5);
	set_alignment(1);
	set_max_hp(150 + random(30));
	set_hp(query_max_hp());
	set_overall_ac(-10);
	set_class("mage");
	set_mlevel("mage", 30);
	set_level(30);
	set_stats("intelligence", 20);
	set_stats("charisma", 10);
	set_stats("dexterity", 17);
	set_stats("wisdom", 14);
	set_stats("constitution", 12);
	set_stats("strength", 13);
	set("aggressive", 0);
	set_mob_magic_resistance("high");
	set_exp(100);
	set_spells(({
		"meteor swarm",
		"monster summoning vii",
		"chain lightning",
	}));
	set_spell_chance(100);
	set_components(100);
	force_me("speech speak in a nasally voice");
}

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
