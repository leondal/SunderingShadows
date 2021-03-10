#include <std.h>
#include <security.h>
#include "../antioch.h"
inherit MONSTER;

int CALL;

void create()
{
	CALL = 0;
	::create();
//   set_no_clean(1);  // I don't think we want or need this *Styx* 12/25/05
	set_name("paladin");
	set_id(({ "paladin", "guard", "paladin guard", "pguard", "Paladin", "guardian", "gate guard", "knight", "vigilant paladin" }));
	set_short("A vigilant paladin");
	set_long(
		"This paladin is a Knight of Jarmila. He has sworn to protect" +
		" the city of Antioch against all dangers, and he looks like" +
		" a formidable adversary. His armor is kept impeccably clean" +
		" and he seems to glow with his own inner light. He is dressed" +
		" in full battle gear, so as to be ready for anything. He" + " stands straight and tall, a watchful guardian."
		);
	set_race("human");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(2 - random(10));
	set_alignment(1);
	set_max_hp(random(100) + 400);
	set_hp(query_max_hp());
	set_level(40);
	set_hd(42);
	set_hp(roll_dice(query_hd(), 40));
	set_class("paladin");
	set_mlevel("paladin", 40);
	set_property("no hold", 1);
	set_property("no death", 1);
	set_property("no dominate", 1);
	set_property("no bows", 1);
	set_mob_magic_resistance("average");
	set_property("swarm", 1);
	set_property("alignment adjustment", -5);  // was -10 *Styx* 12/25/05
	set_property("add_kits", 20);
	set("aggressive", 0);

	set_monster_feats(({
		"toughness",
		"improved toughness",
		"regeneration",
		"damage resistance",
		"improved damage resistance",
		"death ward",
		"unyielding soul",
	}));


	set_detecting_invis(random(2));
	set_stats("strength", 20);
	set_stats("wisdom", 18);
	set_stats("intelligence", 12);
	set_stats("constitution", 20);
	set_stats("charisma", 18);
	set_stats("dexterity", 14);
	set_diety("jarmila");
	new("/realms/melnmarn/holy_symbol")->move(TO);
	set_exp(2000);
}

int query_watched()
{
	return 100;
}

void heart_beat()
{
	object ob, *atkrs;
	int x;
	if (!objectp(TO)) return;
	atkrs = TO->query_attackers();
	::heart_beat();
	if (atkrs != ({ }) && CALL != 1) {
		force_me("yell The Paladin Hall is under attack!!");
		CALL = 1;
	}
	if (atkrs != ({ }) && !random(100)) {
		force_me("yell Help! We're under attack!");
		return 1;
	}
}

void die(object obj)
{
	// You love me, Crystal. You know you do.
	// garrett

	object killer;
	seteuid(UID_LOG);
	if (objectp(killer = TO->query_current_attacker()))
		log_file("antioch", killer->query_name() + " killed vigilant paladin on " + ctime(time()) + ".\n");
	seteuid(getuid(previous_object()));
	return ::die(obj);
}
