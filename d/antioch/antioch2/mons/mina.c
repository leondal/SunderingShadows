#include <std.h>
#include <daemons.h>
#include "../antioch.h"
inherit INTERACTIVE;

void create()
{
	::create();
	remove_std_db();
	remove_dbs(({ "tailor" }));
	remove_random_act_dbs(({ "tailorrandom" }));
	set_name("Mina");
	set_id(({ "Mina", "mina", "tailor", "seamstress" }));
	set_short("Mina, the tailor");
	set_long(
		"Mina is a cute little redhead. She is tall, close to six feet in height." +
		" She is very slender, and has many freckles. She is wearing a lovely" +
		" dress that she obviously made herself. A measuring cloth is around her" +
		" shoulders, and a push pin full of pins is in one of her hands. She" +
		" seems full of energy and eager to get to work. Mina has also been" +
		" known to alter clothing for a small price, if you give her an item" +
		" she might %^BOLD%^%^WHITE%^tailor%^RESET%^%^CYAN%^ it to fit you."
		);
	set_gender("female");
	set_race("human");
	set_body_type("human");
	set_hd(20, 3);
	set_max_hp(random(20) + 100);
	set_hp(query_max_hp());
	set_alignment(1);
	set_class("mage");
	set_mlevel("mage", 20);
	set_overall_ac(-3);
	set_level(20);
	set_stats("dexterity", 18);
	set_stats("intelligence", 18);
	set_stats("wisdom", 12);
	set_stats("strength", 13);
	set_stats("constitution", 10);
	set_stats("charisma", 15);
	set_mob_magic_resistance("high");
	set_exp(100);
	set_nwp("tailoring", 20);
	set_spells(({
		"hideous laughter",
		"magic missile",
		"acid arrow",
		"chain lightning",
		"phantom guardians",
		"fireball",
		"monster summoning vii",
		"web",
		"meteor swarm",
		"hold person",
	}));
	set_spell_chance(100);
	set_storage_room(ROOMDIR + "tailor.c");
	set_items_allowed("clothing");
	set("aggressive", 0);
	add_money("silver", random(20));
	force_me("speech say cheerfully");
}

void catch_say(string message)
{
	object ob;

	if ((mixed *)TO->query_attackers() != ({ })) {
		force_me("say I'm being attacked, please help!");
		return 1;
	}
	if (strsrch(message, "fit") != -1 || strsrch(message, "size") != -1 || (strsrch(message, "tailor") != -1 && strsrch(message, "tailoring") == -1) || strsrch(message, "alter") != -1) {
		if (!objectp(TP->query_property("shapeshifted"))) {
			if ((string)TP->query_race() == "drow" || (string)TP->query_race() == "ogre" || (string)TP->query_race() == "half-ogre" || (string)TP->query_race() == "goblin" || (string)TP->query_race() == "orc" || (string)TP->query_race() == "half-orc" || (string)TP->query_race() == "hobgoblin" || (string)TP->query_race() == "ogre-mage" || (string)TP->query_race() == "gnoll" || (string)TP->query_race() == "half-drow" || (string)TP->query_race() == "kobold" || (string)TP->query_race() == "bugbear") {
				force_me("say I'm not fond of " + TP->query_race() + ", I don't" +
					 " know how you got into town, but please leave.");
				return 1;
			}
		}
		if (member_array(TP->query_name(), KILLING_D->query_bounties()) != -1) {
			force_me("say We do not serve law breakers in this city, begone" +
				 " before I summon the guards!");
			return 1;
		}
		if (member_array(TP->query_name(), KILLING_D->query_evil_bounties()) != -1) {
			force_me("say Evil scum! Get out of my shop before I summon the guards!");
			return 1;
		}
		if (TP->query_invis()) {
			force_me("say Well I need to see you if you want me to get the" +
				 " measurements right.");
			return 1;
		}
		if (TP->is_class("antipaladin")) {
			force_me("say Sorry, I don't serve antipaladins.");
			return 1;
		}else  {
			force_me("say You can give me items that you wish to have" +
				 " refitted to your size. I charge 3 gold for alterations to" +
				 " make the item smaller, and 5 gold to enlarge the item.");
			force_me("smile");
			return 1;
		}
	} else
		::catch_say(message);
}

