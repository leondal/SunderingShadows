#include <std.h>
#include "/d/antioch/antioch2/antioch.h"
inherit VENDOR;

int summon_guards;
int should_interact;
int CALL;

void create()
{
	::create();
	remove_std_db();
	remove_dbs(({ "miscvendors", "armors" }));
	remove_random_act_dbs(({ "armorsrandom" }));
	set_name("Liennor");
	set_short("Liennor, retired paladin shop keeper");
	set_id(({ "liennor", "paladin", "retired paladin", "shop keeper" }));
	set_long(
		"Liennor looks like he has seen quite a few things in his many years." +
		" He is approximately sixty years old and has gray hair and a neatly" +
		" trimmed gray beard. His eyes are a deep blue color, and his hands" +
		" show many callouses and a few scars. He stands perfectly straight and" +
		" is dressed in full armor, although you see no sword in hand. He is still" +
		" in fairly good shape, and he proudly wears the symbol of Helm on the" +
		" front of his plate. He may be retired, but he still obviously takes" +
		" his duties seriously."
		);
	set_gender("male");
	set_race("human");
	set_body_type("human");
	set_alignment(1);
	set_hd(30, 10);
	set_max_hp(350);
	set_hp(query_max_hp());
	set_overall_ac(-17);
	set_class("paladin");
	set_mlevel("paladin", 30);
	set_mob_magic_resistance("average");
	set("aggressive", 0);
	force_me("speech speak in a deep voice");
	set_property("full attacks", 1);
	set_storage_room("/d/antioch/cguilds/paladin/storage");
	set_property("alignment adjustment", -50);
	CALL = 0;
}

int should_interact(object ob)
{
	if (!TP->is_class("paladin")) {
		force_me("say I only serve paladins, but how did you get past the guards? You're not supposed to be here!");
		force_me("yell GUARDS!");
		force_me("kill " + TPQN);
		call_out("summon_guards", 5);
		CALL = 1;
		return 0;
	}
	return 1;
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
	tell_room(ETO, "%^BOLD%^Several paladins burst into the room.");
	new(MONS + "paladin")->move(ETO);
	if (sizeof(TO->query_attackers()) > 1) {
		new(MONS + "paladin")->move(ETO);
	}
	if (sizeof(TO->query_attackers()) > 2) {
		new(MONS + "paladin")->move(ETO);
	}
	if (sizeof(TO->query_attackers()) > 3) {
		new(MONS + "paladin")->move(ETO);
	}
	if (sizeof(TO->query_attackers()) > 4) {
		new(MONS + "paladin")->move(ETO);
	}
	if (sizeof(TO->query_attackers()) > 5) {
		new(MONS + "paladin")->move(ETO);
	}
	return 1;
}