void receive_given_item(object ob)
{
	if (!objectp(ob)) return;
	if ((string)TP->query_race() == "drow" || (string)TP->query_race() == "ogre" || (string)TP->query_race() == "half-ogre" || (string)TP->query_race() == "goblin" || (string)TP->query_race() == "orc" || (string)TP->query_race() == "half-orc" || (string)TP->query_race() == "hobgoblin" || (string)TP->query_race() == "ogre-mage" || (string)TP->query_race() == "gnoll" || (string)TP->query_race() == "half-drow" || (string)TP->query_race() == "kobold" || (string)TP->query_race() == "bugbear") {
		force_me("say I'm not fond of " + TP->query_race() + ", I don't know" +
			 " how you got into town, but please leave.");
		force_me("give " + ob->query_name() + " to " + TPQN + "");
		return 1;
	}
	if (member_array(TP->query_name(), KILLING_D->query_bounties()) != -1) {
		force_me("say We do not serve law breakers in this city, begone before" +
			 " I summon the guards!");
		force_me("give " + ob->query_name() + " to " + TPQN + "");
		return 1;
	}
	if (member_array(TP->query_name(), KILLING_D->query_evil_bounties()) != -1) {
		force_me("say Evil scum! Get out of my shop before I summon the guards!");
		force_me("give " + ob->query_name() + " to " + TPQN + "");
		return 1;
	}
	if (TP->is_class("antipaladin")) {
		force_me("say Sorry, I don't serve antipaladins.");
		force_me("give " + ob->query_name() + " to " + TPQN + "");
		return 1;
	}
	if (TP->query_invis()) {
		force_me("say Well I need to see you if you want me to get the" +
			 " measurements right.");
		force_me("give " + ob->query_name() + " to " + TPQN + "");
		return 1;
	}
	if ((string)ob->query_type() != "clothing") {
		force_me("say I'm a tailor, I only work with clothing, and I" +
			 " only alter my own work.");
		force_me("give " + ob->query_name() + " to " + TPQN + "");
		return 1;
	}
	if (ob->id("azure robe")) {
		force_me("say I'm sorry, even though I created the robe there's" +
			 " no way for me to make it protect someone of your size. You'll" +
			 " have to find something else.");
		force_me("give " + ob->query_name() + " to " + TPQN + "");
		return 1;
	}
	if (!ob->id("mina_clothing")) {
		force_me("say Sorry, I only alter my own work.");
		force_me("give " + ob->query_name() + " to " + TPQN + "");
		return 1;
	}
	if ((int)TP->query_size() == 1) {
		if ((int)ob->query_size() == 1) {
			force_me("say Clearly this will already fit you, I don't know" +
				 " what you need my services for.");
			force_me("give " + ob->query_name() + " to " + TPQN + "");
			return 1;
		}
		if ((int)ob->query_size() != 2) {
			force_me("say If you alter garments too many times they're no" +
				 " good. I'm sure you'll find something else you'll like in my" +
				 " shop, I'm always making different things.");
			force_me("give " + ob->query_name() + " to " + TPQN + "");
			return 1;
		}
		if (!TP->query_funds("gold", 3)) {
			force_me("say The cost to alter this is 3 gold, the Antioch" +
				 " bank is just south of the fountain.");
			force_me("give " + ob->query_name() + " to " + TPQN + "");
			return 1;
		}else  {
			TP->use_funds("gold", 3);
			force_me("emote alters the " + ob->query_name() + " to fit" +
				 " " + TPQCN + ".");
			ob->set_size(1);
			force_me("say There you go!");
			force_me("smile " + TPQN + "");
			force_me("give " + ob->query_name() + " to " + TPQN + "");
			return 1;
		}
	}
	if ((int)TP->query_size() == 3) {
		if ((int)ob->query_size() == 3) {
			force_me("say Clearly this will already fit you, I don't know" +
				 " what you need my services for.");
			force_me("give " + ob->query_name() + " to " + TPQN + "");
			return 1;
		}
		if ((int)ob->query_size() != 2) {
			force_me("say If you alter garments too many times they're no" +
				 " good. I'm sure you'll find something else you'll like in my" +
				 " shop, I'm always making different things.");
			force_me("give " + ob->query_name() + " to " + TPQN + "");
			return 1;
		}
		if (!TP->query_funds("gold", 5)) {
			force_me("say The cost to alter this is 5 gold, the Antioch" +
				 " bank is just south of the fountain.");
			force_me("give " + ob->query_name() + " to " + TPQN + "");
			return 1;
		}else  {
			TP->use_funds("gold", 5);
			force_me("emote alters the " + ob->query_name() + " to fit" +
				 " " + TPQCN + ".");
			ob->set_size(3);
			force_me("say There you go!");
			force_me("smile " + TPQN + "");
			force_me("give " + ob->query_name() + " to " + TPQN + "");
			return 1;
		}
	}
	if ((int)TP->query_size() == 2) {
		if ((int)ob->query_size() == 2) {
			force_me("say Clearly this will already fit you, I don't know" +
				 " what you need my services for.");
			force_me("give " + ob->query_name() + " to " + TPQN + "");
			return 1;
		}
		force_me("say If you alter garments too many times they're no" +
			 " good. I'm sure you'll find something else you'll like in my" +
			 " shop, I'm always making different things.");
		force_me("give " + ob->query_name() + " to " + TPQN + "");
		return 1;
	}
}
